<?php 
	require_once('header.inc'); $pagetitle = 'Researcher Profile'; ?>
	<!---- body  --->
	<?php require_once('navis_bg.inc');?>
	<!---etong next line nalang yung babaguhin mo everytime 
	mag-aadd ka ng content na iba, then iinclude na lang ulit.-->
	<?php
	$_SESSION['researcher_id'] = $_GET['researcherid'];
	require_once('content_viewapprovedaccounts.inc');
	?>
	<!---end body--->
	<?php require_once('footer.inc');?>