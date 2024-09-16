<?php
	if($_FILES["file"]["size"] < 20000){
		move_uploaded_file($_FILES["file"]["tmp_name"], "upload/file.txt");
	}
?>
