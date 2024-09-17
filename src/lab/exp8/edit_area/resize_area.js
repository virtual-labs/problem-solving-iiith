	
	function EditArea(){
		var t=this;
		t.error= false;	// to know if load is interrrupt
		
		t.inlinePopup= [{popup_id: "area_search_replace", icon_id: "search"},
									{popup_id: "edit_area_help", icon_id: "help"}];
		t.plugins= {};
	
		t.line_number=0;
		
		parent.editAreaLoader.set_browser_infos(t); 	// navigator identification
		// fix IE8 detection as we run in IE7 emulate mode through X-UA <meta> tag
		if( t.isIE >= 8 )
			t.isIE	= 7;
		
		t.last_selection={};		
		t.last_text_to_highlight="";
		t.last_hightlighted_text= "";
		t.syntax_list= [];
		t.allready_used_syntax= {};
		t.check_line_selection_timer= 50;	// the timer delay for modification and/or selection change detection
		
		t.textareaFocused= false;
		t.highlight_selection_line= null;
		t.previous= [];
		t.next= [];
		t.last_undo="";
		t.files= {};
		t.filesIdAssoc= {};
		t.curr_file= '';
		//t.loaded= false;
		t.assocBracket={};
		t.revertAssocBracket= {};		
		// bracket selection init 
		t.assocBracket["("]=")";
		t.assocBracket["{"]="}";
		t.assocBracket["["]="]";		
		for(var index in t.assocBracket){
			t.revertAssocBracket[t.assocBracket[index]]=index;
		}
		t.is_editable= true;
		
		
		/*t.textarea="";	
		
		t.state="declare";
		t.code = []; // store highlight syntax for languagues*/
		// font datas
		t.lineHeight= 16;
		/*t.default_font_family= "monospace";
		t.default_font_size= 10;*/
		t.tab_nb_char= 8;	//nb of white spaces corresponding to a tabulation
		if(t.isOpera)
			t.tab_nb_char= 6;

		t.is_tabbing= false;
		
		t.fullscreen= {'isFull': false};
		
		t.isResizing=false;	// resize var
		
		// init with settings and ID (area_id is a global var defined by editAreaLoader on iframe creation
		t.id= area_id;
		t.settings= editAreas[t.id]["settings"];
		
		if((""+t.settings['replace_tab_by_spaces']).match(/^[0-9]+$/))
		{
			t.tab_nb_char= t.settings['replace_tab_by_spaces'];
			t.tabulation="";
			for(var i=0; i<t.tab_nb_char; i++)
				t.tabulation+=" ";
		}else{
			t.tabulation="\t";
		}
			
		// retrieve the init parameter for syntax
		if(t.settings["syntax_selection_allow"] && t.settings["syntax_selection_allow"].length>0)
			t.syntax_list= t.settings["syntax_selection_allow"].replace(/ /g,"").split(",");
		
		if(t.settings['syntax'])
			t.allready_used_syntax[t.settings['syntax']]=true;
		
		
	};	



EditAreaLoader.prototype.start_resize_area= function(){
		var d=document,a,div,width,height,father;
		
		d.onmouseup= editAreaLoader.end_resize_area;
		d.onmousemove= editAreaLoader.resize_area;
		editAreaLoader.toggle(editAreaLoader.resize["id"]);		
		
		a	= editAreas[editAreaLoader.resize["id"]]["textarea"];
		div	= d.getElementById("edit_area_resize");
		if(!div){
			div= d.createElement("div");
			div.id="edit_area_resize";
			div.style.border="dashed #888888 1px";
		}
		width	= a.offsetWidth -2;
		height	= a.offsetHeight -2;
		
		div.style.display	= "block";
		div.style.width		= width+"px";
		div.style.height	= height+"px";
		father= a.parentNode;
		father.insertBefore(div, a);
		
		a.style.display="none";
				
		editAreaLoader.resize["start_top"]= calculeOffsetTop(div);
		editAreaLoader.resize["start_left"]= calculeOffsetLeft(div);		
	};
	
	EditAreaLoader.prototype.end_resize_area= function(e){
		var d=document,div,a,width,height;
		
		d.onmouseup="";
		d.onmousemove="";		
		
		div		= d.getElementById("edit_area_resize");		
		a= editAreas[editAreaLoader.resize["id"]]["textarea"];
		width	= Math.max(editAreas[editAreaLoader.resize["id"]]["settings"]["min_width"], div.offsetWidth-4);
		height	= Math.max(editAreas[editAreaLoader.resize["id"]]["settings"]["min_height"], div.offsetHeight-4);
		if(editAreaLoader.isIE==6){
			width-=2;
			height-=2;	
		}
		a.style.width		= width+"px";
		a.style.height		= height+"px";
		div.style.display	= "none";
		a.style.display		= "inline";
		a.selectionStart	= editAreaLoader.resize["selectionStart"];
		a.selectionEnd		= editAreaLoader.resize["selectionEnd"];
		editAreaLoader.toggle(editAreaLoader.resize["id"]);
		
		return false;
	};
	
	EditAreaLoader.prototype.resize_area= function(e){		
		var allow,newHeight,newWidth;
		allow	= editAreas[editAreaLoader.resize["id"]]["settings"]["allow_resize"];
		if(allow=="both" || allow=="y")
		{
			newHeight	= Math.max(20, getMouseY(e)- editAreaLoader.resize["start_top"]);
			document.getElementById("edit_area_resize").style.height= newHeight+"px";
		}
		if(allow=="both" || allow=="x")
		{
			newWidth= Math.max(20, getMouseX(e)- editAreaLoader.resize["start_left"]);
			document.getElementById("edit_area_resize").style.width= newWidth+"px";
		}
		
		return false;
	};
	
	editAreaLoader.waiting_loading["resize_area.js"]= "loaded";
