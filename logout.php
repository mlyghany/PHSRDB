<?php
		require_once('header.inc'); $pagetitle = 'Home'; 
?>
	<!---- body  --->
	<?php
		session_unset();
		$member = "";
		require_once('navis_bg.inc');?>
	<!---etong next line nalang yung babaguhin mo everytime 
	mag-aadd ka ng content na iba, then iinclude nalang ulit.-->
	<?php require_once('content_logout.inc');?>
	<!---end body--->
	<?php require_once('footer.inc');?>
	