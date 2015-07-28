<?php
	require_once("configure.php");
	
	$studyid = $_GET['studyid'];
	
	$materialpreparation = $_POST['materialPreparation'];
	$materialdirection =  $_POST['materialDirectionForUse'];
	$materialtoxicity = $_POST['materialToxicity'];
	$materialprecautions = $_POST['materialPrecautions'];
	$materialadditionalinformation = $_POST['materialAdditionalInformation'];
	
	$query = "INSERT into material (material_preparation, material_direction, material_toxicity, material_precaution, material_additionalinformation) VALUES ('$materialpreparation', '$materialdirection', '$materialtoxicity', '$materialprecautions', '$materialadditionalinformation')";
	$result = mysql_query($query) or die("Query Failed!");
	
	$materialid = mysql_insert_id();
	$herbariumcount = $_POST['herbariumCount'];
	$indicationcount = $_POST['indicationCount'];
	$informantcount = $_POST['informantCount'];
	
	for($i=1; $i<=$herbariumcount; $i++){
	
		
		$herbariumid = $_POST['materialHerbarium' . $i];
		$materialpartused = $_POST['materialPartUsed' . $i];
		$materialgathering = $_POST['materialGathering' . $i];
		$materialpostharvest = $_POST['materialPostharvest' . $i];
		
		$query = "INSERT into material_herbarium (material_id, herbarium_id, material_partused, material_gathering, material_postharvest) VALUES ('$materialid', '$herbariumid', '$materialpartused', '$materialgathering', '$materialpostharvest')";
		$result = mysql_query($query) or die("Query Failed!");
		
		$query = "INSERT into study_herbarium (study_id, herbarium_id) VALUES ('$studyid', '$herbariumid')";
		$result = mysql_query($query) or die("Query Failed!");
	}
	
	for($i=1; $i<=$indicationcount; $i++){
		$indicationid = $_POST['studyIndication' . $i];
		
		$query = "INSERT into material_indication (material_id, indication_id) VALUES ('$materialid', '$indicationid')";
		$result = mysql_query($query) or die("Query Failed!");
		
		$query = "INSERT into study_indication (study_id, indication_id) VALUES ('$studyid', '$indicationid')";
		$result = mysql_query($query) or die("Query Failed!");
	}
	
	for($i=1; $i<=$informantcount; $i++){
		$informantid = $_POST['studyInformant' . $i];
		
		$query = "INSERT into material_informant (material_id, informant_id) VALUES ('$materialid', '$informantid')";
		$result = mysql_query($query) or die("Query Failed!");
		
		$query = "INSERT into study_informant (study_id, informant_id) VALUES ('$studyid', '$informantid')";
		$result = mysql_query($query) or die("Query Failed!");
	}
	
	$query = "INSERT into study_material (study_id, material_id) VALUES ('$studyid', '$materialid')";
	$result = mysql_query($query) or die("Query Failed!");
	
	
	header("location: ./viewresearch.php?studyid=$studyid");
	
?>