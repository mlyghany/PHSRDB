<?php
	session_start();
	require_once("configure.php");

	$informantid = $_GET['informantid'];
	$studyid = $_GET['studyid'];
	
	$query = "INSERT into study_informant (study_id, informant_id) VALUES ('$studyid', '$informantid')";
	$result = mysql_query($query) or die("Query Failed!");
	
	header("location: ./viewresearch.php?studyid=$studyid");
?>