<?php include('header.inc'); ?>
<?php include('configure.php'); ?>
<?php $pagetitle = 'Add Gatherer'; ?>
<?php 
	if($_POST['pickerContentTrigger']){
		$contentFlag = $_POST['pickerContentTrigger'];
	}
	else{
		$contentFlag = "Existing";
	}	
?>
<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
	<div name="contentBox" style="background: transparent;">
		<h1><center><?php echo $pagetitle;?><center></h1>
		
			<table width="500px" style="margin-left: 50px; text-align: left;">
				<thead>
					<center>
					<form name="pickGathererTrigger" id="pickGathererTrigger" method="post" action="">
						<input type="radio" name="pickerContentTrigger" value="Existing" onclick="submit()" <?php if($contentFlag == "Existing") echo "checked"; ?>>Existing Gatherer
						<input type="radio" name="pickerContentTrigger" value="New" onclick="submit()" <?php if($contentFlag == "New") echo "checked"; ?>>New Gatherer
					</form>
					</center>
				</thead>
				<tbody id="gahtererPickerContent">
					<?php
						if($contentFlag == "Existing"){
							$query = "SELECT * FROM gatherer";
							$result = mysql_query($query) or die("Query Failed");
							
							if($result){
								echo("<table width='400px' align='center' border='1'>");
								echo("<tr>");
								echo("<th>&nbsp;</th>");
								echo("<th>Last Name</th>");
								echo("<th>First Name</th>");
								echo("<th>Middle Initial</th>");
								echo("</tr>");
								while($gatherer = mysql_fetch_array($result, MYSQL_ASSOC)){
									extract($gatherer);
									echo("<tr>");
									echo("<td><a href='javascript: pick($gatherer_id);'>Add</a></td>");
									echo("<td id='lastname$gatherer_id'>$gatherer_lastname</td>");
									echo("<td id='firstname$gatherer_id'>$gatherer_firstname</td>");
									echo("<td id='mi$gatherer_id'>$gatherer_mi</td>");
									echo("</tr>");	
								}
								echo("</table>");
							}
						}
						else{
						?>
							<form name="pickGatherer" id="pickGatherer" method="post" action="./addgathererentry.php">
							<tr>
								<br />
								<td width="100px">Last Name</td>
								<td width="400px"><input type="text" name="gathererLastName" size="40" class="inputBox" /></td>
							</tr>
							<tr>
								<td width="100px">First Name</td>
								<td width="400px"><input type="text" name="gathererFirstName" size="40" class="inputBox" /></td>
							</tr>
							<tr>
								<td width="100px">Middle Inital</td>
								<td width="400px"><input type="text" name="gathererMI" size="10" class="inputBox" /></td>
							</tr>
							<tr>
								<td colspan="2" style="text-align: center;"><input type="submit" value="Add Gatherer" /></td>
							</tr>
							</form>
						<?php } ?>
				</tbody>
			</table>
		</div>
	</body>
	
	<script type="text/javascript">
    function pick(gatherer_id){
        var lastname = document.getElementById('lastname' + gatherer_id).lastChild.nodeValue;
        var firstname = document.getElementById('firstname' + gatherer_id).lastChild.nodeValue;
        var mi = document.getElementById('mi' + gatherer_id);
        if(mi.hasChildNodes()) mi = mi.lastChild.nodeValue;
        else mi = "";
        var parentWindow = opener.document;
        var root = parentWindow.getElementById('gathererContent');
        var gathererCount = parentWindow.addInformant.gathererCount.value;
        gathererCount++;
        alert(gathererCount);
        var tr = document.createElement('tr');
        var td1 = document.createElement('td');
        var content = document.createElement('input');
        var remove = document.createElement('input');

        content.setAttribute('name', "gatherer" + gathererCount);
        content.setAttribute('id', "gatherer" + gathererCount);
        content.setAttribute('type', 'hidden');
        content.setAttribute('value', gatherer_id);
        tr.appendChild(content);

        tr.setAttribute('name', 'informantGatherer' + gathererCount);
        tr.setAttribute('id', 'informantGatherer' + gathererCount);
        remove.setAttribute('onclick', 'Javascript: removeGatherer(' + gathererCount + ')');
        remove.setAttribute('value', 'remove');
        remove.setAttribute('type', 'button');
        remove.setAttribute('id', 'remove' + gathererCount);

        content = document.createTextNode(lastname + ', ' + firstname + ' ');
        if(mi != "") content = document.createTextNode(lastname + ', ' + firstname + ' ' + mi + ".");
        td1.appendChild(content);
        td1.appendChild(remove);
        tr.appendChild(td1);
        root.appendChild(tr);

        parentWindow.addInformant.gathererCount.value = gathererCount;
        self.close();
    }
	</script>
	
</html>
			
		