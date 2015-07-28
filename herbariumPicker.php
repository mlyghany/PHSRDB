<?php $pagetitle = 'Add Herbarium for the Study'; 
if($_POST['contentTrigger']) {
    $contentFlag = $_POST['contentTrigger'];
}
else {
    $contentFlag = "Existing";
}	
?>
<?php include('header.inc'); ?>
<?php include('configure.php'); ?>

<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <center><h1><?php echo $pagetitle;?></h1>
        <table width="500px" style="margin-left: 50px; text-align: left;">
            <tr>
                <td>
                    <center>
                        <form name="addHerbariumTrigger" id="addHerbariumTrigger" method="post" action="">
                            <input type="radio" name="contentTrigger" value="Existing" onclick="submit()" <?php if($contentFlag == "Existing") echo "checked"; ?>>Existing Herbarium
                            <input type="radio" name="contentTrigger" value="New" onclick="submit()" <?php if($contentFlag == "New") echo "checked"; ?>>New Herbarium
                        </form>
                    </center>
                </td>
            </tr>
        </table>
        <?php
        if($contentFlag == "Existing") {
            $query = "SELECT * FROM herbarium";
            $result = mysql_query($query) or die("Query Failed");

            if($result) {
                echo("<table width='400px' align='center' border='1'>");
                echo("<tr>");
                echo("<th>&nbsp;</th>");
                echo("<th>Scientific Name</th>");
                echo("</tr>");
                while($informant = mysql_fetch_array($result, MYSQL_ASSOC)) {
                    extract($informant);
                    echo("<tr>");
                    echo("<td><a href='javascript: pick($herbarium_id)'>Add</a></td>");
                    echo("<td id='scientificname$herbarium_id'>$herbarium_scientificname</td>");
                    echo("</tr>");
                }
                echo("</table>");
            }
        }
        else {
            ?>
        <form id="addHerbarium" name="addHerbarium" method="post" action='addnewherbariumprocess.php?studyid=<?php echo($studyid); ?>&callby=picker'>
            <table width="600px" style="margin-left: 50px; text-align: left;" >
                <tr>
                <td width="200px">Scientific Name</td>
                <td width="400px"><input type="text" name="scientificName" id="scientificName" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px"><p>Other Name(s)</p>
                        <input type="button" value="+" onclick="addName()" />
                        <input type="button" value="-" onclick="removeName()" />
                    </td>
                    <td width="400px"><table width="400px" id="otherTable" >
                            <tr><td><input type="hidden" name ="otherNum" id="otherNum" value=""/></td></tr>
                            <tr>
                                <td width="133px">&nbsp;Name</td>
                                <td width="133px">&nbsp;Language </td>
                                <td width="133px">&nbsp;Type</td>
                            </tr>
                        </table>
                    </td>
                </tr>
                <tr>
                    <td width="200px">Field Number</td>
                    <td width="400px"><input type="text" name="fieldNumber" id="fieldNumber" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px"><p>Herbarium Number</p></td>
                    <td width="400px"><input type="text" name="herbariumNumber" id="herbariumNumber" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Collector</td>
                    <td width="400px"><input type="text" name="collector" id="collector" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Collector Number</td>
                    <td width="400px"><input type="text" name="collectorNumber" id="collectorNumber" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Geographic Area of Collection</td>
                    <td width="400px"><input type="text" name="geographicAreaOfCollection" id="geographicAreaOfCollection" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Latitude</td>
                    <td width="400px"><input type="text" name="latitude" id="latitude" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Habitat</td>
                    <td width="400px"><input type="text" name="habitat" id="habitat" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Altitude Above Sea Level</td>
                    <td width="400px"><input type="text" name="altitudeAboveSeaLevel" id="altitudeAboveSeaLevel" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Habit</td>
                    <td width="400px"><input type="text" name="habit" id="habit" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Height</td>
                    <td width="400px"><input type="text" name="height" id="height" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Diameter of Trunk</td>
                    <td width="400px"><input type="text" name="diameterOfTrunk" id="diameterOfTrunk" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Flower</td>
                    <td width="400px"><input type="text" name="flower" id="flower" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Fruit</td>
                    <td width="400px"><input type="text" name="fruit" id="fruit" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">&nbsp;</td>
                    <td width="400px"><input type="text" name="specimenVoucherIdentifierFirstName" id="specimenVoucherIdentifierFirstName" value="First Name" onfocus="clearText(this)" onblur="clearText(this)" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Specimen Voucher Identifier</td>
                    <td width="400px"><input type="text" name="specimenVoucherIdentifierMiddleName" id="specimenVoucherIdentifierMiddleName" value="Middle Initial" onfocus="clearText(this)" onblur="clearText(this)" class="inputBox" size="10"/></td>
                </tr>
                <tr>
                    <td width="200px">&nbsp;</td>
                    <td width="400px"><input type="text" name="specimenVoucherIdentifierSurname" id="specimenVoucherIdentifierSurname" value="Last Name" onfocus="clearText(this)" onblur="clearText(this)" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Date of Identification of Specimen Voucher</td>
                    <td width="400px"><input  type="text" name="dateOfIdentificationofSpecimenVoucher" id="dateOfIdentificationofSpecimenVoucher" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td width="200px">Specimen Voucher Kept at</td>
                    <td width="400px"><input type="text" name="specimenVoucherKeptAt" id="specimenVoucherKeptAt" class="inputBox" size="40"/></td>
                </tr>
                <tr>
                    <td colspan="2"><center><input type="submit" value="Add Herbarium" /></center></td>
                </tr>
            </table>
        </form>
        <?php } ?>
    </center>

