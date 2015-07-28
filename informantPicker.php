<?php $pagetitle = 'Add Informant for the Study'; 
	if($_POST['contentTrigger']){
		$contentFlag = $_POST['contentTrigger'];
	}
	else{
		$contentFlag = "Existing";
	}	
?>
<?php include('header.inc'); ?>
<?php include('configure.php'); ?>

	<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
	<div name="contentBox" style="background: transparent;">
		<center><h1><?php echo $pagetitle;?></h1>
		<form name="addInformantTrigger" id="addInformantTrigger" method="post" action="">
		<table width="500px" style="margin-left: 50px; text-align: center;">
			<tr>
				<td>
					<input type="radio" name="contentTrigger" value="Existing" onclick="submit()" <?php if($contentFlag == "Existing") echo "checked"; ?>>Existing Informant
					<input type="radio" name="contentTrigger" value="New" onclick="submit()" <?php if($contentFlag == "New") echo "checked"; ?>>New Informant
				</td>
			</tr>
		</table>
		</form>
			<?php
						if($contentFlag == "Existing"){
							$query = "SELECT * FROM informant";
							$result = mysql_query($query) or die("Query Failed");
							
							if($result){
								echo("<table width='400px' align='center' border='1'>");
								echo("<tr>");
								echo("<th>&nbsp;</th>");
								echo("<th>Last Name</th>");
								echo("<th>First Name</th>");
								echo("<th>Middle Initial</th>");
								echo("</tr>");
								while($informant = mysql_fetch_array($result, MYSQL_ASSOC)){
									extract($informant);
									echo("<tr>");
									echo("<td><a href='javascript: pick($informant_id)'>Add</a></td>");
									echo("<td id='lastname$informant_id'>$informant_lastname</td>");
									echo("<td id='firstname$informant_id'>$informant_firstname</td>");
									echo("<td id='mi$informant_id'>$informant_mi</td>");
									echo("</tr>");	
								}
								echo("</table>");
							}
						}
						else{
						?>
							<form name="addInformant" id="addInformant" method="post" action='./addnewinformantprocess.php?studyid=<?php echo($studyid); ?>&callby=picker'>
							<table width="500px" style="margin-left: 50px; text-align: left;">
								<tr>
									<br />
									<td width="200px">Last Name</td>
									<td width="400px"><input type="text" name="informantLastName" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">First Name</td>
									<td width="400px"><input type="text" name="informantFirstName" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Middle Initial</td>
									<td width="400px"><input type="text" name="informantMI" size="4" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Address</td>
									<td width="400px"><input type="text" name="informantAddress" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Birthday</td>
									<td width="400px"><input type="text" name="informantBirthday" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Sex</td>
									<td width="400px">
										<select  name="informantSex" class="inputBox"/>
											<option value="M">Male</option>
											<option value="F">Female</option>
										</select>
									</td>
								</tr>
								<tr>
									<td width="200px">Occupation/Livelihood</td>
									<td width="400px"><input type="text" name="informantOccupation" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Educational Attainment</td>
									<td width="400px"><textarea rows="2" cols="30" name="informantEducationalAttainment" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">Marital Status</td>
									<td width="400px">
										<select  name="informantMaritalStatus" class="inputBox"/>
											<option value="Single">Single</option>
											<option value="Married">Married</option>
											<option value="Divorced">Divorced</option>
											<option value="Widowed">Widowed</option>
										</select>
									</td>
								</tr>
								<tr>
									<td width="200px">Religion</td>
									<td width="400px"><input type="text" name="informantReligion" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Type of Informant</td>
									<td width="400px"><input type="text" name="informantType" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Type of Healing Practice</td>
									<td width="400px"><input type="text" name="informantHealingPractice" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Length of Experience</td>
									<td width="400px"><input type="text" name="informantReligion" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td width="200px">Informant Case History</td>
									<td width="400px"><textarea rows="2" cols="30" name="informantCaseHistory" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">Names of Immediate Family Members and Relationship</td>
									<td width="400px"><textarea rows="2" cols="30" name="informantFamily" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">Gatherer <input type="button" value="+" onclick="showGathererPicker()" /></td>
									<td width="200px" id="gathererContent">
										<input type="hidden" name="gathererCount" id="gathererCount" />
									</td>
								</tr>
								<tr>
									<td width="200px">Date Gathered</td>
									<td width="400px"><input type="text" name="informantDateGathered" size="40" class="inputBox"/></td>
								</tr>
								<tr>
									<td colspan="2"><center><input type="submit" value="Add Informant" /></center></td>
								</tr>
								</table>
								</form>
						<?php } ?>
		</center>
	</div>
	
	<script type="text/javascript">
				function showGathererPicker(){
					window.open("gathererPicker.php" ,"Ratting2","width=550,height=400,left=200,top=200,toolbar=1,status=1,");
				}
				
				function pick(informant_id){
					var lastname = document.getElementById('lastname' + informant_id).lastChild.nodeValue;
					var firstname = document.getElementById('firstname' + informant_id).lastChild.nodeValue;
					var mi = document.getElementById('mi' + informant_id).lastChild.nodeValue;
			
					var parentWindow = opener.document;
					var root = parentWindow.getElementById('informantContent');
					var informantCount = parentWindow.addMaterial.informantCount.value;
			
					informantCount++;
				
					var content = document.createElement('input');
					content.setAttribute('type', 'hidden');
					content.setAttribute('value', informant_id);
					content.setAttribute('name', 'studyInformant' + informantCount);
			
			
					root.appendChild(content);
			
					content = document.createTextNode(lastname + ', ' + firstname + ' ' + mi + '.');
		
					root.appendChild(content);
					root.appendChild(parentWindow.createElement('br'));
			
					parentWindow.addMaterial.informantCount.value = informantCount;
					self.close();
				}
	</script>
