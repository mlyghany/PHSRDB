<?php
 
$pagetitle = "Advanced Search";

?>

<center><h1><?php echo($pagetitle); ?></h1>
	<form name="advancedSearch" method="post" action="./advancedsearchprocess.php">
	<table width="600px" style="text-align: left;">
		<thead  id="searchContent">
			<tr>
				<td>
					<input type="hidden" id="queryCount" name="queryCount" value="1">
				</td>
			</tr>
			<tr>
				<th width="200px">
					Search for:
				</th>
				<th width="400px">
					contains:
				</th>
			</tr>
			
			<tr>
				<td>
					<select name="source1" id="source1" class="inputBox">
						<option value="Title">Title of the Study</option>
						<option value="Author">Author</option>
						<option value="Source/Library">Source</option>
						<option value="Herbarium">Herbarium</option>
						<option value="Indication">Indication</option>
						<option value="Material">Material</option>
						<option value="Informant">Informant</option>
					</select>
				</td>
				<td>
					<input type="text" name="searchstring1" id="searchstring1" size="40" class="inputBox"/>
					<input type="button" name="add" onclick="addField()" value="+">
					<input type="button" name="remove" onclick="removeField()" value="-">
				</td>
			</tr>
		</thead>
		<tbody>
			<tr>
				<td colspan="2"><center><input type="submit" value="Search" /></center></td>
			</tr>
		</tbody>
	</table>
	</form>
</center>

<script type="text/javascript">
	function addField(){
		var root = document.getElementById('searchContent');
		var count = document.advancedSearch.queryCount.value;
		var row = document.createElement('tr');
		var col, content;
		
		count++;
		
		col = document.createElement('td');
		
		content = document.createElement('select');
		content.setAttribute('name', 'source' + count);
		content.setAttribute('class', 'inputBox');
		
		content.innerHTML = document.getElementById('source1').innerHTML;
		
		col.appendChild(content);
		row.appendChild(col);
		
		col= document.createElement('td');
		content= document.createElement('input');
		content.setAttribute('type', 'text');
		content.setAttribute('name', 'searchstring' + count);
		content.setAttribute('id', 'searchstring' + count);
		content.setAttribute('size', '40');
		content.setAttribute('class', 'inputBox');
		
		col.appendChild(content);
		row.appendChild(col);
		root.appendChild(row);
		
		document.advancedSearch.queryCount.value = count;
	}
	
	function removeField(){
		var count = document.advancedSearch.queryCount.value;
		var root = document.getElementById('searchContent');
		if(count>1){
			root.removeChild(root.lastChild);
			count--;
			document.advancedSearch.queryCount.value = count;
		}
	}
</script>