</div>

<script type="text/javascript">
    function clearText(field){
        if (field.defaultValue == field.value) field.value = '';
        else if (field.value == '') field.value = field.defaultValue;
    }

    function addName(){

        var number = document.getElementById('otherNum');

        var num = number.value;
        num++;
        number.value = num;

        var main = document.getElementById('otherTable');
        var t = document.createElement('table');
        var tr = document.createElement('tr');
        var list = document.createElement('select');
        var values = new Array('Local', 'Foreign', 'Common');
        var option = new Array(3);
        var input = new Array(2);
        var td = new Array(3);

        for(var i = 0; i < 3; i++) {
            option[i] = document.createElement('option');
            option[i].text = values[i];
            list.options[i] = option[i];
            td[i] = document.createElement('td');
            td[i].setAttribute('width' , '100px');
            input[i] = document.createElement('input');
            if(i < 2)td[i].appendChild(input[i]);
        }

        td[2].appendChild(list);
        tr.appendChild(td[0]);
        tr.appendChild(td[1]);
        tr.appendChild(td[2]);

        input[0].id = input[0].name = "otherName" + num;
        input[1].id = input[1].name = "language" + num;
        input[0].setAttribute("class", "inputBox");
        input[1].setAttribute("class", "inputBox");
        list.setAttribute("class", "inputBox");
        list.id = list.name = "type" + num;

        main.appendChild(tr);
    }

    function removeName(){
        var number = document.getElementById('otherNum');
        var num = number.value;
        if(num > 0){
            num--;
            number.value = num;
            var main = document.getElementById('otherTable');
            main.removeChild(main.lastChild);
        }
    }

    function pick(herbarium_id){
        var name = document.getElementById('scientificname' + herbarium_id).lastChild.nodeValue;

        var parentWindow = opener.document;
        var root = parentWindow.getElementById('herbariumContent');
        var herbariumCount = parentWindow.addMaterial.herbariumCount.value;

        herbariumCount++;
        var row = document.createElement('tr');
        var col = document.createElement('td');

        var content = document.createTextNode(name);

        col.appendChild(content);

        content = document.createElement('input');
        content.setAttribute('type', 'hidden');
        content.setAttribute('name', "materialHerbarium" + herbariumCount);
        content.setAttribute('id' ,  "materialHerbarium" + herbariumCount);
        content.setAttribute('value', herbarium_id);

        col.appendChild(content);
        row.appendChild(col);

        col = document.createElement('td');
        content = document.createElement('input');
        content.setAttribute('type', 'text');
        content.setAttribute('name',"materialPartUsed" + herbariumCount);
        content.setAttribute('id' , "materialPartUsed" + herbariumCount);
        content.setAttribute('class', 'inputBox');
        content.setAttribute('size' , '13');

        alert(content.name);

        col.appendChild(content);
        row.appendChild(col);

        root.appendChild(row);

        col = document.createElement('td');
        content = document.createElement('input');
        content.setAttribute('type', 'text');
        content.setAttribute('name',"materialGathering" + herbariumCount);
        content.setAttribute('id' , "materialGathering" + herbariumCount);
        content.setAttribute('class', 'inputBox');
        content.setAttribute('size' , '13');

        alert(content.name);

        col.appendChild(content);
        row.appendChild(col);

        root.appendChild(row);

        col = document.createElement('td');
        content = document.createElement('input');
        content.setAttribute('type', 'text');
        content.setAttribute('name',"materialPostharvest" + herbariumCount);
        content.setAttribute('id' , "materialPostharvest" + herbariumCount);
        content.setAttribute('class', 'inputBox');
        content.setAttribute('size' , '13');

        alert(content.name);

        col.appendChild(content);
        row.appendChild(col);

        root.appendChild(row);

        parentWindow.addMaterial.herbariumCount.value = herbariumCount;
    }
</script>

