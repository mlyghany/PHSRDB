<?php 
	include("./configure.php");
	
	$searchstring = $_POST['search'];
	$searchdb = $_POST['source'];

	$pagetitle = "Search Results: ";
	
	$counter=0;
	$studarray = array();
?>

<h1><?php echo($pagetitle); ?></h1>
	
<?php
	$query1 = "SELECT author_id from author WHERE author_firstname LIKE '%$searchstring%' OR author_lastname LIKE '%$searchstring%' OR author_mi LIKE '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($author = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($author) extract($author);
		
		$query2 = "SELECT study_id as stud1 FROM study_author WHERE author_id = $author_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		while($study1 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study1) extract($study1);
		
			$studarray[$counter] = $stud1;
			$counter++;
		}
		
	}
	
	$query1 = "SELECT gatherer_id from gatherer WHERE gatherer_firstname LIKE '%$searchstring%' OR gatherer_lastname LIKE '%$searchstring%' OR gatherer_mi LIKE '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($gatherer = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($gatherer) extract($gatherer);
		
		$query2 = "SELECT informant_id from informant_gatherer WHERE gatherer_id = $gatherer_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($informant_gatherer = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($informant_gatherer) extract ($informant_gatherer);
					
			$query4 = "SELECT study_id as stud2 from study_informant where informant_id = $informant_id";
			$result4 = mysql_query($query4) or die("Query Failed!");
			
			while($study2 = mysql_fetch_array($result4, MYSQL_ASSOC)){
				if($study2) extract($study2);
	
				$studarray[$counter] = $stud2;
				$counter++;
			}
		}
	} 
	
	$query1 = "select herbarium_id from herbarium where `herbarium_fieldnumber` like '%$searchstring%' or `herbarium_number` like '%$searchstring%' or `herbarium_collector` like '%$searchstring%' or `herbarium_collectornumber` like '%$searchstring%' or `herbarium_geographicarea` like '%$searchstring%' or `herbarium_latitude` like '%$searchstring%' or `herbarium_habitat` like '%$searchstring%' or `herbarium_altitude` like '%$searchstring%' or `herbarium_habit` like '%$searchstring%' or `herbarium_height` like '%$searchstring%' or `herbarium_diameter` like '%$searchstring%' or `herbarium_flower` like '%$searchstring%' or `herbarium_fruit` like '%$searchstring%' or `herbarium_specimenkeptat` like '%$searchstring%' or `herbarium_scientificname` like '%$searchstring%' or `herbarium_identifierlastname` like '%$searchstring%' or `herbarium_identifierfirstname` like '%$searchstring%' or `herbarium_identifiermi` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($herbarium = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($herbarium) extract($herbarium);
		
		$query2 = "SELECT study_id as stud3 from study_herbarium where herbarium_id = $herbarium_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study3 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study3) extract($study3);
		
			$studarray[$counter] = $stud3;
			$counter++;
		}
	}
	
	$query1 = "select herbarium_id from herbarium_othername where `othername_name` like '%$searchstring%' or `othername_language` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($herbarium_othername = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($herbarium_othername) extract($herbarium_othername);
		
		$query2 = "SELECT study_id as stud4 from study_herbarium where herbarium_id = $herbarium_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study4 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study4) extract($study4);
		
			$studarray[$counter] = $stud4;
			$counter++;
		}
	}
	
	$query1 = "select indication_id from indication where `indication_name` like '%$searchstring%' OR `indication_description` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($indication = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($indication) extract($indication);
		
		$query2 = "SELECT study_id as stud5 from study_indication where indication_id = $indication_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study5 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study5) extract($study5);
		
			$studarray[$counter] = $stud5;
			$counter++;
		}
	}
	
	$query1 = "select indication_id from indication_medical where `indication_fullcourse` like '%$searchstring%' or `indication_cause` like '%$searchstring%' or `indication_diagnosis` like '%$searchstring%' or `indication_materialtreatment` like '%$searchstring%' or `indication_nonmaterialtreatment` like '%$searchstring%' or `indication_westerntreatment` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($indication_medical = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($indication_medical) extract($indication_medical);
		
		$query2 = "SELECT study_id as stud6 from study_indication where indication_id = $indication_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study6 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study6) extract($study6);
		
			$studarray[$counter] = $stud6;
			$counter++;
		}
	}
	
	$query1 = "select indication_id from indication_other where `indication_antidote` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($indication_other = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($indication_other) extract($indication_other);
		
		$query2 = "SELECT study_id as stud7 from study_indication where indication_id = $indication_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study7 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study7) extract($study7);
		
			$studarray[$counter] = $stud7;
			$counter++;
		}
	}
	
	$query1 = "select informant_id from informant where `informant_firstname` like '%$searchstring%' or `informant_lastname` like '%$searchstring%' or `informant_address` like '%$searchstring%' or `informant_occupation` like '%$searchstring%' or `informant_religion` like '%$searchstring%' or `informant_type` like '%$searchstring%' or `informant_healingpractice` like '%$searchstring%' or `informant_lengthofexperience` like '%$searchstring%' or `informant_educationalattainment` like '%$searchstring%' or `informant_casehistory` like '%$searchstring' or `informant_familymembers` like '%$searchstring'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($informant = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($informant) extract($informant);
		
		$query2 = "SELECT study_id as stud8 from study_informant where informant_id = $informant_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study8 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study8) extract($study8);
		
			$studarray[$counter] = $stud8;
			$counter++;
		}
	}
	
	$query1 = "select library_id from library where `library_name` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($library = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($library) extract($library);
		
		$query2 = "SELECT study_id as stud9 from study_library where library_id = $library_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study9 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study9) extract($study9);
		
			$studarray[$counter] = $stud9;
			$counter++;
		}
	}
	
	$query1 = "select material_id from material where `material_preparation` like '%$searchstring%' or `material_direction` like '%$searchstring%' or `material_toxicity` like '%$searchstring%' or `material_precaution` like '%$searchstring%' or `material_additionalinformation` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($material = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($material) extract($material);
		
		$query2 = "SELECT study_id as stud10 from study_material where material_id = $material_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study10 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study10) extract($study10);
		
			$studarray[$counter] = $stud10;
			$counter++;
		}
	}
	
	$query1 = "select material_id from material_herbarium where `material_partused` like '%$searchstring%' or `material_gathering` like '%$searchstring%' or `material_postharvest` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
	
	while($material_herbarium = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($material_herbarium) extract($material_herbarium);
		
		$query2 = "SELECT study_id as stud11 from study_material where material_id = $material_id";
		$result2 = mysql_query($query2) or die("Query Failed!");
		
		while($study11 = mysql_fetch_array($result2, MYSQL_ASSOC)){
			if($study11) extract($study11);
		
			$studarray[$counter] = $stud11;
			$counter++;
		}
	}
	
	$query1 = "select study_id as stud12 from study where `study_title` like '%$searchstring%'";
	$result1 = mysql_query($query1) or die("Query Failed!");
		
	while($study12 = mysql_fetch_array($result1, MYSQL_ASSOC)){
		if($study12) extract($study12);
	
		$studarray[$counter] = $stud12;
		$counter++;
	}
	
	$studarray = array_unique($studarray);
	sort($studarray);
	//print_r($studarray);
	
	if(sizeof($studarray) == 0){
		echo("<center>No search results to display.</center>");
	}
	echo("<ol type='1' style='margin-left: 50px;'>");
	for($i=0; $i<sizeof($studarray); $i++){
		
		$query= "select * from study WHERE study_id = '$studarray[$i]'";
		if($searchdb != "") { $query = $query . " and study_database = '$searchdb'"; }
		$result = mysql_query($query) or die("Query Failed!");
		
		while($study = mysql_fetch_array($result, MYSQL_ASSOC)){
			if($study) extract($study);
			
			echo("<li><a href='./viewresearch.php?studyid=$study_id'>" . $study_title . "</a></li>" );
		}
	}
	echo("</ul>");
	
?>
