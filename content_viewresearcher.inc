<?php 
	require_once("configure.php");
	$query = "SELECT * FROM researcher WHERE researcher_approveFlag = 'A'";
	$result = mysql_query($query) or die("Query Failed!");
	$i = 0;
	echo ("<h1>Researcher/s</h1>");
	echo "<table id=\"researcherTable\" style=\"margin-left: 50px;\" width=\"600px\">";
		
		//display the researchers				
		while ($row = mysql_fetch_assoc($result)) {
			$i++;
			echo "<tr><td>" . $i . "</td>";
			echo "<td><a href=\"viewresearcherinfo.php?researcherid=" . $row["researcher_id"] . "\">" . $row["researcher_lastname"] . ", " 	. $row["researcher_firstname"];
			if($row["researcher_mi"] != "") echo " " . $row["researcher_mi"] . ".";
			echo " (" . $row["researcher_username"] . ")";
			echo "<br /></a></td></tr>";
		}
		if($i == 0) echo("<tr><td><em>There are no researchers to display.</em></td></tr>");
		
	echo "</table>";
?>
				<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
				<div name="contentBox" style="background: transparent;">
				</div>
			
		