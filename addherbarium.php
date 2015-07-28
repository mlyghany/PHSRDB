<?php 
	require_once('header.inc');
	require_once('configure.php');
	
	$studyid= $_GET['studyid'];
	
	
	$query = "SELECT * FROM study_researcher where study_id='$studyid'";
	$result = mysql_query($query) or die("Query Failed!");
	$studyresearcher = mysql_fetch_array($result, MYSQL_ASSOC);
	if($studyresearcher){
		extract($studyresearcher);
	}
?>
	<!---- body  --->
	<?php require_once('navis_bg.inc');?>
	<!---etong next line nalang yung babaguhin mo everytime 
	mag-aadd ka ng content na iba, then iinclude nalang ulit.-->
	<?php if($member_id == $researcher_id && $studyid != ""){
			require_once('content_addherbarium.inc');
		}
		else{
			include('notauthorized.php');
		}
	?>
	<!---end body--->
	<?php require_once('footer.inc');?>
	