<?php
	session_start();
	require_once("configure.php");

	$indicationid = $_GET['indicationid'];
	$studyid = $_GET['studyid'];
	
	$query = "INSERT into study_indication(study_id, indication_id) VALUES ('$studyid', '$indicationid')";
	$result = mysql_query($query) or die("Query Failed!");
	
	header("location: ./viewresearch.php?studyid=$studyid");
?>