/*
 *	Bulgarian translation
 *	Author:		Valentin Hristov
 *	Company:	SOFTKIT Bulgarian
 *	Site:		http://www.softkit-bg.com
 */

function editAreaLoader(){
	var t=this;
	t.version= "0.8.2";
	date= new Date();
	t.start_time=date.getTime();
	t.win= "loading";	// window loading state
	t.error= false;	// to know if load is interrrupt
	t.baseURL="";
	//t.suffix="";
	t.template="";
	t.lang= {};	// array of loaded speech language
	t.load_syntax= {};	// array of loaded syntax language for highlight mode
	t.syntax= {};	// array of initilized syntax language for highlight mode
	t.loadedFiles= [];
	t.waiting_loading= {}; 	// files that must be loaded in order to allow the script to really start
	// scripts that must be loaded in the iframe
	t.scripts_to_load= ["elements_functions", "resize_area", "reg_syntax"];
	t.sub_scripts_to_load= ["edit_area", "manage_area" ,"edit_area_functions", "keyboard", "search_replace", "highlight", "regexp"];
	t.syntax_display_name= { /*syntax_display_name_AUTO-FILL-BY-COMPRESSOR*/ };
	
	t.resize= []; // contain resizing datas
	t.hidden= {};	// store datas of the hidden textareas
	
	t.default_settings= {
		//id: "src"	// id of the textarea to transform
		debug: false
		,smooth_selection: true
		,font_size: "10"		// not for IE
		,font_family: "monospace"	// can be "verdana,monospace". Allow non monospace font but Firefox get smaller tabulation with non monospace fonts. IE doesn't change the tabulation width and Opera doesn't take this option into account... 
		,start_highlight: false	// if start with highlight
		,toolbar: "search, go_to_line, fullscreen, |, undo, redo, |, select_font,|, change_smooth_selection, highlight, reset_highlight, word_wrap, |, help"
		,begin_toolbar: ""		//  "new_document, save, load, |"
		,end_toolbar: ""		// or end_toolbar
		,is_multi_files: false		// enable the multi file mode (the textarea content is ignored)
		,allow_resize: "both"	// possible values: "no", "both", "x", "y"
		,show_line_colors: false	// if the highlight is disabled for the line currently beeing edited (if enabled => heavy CPU use)
		,min_width: 400
		,min_height: 125
		,replace_tab_by_spaces: false
		,allow_toggle: true		// true or false
		,language: "en"
		,syntax: ""
		,syntax_selection_allow: "basic,brainfuck,c,coldfusion,cpp,css,html,java,js,pas,perl,php,python,ruby,robotstxt,sql,tsql,vb,xml"
		,display: "onload" 		// onload or later
		,max_undo: 30
		,browsers: "known"	// all or known
		,plugins: "" // comma separated plugin list
		,gecko_spellcheck: false	// enable/disable by default the gecko_spellcheck
		,fullscreen: false
		,is_editable: true
		,cursor_position: "begin"
		,word_wrap: false		// define if the text is wrapped of not in the textarea
		,autocompletion: false	// NOT IMPLEMENTED			
		,load_callback: ""		// click on load button (function name)
		,save_callback: ""		// click on save button (function name)
		,change_callback: ""	// textarea onchange trigger (function name)
		,submit_callback: ""	// form submited (function name)
		,EA_init_callback: ""	// EditArea initiliazed (function name)
		,EA_delete_callback: ""	// EditArea deleted (function name)
		,EA_load_callback: ""	// EditArea fully loaded and displayed (function name)
		,EA_unload_callback: ""	// EditArea delete while being displayed (function name)
		,EA_toggle_on_callback: ""	// EditArea toggled on (function name)
		,EA_toggle_off_callback: ""	// EditArea toggled off (function name)
		,EA_file_switch_on_callback: ""	// a new tab is selected (called for the newly selected file)
		,EA_file_switch_off_callback: ""	// a new tab is selected (called for the previously selected file)
		,EA_file_close_callback: ""		// close a tab
	};



editAreaLoader.lang["bg"]={
new_document: "нов документ",
search_button: "търсене и замяна",
search_command: "търси следващия / отвори прозорец с търсачка",
search: "търсене",
replace: "замяна",
replace_command: "замяна / отвори прозорец с търсачка",
find_next: "намери следващия",
replace_all: "замени всички",
reg_exp: "реголярни изрази",
match_case: "чуствителен към регистъра",
not_found: "няма резултат.",
occurrence_replaced: "замяната е осъществена.",
search_field_empty: "Полето за търсене е празно",
restart_search_at_begin: "До края на документа. Почни с началото.",
move_popup: "премести прозореца с търсачката",
font_size: "--Размер на шрифта--",
go_to_line: "премени към реда",
go_to_line_prompt: "премени към номера на реда:",
undo: "отмени",
redo: "върни",
change_smooth_selection: "включи/изключи някой от функциите за преглед (по красиво, но повече натоварва)",
highlight: "превключване на оцветяване на синтаксиса включена/изключена",
reset_highlight: "въстанови оцветяване на синтаксиса (ако не е синхронизиран с текста)",
word_wrap: "режим на пренасяне на дълги редове",
help: "за програмата",
save: "съхрани",
load: "зареди",
line_abbr: "Стр",
char_abbr: "Стлб",
position: "Позиция",
total: "Всичко",
close_popup: "затвори прозореца",
shortcuts: "Бързи клавиши",
add_tab: "добави табулация в текста",
remove_tab: "премахни табулацията в текста",
about_notice: "Внимание: използвайте функцията оцветяване на синтаксиса само за малки текстове",
toggle: "Превключи редактор",
accesskey: "Бърз клавиш",
tab: "Tab",
shift: "Shift",
ctrl: "Ctrl",
esc: "Esc",
processing: "Зареждане...",
fullscreen: "на цял екран",
syntax_selection: "--Синтаксис--",
close_tab: "Затвори файла"
};
