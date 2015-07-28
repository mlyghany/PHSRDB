<?php
	require_once("configure.php");
	
	$callby = $_GET['callby'];
	$studyid = $_GET['studyid'];
	$informantlastname = $_POST['informantLastName'];
	$informantfirstname = $_POST['informantFirstName'];
	$informantmi = $_POST['informantMI'];
	$informantaddress = $_POST['informantAddress'];
	$informantbirthday = $_POST['informantBirthday'];
	$informantsex = $_POST['informantSex'];
	$informantoccupation = $_POST['informantOccupation'];
	$informanteducationalattainment = $_POST['informantEducationalAttainment'];
	$informantmaritalstatus = $_POST['informantMaritalStatus'];
	$informantreligion = $_POST['informantReligion'];
	$informanttype = $_POST['informantType'];
	$informanthealingpractice = $_POST['informantHealingPractice'];
	$informantlengthofexperience = $_POST['informantLengthOfExperience'];
	$informantcasehistory = $_POST['informantCaseHistory'];
	$informantfamily = $_POST['informantFamily'];
	$informantdategathered = $_POST['informantDateGathered'];
	
	$query = "INSERT into informant (informant_lastname, informant_firstname, informant_mi, informant_address, informant_birthday, informant_sex, informant_occupation, informant_educationalattainment, informant_maritalstatus, informant_religion, informant_type, informant_healingpractice, informant_lengthofexperience, informant_casehistory, informant_familymembers, informant_dategathered) VALUES ('$informantlastname', '$informantfirstname', '$informantmi', '$informantaddress', '$informantbirthday', '$informantsex', '$informantoccupation', '$informanteducationalattainment', '$informantmaritalstatus', '$informantreligion', '$informanttype', '$informanthealingpractice', '$informantlengthofexperience', '$informantcasehistory', '$informantfamily', '$informantdategathered')";
	$result = mysql_query($query) or die("Query Failed!");
	
	$informantid = mysql_insert_id();
	
	$gatherercount = $_POST['gathererCount'];
	
	for($i=1; $i<=$gatherercount; $i++){
		$gathererid = $_POST['gatherer' . $i];
		$query = "INSERT INTO informant_gatherer (informant_id, gatherer_id) VALUES ('$informantid', '$gathererid')";
		$result = mysql_query($query) or die("Query Failed");
	}
	
	
	if($callby == ""){
	$query2 = "INSERT into study_informant (study_id, informant_id) VALUES ('$studyid', '$informantid')";
	$result2 = mysql_query($query2) or die("Query Failed!");
	
		header("location: ./viewresearch.php?studyid=$studyid");
	}
	else{
?>

<html>
<body>
<script type="text/javascript">
		function sendToParent(){
			var parentWindow = opener.document;
			
			var informantCount = parentWindow.addMaterial.informantCount.value;
			
			informantCount++;
			
			var root = parentWindow.getElementById('informantContent');;
			
			var content = document.createElement('input');
			content.setAttribute('type', 'hidden');
			content.setAttribute('value', '<?php echo($informantid); ?>');
			content.setAttribute('name', 'studyInformant' + informantCount);
			
			
			root.appendChild(content);
			
			content = document.createTextNode('<?php echo(ucfirst($informantlastname) . ", " . ucfirst($informantfirstname) . " " . ucfirst($informantmi) . "."); ?>');
			
			root.appendChild(content);
			root.appendChild(parentWindow.createElement('br'));
			
			parentWindow.addMaterial.informantCount.value = informantCount;
			self.close();
		}
		sendToParent();
</script>
</body>
</html>
	
<?php } ?>