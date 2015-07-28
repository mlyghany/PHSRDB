<?php
	require_once("configure.php");
	
	$callby = $_GET['callby'];
	$studyid = $_GET['studyid'];
	$indicationname = $_POST['indicationName'];
	$indicationdescription = $_POST['indicationDescription'];
	$indicationtype = $_POST['indicationType'];
	
	$query = "INSERT into indication (indication_name, indication_description, indication_type) VALUES ('$indicationname' , '$indicationdescription', '$indicationtype')";
	$result = mysql_query($query) or die("Query Failed!");
	
	$indicationid = mysql_insert_id();
	
	if($indicationtype == "Medical"){
		$indicationfullcourse = $_POST['indicationFullCourse'];
		$indicationcause = $_POST['indicationCause'];
		$indicationdiagnosis = $_POST['indicationDiagnosis'];
		$indicationtreatmentherb = $_POST['indicationTreatmentHerb'];
		$indicationtreatmentnonmat = $_POST['indicationTreatmentNonMat'];
		$indicationtreatmentwestern = $_POST['indicationTreatmentWestern'];
		
		$query = "INSERT into indication_medical (indication_id, indication_fullcourse, indication_cause, indication_materialtreatment, indication_nonmaterialtreatment, indication_westerntreatment, indication_diagnosis) VALUES ('$indicationid', '$indicationfullcourse' , '$indicationcause', '$indicationtreatmentherb' , '$indicationtreatmentnonmat', '$indicationtreatmentwestern', '$indicationdiagnosis')";
		$result = mysql_query($query) or die("Query Failed");
	}
	else{
		$indicationantidote = $_POST['indicationAntidote'];
		
		$query = "INSERT into indication_other (indication_id, indication_antidote) VALUES ('$indicationid', '$indicationantidote')";
		$result = mysql_query($query) or die("Query Failed!");
		
	}
	
	
	if($callby == ""){
	$query = "INSERT INTO study_indication (study_id, indication_id) VALUES ('$studyid', '$indicationid')";
	$result = mysql_query($query) or die("Query Failed!");
	
		header("location: ./viewresearch.php?studyid=$studyid");
	}
	else{
?>

<html>
<body>
<script type="text/javascript">
		function sendToParent(){
			var parentWindow = opener.document;
			
			var indicationCount = parentWindow.addMaterial.indicationCount.value;
			
			indicationCount++;
			
			var root = parentWindow.getElementById('indicationContent');;
			
			var content = document.createElement('input');
			content.setAttribute('type', 'hidden');
			content.setAttribute('value', '<?php echo($indicationid); ?>');
			content.setAttribute('name', 'studyIndication' + indicationCount);
			
			
			root.appendChild(content);
			
			content = document.createTextNode('<?php echo(ucfirst($indicationname)); ?>');
			
			root.appendChild(content);
			root.appendChild(parentWindow.createElement('br'));
			
			parentWindow.addMaterial.indicationCount.value = indicationCount;
			self.close();
		}
		sendToParent();
</script>
</body>
</html>

<?php } ?>