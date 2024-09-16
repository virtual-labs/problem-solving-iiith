<!DOCTYPE html>
<html lang="en" class="no-js">

<head>
  
  <!--It is a good practice to declare the encoding even for an 
  English Web site. One function of this is to tag is to "reset"
  the user's browser back to Latin-1 and ensure proper font 
  settings. The Unicode "utf-8" encoding also ensures that any 
  special characters inserted such as "Smart quotes", currency 
  symbols, em-dashes and so forth will be properly displayed in
  most browsers.-->
  <meta http-equiv="Content-Type" content="text/html;  charset=utf-8" >


  <!-- The following meta element gives the appearance of using 
  Internet Explorer (IE) but actually renders the page in google 
  chrome thus rescuing the older IE versions and providing the 
  speed and standards compliance, and security of Chrome 
  http://tech18.com/google-chrome-frame-rescue-older-ie.html -->
  <meta http-equiv="X-UA-Compatible"  content="IE=edge,chrome=1"/>


  <!-- The default title of the lab. -->
  <title class="custom" id="page-title">Virtual Labs</title>
  

  <!-- Following meta tags store the information about the 
  author and any other relevant information about the  code -->
  <meta name="author" content="" class="custom">
  <meta name="description" content="" class="custom">


  <!-- Place the relative address of the favicon 
  ("images/logo.jpeg" here). All major browsers support the link
  rel="shortcut icon"  tag to associate a small icon with the 
  page -->
  <link rel="shortcut icon" href="http://deploy.virtual-labs.ac.in/labs/cse09//images/favicon.png"   class="custom">


  <!-- These are the stylesheets used for the lab. Please don't
  edit them; If you do, you will lose the edits in subsequent 
  releases of this User Interface. -->
  <link rel="stylesheet" href="<?php echo $css_js;?>css/default.css"/>
  <link rel="stylesheet" href="<?php echo $css_js;?>css/style.css"/>

  <!-- Instead add your custom styles to override the defaults 
  coming from the above style sheets. -->
  
  <link rel="stylesheet" href="<?php echo $css_js;?>css/override.css"/>

  <!-- ***************************************************** -->

  <!-- All JavaScript at the bottom, except for Modernizr which
  enables HTML5 elements & feature detects -->

</head>

<body> 
  <div id="container">
  	
  	 <!-- The Experiment Document Container-->

<!-- The lab Header contains the logo and the name of the lab,
	usually displayed on the top of the page-->

	<header id="experiment-header">

	<div id="experiment-header-logo" class="logo">
	<!-- Enclose the logo image of your lab or write it in 
	text-->
	<a href="<?php echo $vlab_url?>"><div class="imagemap">
		<img src="http://virtual-labs.ac.in/images/virtualLabsLogo.jpg" alt="" usemap="#logos" />

	
		<map name="logos">
			
			<area shape="rect" coords="0,0,505,98" href="http://www.vlab.co.in/" title="Vlab" alt="Vlab" />
			<area shape="rect" coords="734,0,1022,97" href="http://www.iiit.ac.in/" title="IIIT" alt="IIIT" />
			
			<area shape="default" nohref="nohref" title="Default" alt="Default"/>
		</map>
		</div>
      
     </a>
	</div>

	<div id="experiment-header-heading" class="heading">
	<!-- Write the name of your lab and link it to the home 
	page of your lab (h1 tag is preferred while writing your 
			lab name)-->
	<a href="<?php echo $lab_url?>"> <?php echo $labheaderheading?></a>	
	</div>

	<!-- Add any additional element you want to add to the lab 
	header, For example : Help (Enclosing them with suitable 
			div is recommended)-->

	</header>


	<!-- The lab article is the main content area where all the 
	experiment content sits-->
	<article id="experiment-article">

	<div class="breadcrumb" id="experiment-article-breadcrumb"><a href="<?php echo $vlab_url?>">Home</a><a></a> &gt; <a href="<?php echo $lab_url?>">Problem Solving Lab</a>    </div>
	  
	<!-- The lab article has an header, optional navigational 
	menu, number of sections, an optional sidebar and a closing 
	footer-->

	<header id="experiment-article-heading" class="heading">
	<!-- You can add a welcome message or title of the 
	experiment here -->
	<?php echo $labarticleheading; ?>	 
	<!-- Add any additional element if required with proper 
	enclosing-->
	</header>

	<!-- Navigation menu is useful to organize the view of 
	multiple sections inside the article-->
	
	<!-- Navigation menu is useful to organize the view of 
	multiple sections inside the article-->
		<nav id="experiment-article-navigation" class="default">
			<ul id="experiment-article-navigation-menu">
			  <!-- The menu can be dynamically generated to contain 
			  the headings of your sections or instead write the 
			  menu items of your choice individually enclosedu in 
			  <li> tag as shown below-->
				
				<?php foreach ($nav as $n) {?>
					<li> <a href="<?php echo $base_url."?section=".trim($n['heading']);?>">
				<!-- Enclose the icon image of your lab -->
					<?php echo $n['img']?> 
				<br>
				<?php echo $n['heading']?>
				 </a></li>
				<?php }?>
		
		
		
		</ul>
      </nav>

	<!-- All the sections of your lab or experiment can be 
	enclosed together with a div element as shown below-->
	<div id="experiment-article-sections">

	<!-- First section of the article-->
	<section id="experiment-article-section-1">

		<div id="experiment-article-section-1-icon" class="icon">
		<!-- Enclose the icon image of your lab -->
		<img src="http://deploy.virtual-labs.ac.in/labs/cse04/images/introduction.jpg">
		</div>	
		
		<!-- The heading for the section can be enclosed in a 
		div tag. -->
		<div id="experiment-article-section-1-heading" class="heading">
		<?php if(isset($data['SubHeading'])) echo $data['SubHeading'] ?>
		</div>
		<!-- Write the section content inside a paragraph 
		element, You can also include images with <img> tag -->
		<div id="experiment-article-section-1-content" class="content">	
		<?php if(isset($data['SubContent'])) echo $data['SubContent'] ?>
		
		</div>


	</section>

	
	
        

      </div>


    <!-- An article can have a sidebar that contain related 
    links and additional material (however it is kept optional 
    at this moment) -->
    <aside id="lab-article-sidebar" class="default">
      <!-- put the content that you want to appear in the 
      sidebar -->	
    </aside>


    <!-- Article footer can display related content and 
    additional links -->						
    <footer id="lab-article-footer" class="default">
      <!-- Put the content that you want to appear here -->
    </footer>

  </article>


  <!-- Links to other labs, about us page can be kept the lab 
  footer-->
   <footer id="lab-footer" class="footer">
    <!-- Put the content here-->
	<a href="http://virtual-labs.ac.in/nmeict/">Sponsered by MHRD (NME-ICT) </a> | <a href="http://virtual-labs.ac.in/licensing/" target="_blank"> Licensing Terms </a> | <a href="http://virtual-labs.ac.in/feedback/?lab=cse04/" target="_blank"> Feedback </a>
  </footer>
	
  	
  </div>
  
	
  <!-- Javascript at the bottom for fast page loading -->

  

  
  <!-- ******** ADD/OVERRIDE JAVASCRIPT FILES HERE ********* -->
  <?php include_once("analyticstracking.php") ?>



  <!-- ***************************************************** -->
  
</body>
</html>
