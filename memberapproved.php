<?php require_once('header.inc');?>
	<!---- body  --->
	<?php require_once('navis_bg.inc');?>
	<!---etong next line nalang yung babaguhin mo everytime 
	mag-aadd ka ng content na iba, then iinclude nalang ulit.-->
	<?php if($member_type == 'admin'){
			require_once('content_memberapproved.inc');
		}
		else{
			include('notauthorized.php');
		}
	?>	<!---end body--->
	<?php require_once('footer.inc');?>
	