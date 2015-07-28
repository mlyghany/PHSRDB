<?php
	require_once("configure.php");
	
	$studyid = $_GET['studyid'];
	$herbariumid = $_GET['herbariumid'];
	$herbariumscientificname = $_POST['scientificName'];
	$herbariumfieldnumber = $_POST['fieldNumber'];
	$herbariumnumber = $_POST['herbariumNumber'];
	$herbariumcollector = $_POST['collector'];
	$herbariumcollectornumber = $_POST['collectorNumber'];
	$herbariumgeographicarea = $_POST['geographicAreaOfCollection'];
	$herbariumlatitude = $_POST['latitude'];
	$herbariumhabitat = $_POST['habitat'];
	$herbariumaltitude = $_POST['altitudeAboveSeaLevel'];
	$herbariumhabit = $_POST['habit'];
	$herbariumheight = $_POST['height'];
	$herbariumdiameter = $_POST['diameterOfTrunk'];
	$herbariumflower = $_POST['flower'];
	$herbariumfruit = $_POST['fruit'];
	$herbariumidentifierlastname = $_POST['specimenVoucherIdentifierSurname'];
	$herbariumidentifierfirstname = $_POST['specimenVoucherIdentifierFirstName'];
	$herbariumidentifiermi = $_POST['specimenVoucherIdentifierMiddleName'];
	$herbariumdateofidentification = $_POST['dateOfIdentificationOfSpecimenVoucher'];
	$herbariumspecimenvoucherkeptat = $_POST['specimenVoucherKeptAt'];
	
	if($herbariumidentifierlastname == "Last Name"){
		$herbariumidentifierlastname = "";
	}
	if($herbariumidentifierfirstname == "First Name"){
		$herbariumidentifierfirstname = "";
	}
	if($herbariumidentifiermi == "Middle Initial"){
		$herbariumidentifiermi = "";
	}
	
	$query = "UPDATE herbarium SET herbarium_scientificname = '$herbariumscientificname', herbarium_fieldnumber = '$herbariumfieldnumber', herbarium_number = '$herbariumnumber', herbarium_collector = '$herbariumcollector', herbarium_collectornumber = '$herbariumcollectornumber', herbarium_geographicarea = '$herbariumgeographicarea', herbarium_latitude = '$herbariumlatitude', herbarium_habitat = '$herbariumhabitat', herbarium_altitude = '$herbariumaltitude', herbarium_habit = '$herbariumhabit', herbarium_height = '$herbariumheight', herbarium_diameter = '$herbariumdiameter', herbarium_flower = '$herbariumflower', herbarium_fruit = '$herbariumfruit', herbarium_identifierlastname = '$herbariumidentifierlastname', herbarium_identifierfirstname = '$herbariumidentifierfirstname', herbarium_identifiermi = '$herbariumidentifiermi', herbarium_dateofidentification = '$herbariumdateofidentification', herbarium_specimenkeptat = '$herbariumspecimenvoucherkeptat' WHERE herbarium_id = '$herbariumid'";
        $result = mysql_query($query) or die("Query Failed!");
	
	$namecount = $_POST['otherNum'];

        $query = "DELETE FROM herbarium_othername WHERE herbarium_id = '$herbariumid'";
        $result = mysql_query($query) or die("Query Failed!");

	for($i=1; $i<=$namecount; $i++){
		$othername = $_POST['otherName' . $i];
		$language = $_POST['language' . $i];
		$type = $_POST['type' . $i];
		
		$query = "INSERT into herbarium_othername (herbarium_id, othername_name, othername_language, othername_type) VALUES ('$herbariumid', '$othername', '$language', '$type')";
                $result = mysql_query($query) or die("Query Failed!");
		
	}
	
	header("location: ./viewherbarium.php?herbariumid=$herbariumid&studyid=$studyid");
	
?>