<?php
	require_once("configure.php");
	
	$studyid = $_GET['studyid'];
	$callby = $_GET['callby'];
	
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
	
	$query = "INSERT into herbarium (herbarium_scientificname, herbarium_fieldnumber, herbarium_number, herbarium_collector, herbarium_collectornumber, herbarium_geographicarea, herbarium_latitude, herbarium_habitat, herbarium_altitude, herbarium_habit, herbarium_height, herbarium_diameter, herbarium_flower, herbarium_fruit, herbarium_identifierlastname, herbarium_identifierfirstname, herbarium_identifiermi, herbarium_dateofidentification, herbarium_specimenkeptat) VALUES ('$herbariumscientificname', '$herbariumfieldnumber', '$herbariumnumber', '$herbariumcollector', '$herbariumcollectornumber', '$herbariumgeographicarea', '$herbariumlatitude', '$herbariumhabitat', '$herbariumaltitude', '$herbariumhabit', '$herbariumheight', '$herbariumdiameter', '$herbariumflower', '$herbariumfruit', '$herbariumidentifierlastname', '$herbariumidentifierfirstname', '$herbariumidentifiermi', '$herbariumdateofidentification', '$herbariumspecimenvoucherkeptat')";
	$result = mysql_query($query) or die("Query Failed!");
	
	$namecount = $_POST['otherNum'];
	$herbariumid = mysql_insert_id();
	
	for($i=1; $i<=$namecount; $i++){
		$othername = $_POST['otherName' . $i];
		$language = $_POST['language' . $i];
		$type = $_POST['type' . $i];
		
		$query = "INSERT into herbarium_othername (herbarium_id, othername_name, othername_language, othername_type) VALUES ('$herbariumid', '$othername', '$language', '$type')";
		$result = mysql_query($query) or die("Query Failed!");
		
	}
	
	if($callby == ""){
	
	$query = "INSERT INTO study_herbarium (study_id, herbarium_id) VALUES ('$studyid', '$herbariumid')";
	$result = mysql_query($query) or die("Query Failed!");
	
	
		header("location: ./viewresearch.php?studyid=$studyid");
	}
	
	else{
?>

<html>
<head>
<script>
function sendToParent(){
        var parentWindow = opener.document;
        var root = parentWindow.getElementById('herbariumContent');
        var herbariumCount = parentWindow.addMaterial.herbariumCount.value;

        herbariumCount++;
		
        var row = document.createElement('tr');
        var col = document.createElement('td');

		var content = document.createTextNode('<?php echo($herbariumscientificname); ?>');
		 
        col.appendChild(content);

        content = document.createElement('input');
        content.setAttribute('type', 'hidden');
        content.setAttribute('name', "materialHerbarium" + herbariumCount);
        content.setAttribute('id' ,  "materialHerbarium" + herbariumCount);
        content.setAttribute('value', '<?php echo($herbariumid); ?>');

        col.appendChild(content);
        row.appendChild(col);

        col = parentWindow.createElement('td');
        content = parentWindow.createElement('input');
        content.setAttribute('type', 'text');
		content.setAttribute('class', 'inputBox');
		content.setAttribute('name',"materialPartUsed" + herbariumCount);
        content.setAttribute('id' , "materialPartUsed" + herbariumCount);
        content.setAttribute('size' , '13');
		
		col.appendChild(content);
        row.appendChild(col);

        root.appendChild(row);

		 
        col = parentWindow.createElement('td');
        content = parentWindow.createElement('input');
        content.setAttribute('type', 'text');
        content.setAttribute('name',"materialGathering" + herbariumCount);
        content.setAttribute('id' , "materialGathering" + herbariumCount);
		content.setAttribute('class', 'inputBox');
        content.setAttribute('size' , '13');

        col.appendChild(content);
        row.appendChild(col);

        root.appendChild(row);

        col = parentWindow.createElement('td');
        content = parentWindow.createElement('input');
        content.setAttribute('type', 'text');
        content.setAttribute('name',"materialPostharvest" + herbariumCount);
        content.setAttribute('id' , "materialPostharvest" + herbariumCount);
        content.setAttribute('class', 'inputBox');
        content.setAttribute('size' , '13')

        col.appendChild(content);
        row.appendChild(col);

        root.appendChild(row);

        parentWindow.addMaterial.herbariumCount.value = herbariumCount;
		self.close();
    }
	sendToParent();
</script>
</head>
</html>

<?php } ?>
