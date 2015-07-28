<?php 
	require_once("configure.php");
	// get the id of the researcher to display
	$researcher_id = $_SESSION['researcher_id'];
	$query = "SELECT * FROM researcher WHERE researcher_id = '$researcher_id' ";
	$result = mysql_query($query) or die("Query Failed!");
	$researcher = mysql_fetch_array($result, MYSQL_ASSOC);
	extract($researcher);
	
?>
				<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
				<div name="contentBox" style="background: transparent;">
					<!--RESEARCHER INFO-->
					<h1>Researcher Info<?php if($member_username == $researcher_username){?><a href="editprofile.php" class="viewLinks">  [edit]</a><?php } ?></h1>
					<table id="researcherInfo" style="margin-left: 50px;" width="600px">
						<?php
								//name
								echo("<tr>");
								echo("<td width='200px'><strong>Name:</strong></td>");
								echo("<td width='400px'>");	
								echo $researcher_lastname . ", " . $researcher_firstname;
									if(!($researcher_mi == "")) echo " " . $researcher_mi . ".";
								
								//sex
								echo("</tr><tr>");
								echo("<td width='200px'><strong>Sex:</strong></td>");
								echo("<td width='400px'>");	
									if($researcher_sex == "M") echo "Male";
									else if($researcher_sex == "F") echo "Female";
								
								//bday
								echo("</tr><tr>");
								echo("<td width='200px'><strong>Birthday:</strong></td>");
								echo("<td width='400px'>");	
									if(!($researcher_birthday == "0000-00-00")) echo $researcher_birthday;
									else echo "-";

								//email
								echo("</tr><tr>");
								echo("<td width='200px'><strong>Email::</strong></td>");
								echo("<td width='400px'>");
									if(!($researcher_email == "")) echo $researcher_email;
									else echo "-";

								//address
								echo("</tr><tr>");
								echo("<td width='200px'><strong>Address:</strong></td>");
								echo("<td width='400px'>");	
									if(!($researcher_address == "0")) echo $researcher_address;
									else echo "-";

								//location
								echo("</tr><tr>");
								echo("<td width='200px'><strong>Location:</strong></td>");
								echo("<td width='400px'>");	
									if(!($researcher_location == "")) echo $researcher_location;
									else echo "-";		

								//occupation
								echo("</tr><tr>");
								echo("<td width='200px'><strong>Occupation:</strong></td>");
								echo("<td width='400px'>");	
									if(!($researcher_occupation == "")) echo $researcher_occupation;
									else echo "-";	

								//work address
								echo("</tr><tr>");
								echo("<td width='200px'><strong>Work Address:</strong></td>");
								echo("<td width='400px'>");	
									if(!($researcher_workAddress == "")) echo $researcher_workAddress;
									else echo "-";	
								echo("</tr>");
						?>
					</table>
					
					<!--RESEARCHER ENTRIES-->
					<h1>Researcher Entries</h1>
					<table id="researcherEntries" style="margin-left: 50px;" width="600px">
						<?php
								$query2 = "SELECT member_id as mid FROM members WHERE member_username = '$researcher_username' ";
								$result2 = mysql_query($query2) or die("Query Failed!");
								$membertofind = mysql_fetch_array($result2, MYSQL_ASSOC);
								if($membertofind){ extract($membertofind); }
								
								$query = "SELECT * FROM study_researcher WHERE researcher_id = '$mid' ";
								$result = mysql_query($query) or die("Query Failed!");
								$i = 0;
								//display the study
								while ($row = mysql_fetch_assoc($result)) {
									$i++;
									$studyid = $row["study_id"];
									$query = "SELECT * FROM study WHERE study_id = '$studyid'";
									$result2 = mysql_query($query) or die("Query Failed!");
									$study = mysql_fetch_array($result2, MYSQL_ASSOC);
									extract($study);
									if ($study_title == "") $study_title = "Untitled";
									echo "<tr><td><a href=\"viewresearch.php?studyid=" . $row["study_id"] . "\"><strong>" . $i . "</strong> - " . $study_title . "<br /></a></td></tr>";
								}
								if($i == 0) echo("<tr><td><em>There are no entries from this researcher to display.</em></td></tr>");
						?>
					</table>
				</div>