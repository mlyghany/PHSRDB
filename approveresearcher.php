<?php 
	require_once('header.inc'); $pagetitle = 'Home'; ?>
	<!---- body  --->
	<?php require_once('navis_bg.inc');?>
	<!---etong next line nalang yung babaguhin mo everytime 
	mag-aadd ka ng content na iba, then iinclude nalang ulit.-->
	<?php if($member_type == 'admin'){
			require_once('content_approveresearcher.inc');
		}
		else{
			include('notauthorized.php');
		}
	?>
	<!---end body--->
	<?php require_once('footer.inc');?>
	