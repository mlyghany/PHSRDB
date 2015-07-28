<?php $pagetitle = 'Add Material for the Study'; ?>
<div name="contentBox" style="background: transparent;">
<center><h1><?php echo($pagetitle); ?></h1></center>
	<br />
	<form name="addMaterial" id="addMaterial" method="post" action="./addnewmaterialprocess.php?studyid=<?php echo($studyid); ?>">
		<table id="materialTable" width="600px" style="margin-left: 50px; text-align: left;">
			<tbody>
				<tr>
					<td width="200px">
						Ethnopharmacological or Other Indication
						<button type="button" onclick="showIndicationPicker()">+</button>
					</td>
					<td width="400px" id="indicationContent">
						<input type="hidden" id="indicationCount" name="indicationCount" value="0" />	
					</td>
				</tr>
				<tr>
					<td width="200px">
						Herbarium
						<button type="button" onclick="showHerbariumPicker()">+</button>
					</td>
					<td>
						<table id="herbariumContent" name="herbariumContent">
							<tr>
								<th width="100px">Herbarium</th>
								<th width="100px">Part Used</th>
								<th width="100px">Gathering</th>
								<th width="100px">Postharvest</th>
							</tr>
						</table>
						<input type="hidden" id="herbariumCount" name="herbariumCount" value="0" />	
					</td>
				</tr>
				<tr>
					<td width="200px">
						Preparation
					</td>
					<td width="400px">
						<textarea cols="26" name="materialPreparation" class="inputBox"></textarea>
					</td>
				</tr>
				<tr>
					<td width="200px">
						Direction for Use and Dosage
					</td>
					<td width="400px">
						<textarea cols="26" name="materialDirectionForUse" class="inputBox"></textarea>
					</td>
				</tr>
				<tr>
					<td width="200px">
						Toxicity
					</td>
					<td width="400px">
						<textarea cols="26" name="materialToxicity" class="inputBox"></textarea>
					</td>
				</tr>
				<tr>
					<td width="200px">
						Precautions
					</td>
					<td width="400px">
						<textarea cols="26" name="materialPrecautions" class="inputBox"></textarea>
					</td>
				</tr>
				<tr>
					<td width="200px">
						Additional Information
					</td>
					<td width="400px">
						<textarea cols="26" name="materialAdditionalInformation" class="inputBox"></textarea>
					</td>
				</tr>
				<tr>
					<td width="200px">
						Informant
						<button type="button" onclick="showInformantPicker()">+</button>
					</td>
					<td width="400px" id="informantContent">
						<input type="hidden" id="informantCount" name="informantCount" value="0" />	
					</td>
				</tr>
				<tr>
					<td colspan="2"><center><input type="submit" value="Add Material" /></center></td>
				</tr>
			</tbody>
		</table>
	</form>
</div>

<script type="text/javascript">
				function showIndicationPicker(){
					window.open("indicationPicker.php","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
				}
				
				function showHerbariumPicker(){
					window.open("herbariumPicker.php","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
				}
				
				function showInformantPicker(){
					window.open("informantPicker.php","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
				}
</script>


