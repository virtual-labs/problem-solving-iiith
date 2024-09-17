/*
 *	Bulgarian translation
 *	Author:		Valentin Hristov
 *	Company:	SOFTKIT Bulgarian
 *	Site:		http://www.softkit-bg.com
 */
function editArea(){
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

editArea.add_lang("bg",{
test_select: "избери таг",
test_but: "тествай копието"
});
