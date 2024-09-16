<?php
	$file=fopen("upload/savedFile.txt","w") or exit("unable to open file");
	echo $_GET[content];
	fwrite($file,$_GET['content']);
?>
