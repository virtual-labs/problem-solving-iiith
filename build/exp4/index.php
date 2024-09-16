  
<?php

include('../simple_html_dom.php');

$html = file_get_html('./content.html');
	
if(!isset($_GET["section"])) $section = "Introduction"; 
else $section = $_GET["section"];
// Find all images

$labheaderheading =$html->getElementById("experiment-header-heading")->innertext;
$labarticleheading =$html->getElementById("experiment-article-heading")->innertext;
		
 foreach($html->find('section') as $element) {
	 $nav[] = array('heading' => $html->getElementById($element->id."-heading")->innertext,'img'=> $html->getElementById($element->id."-icon")->innertext);

//echo $html->getElementById($element->id."-icon")->innertext->find('section');
 // echo $html->getElementById($element->id."-heading")->plaintext."-";
// echo $section."=";
// echo strcasecmp(trim($section),trim($html->getElementById($element->id."-heading")->plaintext)).",";
	  if(strcasecmp(trim($section),trim($html->getElementById($element->id."-heading")->plaintext))==0)
	 {
	   //    $nav[] = array('heading' => $html->getElementById($element->id."-heading")->innertext,'img'=> $html->getElementById($element->id."-icon")->innertext);
	   $data['SubHeading'] =$html->getElementById($element->id."-heading")->innertext;
	   $data['SubContent'] =$html->getElementById($element->id."-content")->innertext;
		  // echo "<b>Section: </b>".$element->id . '<br><hr>';
	   // echo "<b>Icon: </b>".$html->getElementById($element->id."-icon")->innertext."<br>";
	   // echo "<b>Heading:</b> ".$html->getElementById($element->id."-heading")->innertext."<br>";
	   // echo "<b>Content: </b>".$html->getElementById($element->id."-content")->innertext."<br><br><br>";
	 } 
	   
	
}
$data['nav'] = $nav;
//print_r($nav);

$vlab_url = "http://virtual-labs.ac.in/"; 
$css_js   = "../"; 
$lab_url  = "../index.php";
$exp_url  =  "./index.php";
$base_url = $exp_url;


//$vlab_url = "http://virtual-labs.ac.in/"; 
//$css_js   = "http://deploy.virtual-labs.ac.in/labs/cse04/"; 
//$lab_url  = "http://deploy.virtual-labs.ac.in/labs/cse04/index.php";
//$exp_url  =  "http://deploy.virtual-labs.ac.in/labs/cse04/exp4/index.php";
//$base_url = $exp_url;

include('../exp_template.php');

?>



