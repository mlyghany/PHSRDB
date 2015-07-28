<?php $pagetitle = 'Add Indication for the Study'; 
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
					<center><h1><?php echo($pagetitle); ?></h1>
					<table width="500px" style="margin-left: 50px; text-align: left;">
						<tr>
							<td>
							<center>
							<form name="addIndicationTrigger" id="addIndicationTrigger" method="post" action="">
								<input type="radio" name="contentTrigger" value="Existing" onclick="submit()" <?php if($contentFlag == "Existing") echo "checked"; ?>>Existing Indication
								<input type="radio" name="contentTrigger" value="New" onclick="submit()" <?php if($contentFlag == "New") echo "checked"; ?>>New Indication
							</form>
							</center>
							</td>
						</tr>
					</table>
					
					<?php
						if($contentFlag == "Existing"){
							$query = "SELECT * FROM indication";
							$result = mysql_query($query) or die("Query Failed");
							
							if($result){
								echo("<table width='400px' align='center' border='1'>");
								echo("<tr>");
								echo("<th>&nbsp;</th>");
								echo("<th>Name of Condition</th>");
								echo("</tr>");
								while($informant = mysql_fetch_array($result, MYSQL_ASSOC)){
									extract($informant);
									echo("<tr>");
									echo("<td><a href='javascript: pick($indication_id)'>Add</a></td>");
									echo("<td id='name$indication_id'>$indication_name</td>");
									echo("</tr>");	
								}
								echo("</table>");
							}
						}
						else{
						?>
						
					<form name="addIndication" id="addIndication" method="post" action="./addnewindicationprocess.php?studyid=<?php echo($studyid); ?>&callby=picker">
						<table id="indicationTable" width="500px" style="margin-left: 50px; text-align: left;">
							<thead>
							<tr>
								<td width="200px">
									Type:
								</td>
								
								<td width="450px">
									<select id="indicationType" name="indicationType" onChange="showContent()" class="inputBox">
										<option value="Medical">Medical Indication</option>
										<option value="Other">Other Indication</option>
									</select>
								</td>
							</tr>
							<tr>
								<td width="200px">
									Name of Indication:
								</td>
								
								<td width="450px">
									<input type="text" name="indicationName" size="33" class="inputBox"/>
								</td>
							</tr>
							<tr>
								<td width="200px">
									Description:
								</td>
								<td width="450px">
								<textarea cols="26" name="indicationDescription" class="inputBox"></textarea>
								</td>
							</tr>
							</thead>
								<tbody id="medicalIndication">
								<tr>
									<td width="200px">Full Course:</td>
									<td width="450px">
									<textarea cols="26" name="indicationFullCourse" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">Cause(s):</td>
									<td width="450px"><textarea cols="26" name="indicationCause" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">How to arrive at diagnosis:</td>
									<td width="450px"><textarea cols="26" name="indicationDiagnosis" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">Treatment <br/> (Herbs and/or Other Material):</td>
									<td width="450px">
									<textarea cols="26" name="indicationTreatmentHerb" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">Treatment <br/>(Non-material):</td>
									<td width="450px">
									<textarea cols="26" name="indicationTreatmentNonMat" class="inputBox"></textarea></td>
								</tr>
								<tr>
									<td width="200px">Treatment <br/>(Western Medicine):</td>
									<td width="450px">
									<textarea cols="26" name="indicationTreatmentWestern" class="inputBox"></textarea></td>
								</tr>
								</tbody>
							<tbody id="otherIndication">
								<tr>
									<td width="200px">Antidote <br/> [if indication is as poison]:</td>
									<td width="450px">
									<textarea cols="26" name="indicationAntidote" class="inputBox"></textarea></td>
								</tr>
							</tbody>
								<tr>
									<td colspan="2"><center><input type="submit" value="Add Indication" / ></center></td>
								</tr>
						</table>
						</form>
						</center>
					<?php } ?>
				</div>
				<script type="text/javascript">
					function showContent(){
						var typeFlag = document.addIndication.indicationType.value;
						
						if(typeFlag == "Medical"){
							document.getElementById('otherIndication').style.display = 'none';
							document.getElementById('medicalIndication').style.display = '';	
						}
						else{
							document.getElementById('otherIndication').style.display = '';
							document.getElementById('medicalIndication').style.display = 'none';
						}
					}
					showContent();
					
					function pick(indication_id){
					var name = document.getElementById('name' + indication_id).lastChild.nodeValue;
					
			
					var parentWindow = opener.document;
					var root = parentWindow.getElementById('indicationContent');
					var indicationCount = parentWindow.addMaterial.indicationCount.value;
			
					indicationCount++;
				
					var content = document.createElement('input');
					content.setAttribute('type', 'hidden');
					content.setAttribute('value', indication_id);
					content.setAttribute('name', 'studyIndication' + indicationCount);
			
			
					root.appendChild(content);
			
					content = document.createTextNode(name);
		
					root.appendChild(content);
					root.appendChild(parentWindow.createElement('br'));
			
					parentWindow.addMaterial.indicationCount.value = indicationCount;
					self.close();
					
					}
					
				</script>