 
<?php

include('simple_html_dom.php');

$html = file_get_html('./content.html');
       
		//$section = $_GET['section'];
		//if(!isset($section))
			//{$section="Introduction";}
			
			if(!isset($_GET["section"])) $section = "Introduction"; 
			else $section = $_GET["section"];
        // Find all images
        $labheaderheading =$html->getElementById("lab-header-heading")->innertext;
        $labarticleheading =$html->getElementById("lab-article-heading")->innertext;
       // echo $html->getElementById("experiment-article-section-1-content")->plaintext; 
        // foreach($html->find('div[id=experiment-article-section-1-content]') as $element)
               // echo $element->plaintext . '<br>';
//  
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
$css_js   = "./"; 
$lab_url  = "./index.php";
$exp_url  =  "./exp/index.php";
$base_url = $lab_url;

//$vlab_url = "http://virtual-labs.ac.in/"; 
//$css_js   = "http://deploy.virtual-labs.ac.in/labs/cse04/"; 
//$lab_url  = "http://deploy.virtual-labs.ac.in/labs/cse04/index.php";
//$exp_url  =  "http://deploy.virtual-labs.ac.in/labs/cse04/exp/index.php";
//$base_url = $lab_url;

include('./exp_template.php');

//include('./number_system.php');

?>



