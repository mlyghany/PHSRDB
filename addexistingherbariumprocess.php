<?php
	session_start();
	require_once("configure.php");

	$herbariumid = $_GET['herbariumid'];
	$studyid = $_GET['studyid'];
	
	$query = "INSERT into study_herbarium (study_id, herbarium_id) VALUES ('$studyid', '$herbariumid')";
	$result = mysql_query($query) or die("Query Failed!");
	
	header("location: ./viewresearch.php?studyid=$studyid");
?>