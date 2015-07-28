<?php 
$pagetitle = 'View Material for the Study';
$materialid = $_GET["materialid"];
$query = "SELECT * FROM material WHERE  material_id='$materialid'";
$result = mysql_query($query) or die("Query Failed!");
$material = mysql_fetch_array($result, MYSQL_ASSOC);
if($material) extract($material); 

$query = "SELECT * FROM material_herbarium WHERE  material_id='$materialid'";
$result = mysql_query($query) or die("Query Failed!");
while ($row = mysql_fetch_assoc($result)) {
	$herbariumid = $row["herbarium_id"];
	$query2 = "SELECT * FROM herbarium WHERE herbarium_id='$herbariumid'";
	$result2 = mysql_query($query2) or die("Query Failed!");
	$herbarium = mysql_fetch_array($result2, MYSQL_ASSOC);
	if($herbarium) extract($herbarium);
}

$query = "SELECT * FROM material_indication WHERE  material_id='$materialid'";
$result = mysql_query($query) or die("Query Failed!");
while ($row = mysql_fetch_assoc($result)) {
	$indicationid = $row["indication_id"];
	$query2 = "SELECT * FROM indication WHERE indication_id='$indicationid'";
	$result2 = mysql_query($query2) or die("Query Failed!");
	$indication = mysql_fetch_array($result2, MYSQL_ASSOC);
	if($indication) extract($indication);
}

?>
<div name="contentBox" style="background: transparent;">
<center><h1><?php echo($pagetitle); ?></h1></center>
	<br />
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
</div>


