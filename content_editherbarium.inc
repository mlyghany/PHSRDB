<?php
$pagetitle = 'Edit Herbarium';
require_once("configure.php");
$herbariumid = $_GET['herbariumid'];
$studyid= $_GET['studyid'];
$query = "SELECT * FROM herbarium WHERE herbarium_id ='$herbariumid'";
$result = mysql_query($query) or die("Query Failed!");
$herbarium = mysql_fetch_array($result, MYSQL_ASSOC);
extract($herbarium);
?>

<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
   <center><h1><?php echo $pagetitle;?></h1></center>
    <form id="addHerbarium" name="addHerbarium" method="post" action="editherbariumprocess.php?herbariumid=<?php echo($herbariumid);?>&studyid=<?php echo($studyid); ?>">
        <table width="600px" style="margin-left: 50px; text-align: left;">
            <tr>
                <td width="200px">Scientific Name</td>
                <td width="400px"><input type="text" name="scientificName" id="scientificName" class="inputBox" size="40" value="<?php if($herbarium_scientificname != "") echo($herbarium_scientificname); ?>"/></td>
            </tr>
            <tr>
                <td width="200px"><p>Other Name(s)</p>
                    <input type="button" value="+" onclick="addName()" />
                    <input type="button" value="-" onclick="removeName()" />
                </td>
                <td width="400px"><table width="400px"><tbody id="otherTable" >
                        <tr>
                            <td width="133px">&nbsp;Name</td>
                            <td width="133px">&nbsp;Language </td>
                            <td width="133px">&nbsp;Type</td>
                        </tr>
		<?php
			$query2 = "SELECT * FROM herbarium_othername WHERE herbarium_id='$herbariumid'" ;
			$result2 = mysql_query($query2) or die("Query Failed!");
                        $count = 0;

			if(mysql_num_rows($result2) > 0){

				while($herbarium_othername = mysql_fetch_array($result2, MYSQL_ASSOC)){
					extract($herbarium_othername);
                                        $count++;
                                        echo("<tr id='other" . $count . "'><td width='133px'><input name='otherName" . $count . "' id='otherName" . $count . "' class='inputBox' value='" . $othername_name . "'/></td>");
                                        echo("<td width='133px'><input name='language" . $count . "' id='language" . $count . "' class='inputBox' value='" . $othername_language . "'/></td>");
                                        echo("<td width='133px'><select class='inputBox' name='type" . $count . "' id='type" . $count . "'>");
                                        echo "<option ";
                                        if($othername_type == 'Local') echo "selected";
                                        echo">Local</option><option ";
                                        if($othername_type == 'Foreign') echo "selected";
                                        echo ">Foreign</option>";
                                        echo "<option ";
                                        if($othername_type == 'Common') echo "selected";
                                        echo ">Common</option></select></td></tr>";
                                }
                                echo "<tr><td><input type='hidden' name ='otherNum' id='otherNum' value='" . $count . "'/></td></tr>";
			}
			?>
                        </tbody></table>
                </td>
            </tr>
            <tr>
                <td width="200px">Field Number</td>
                <td width="400px"><input type="text" name="fieldNumber" id="fieldNumber" class="inputBox" size="40" value="<?php if($herbarium_fieldnumber != "") echo($herbarium_fieldnumber); ?>"/></td>
            </tr>
            <tr>
                <td width="200px"><p>Herbarium Number</p></td>
                <td width="400px"><input type="text" name="herbariumNumber" id="herbariumNumber" class="inputBox" size="40" value="<?php if($herbarium_number != "") echo($herbarium_number); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Collector</td>
                <td width="400px"><input type="text" name="collector" id="collector" class="inputBox" size="40" value="<?php if($herbarium_collector != "") echo($herbarium_collector); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Collector Number</td>
                <td width="400px"><input type="text" name="collectorNumber" id="collectorNumber" class="inputBox" size="40" value="<?php if($herbarium_collectornumber != "") echo($herbarium_collectornumber); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Geographic Area of Collection</td>
                <td width="400px"><input type="text" name="geographicAreaOfCollection" id="geographicAreaOfCollection" class="inputBox" size="40" value="<?php if($herbarium_geographicarea != "") echo($herbarium_geographicarea); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Latitude</td>
                <td width="400px"><input type="text" name="latitude" id="latitude" class="inputBox" size="40" value="<?php if($herbarium_latitude != "") echo($herbarium_latitude); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Habitat</td>
                <td width="400px"><input type="text" name="habitat" id="habitat" class="inputBox" size="40" value="<?php if($herbarium_habitat != "") echo($herbarium_habitat); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Altitude Above Sea Level</td>
                <td width="400px"><input type="text" name="altitudeAboveSeaLevel" id="altitudeAboveSeaLevel" class="inputBox" size="40" value="<?php if($herbarium_altitude != "") echo($herbarium_altitude); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Habit</td>
                <td width="400px"><input type="text" name="habit" id="habit" class="inputBox" size="40" value="<?php if($herbarium_habit != "") echo($herbarium_habit); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Height</td>
                <td width="400px"><input type="text" name="height" id="height" class="inputBox" size="40" value="<?php if($herbarium_height != "") echo($herbarium_height); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Diameter of Trunk</td>
                <td width="400px"><input type="text" name="diameterOfTrunk" id="diameterOfTrunk" class="inputBox" size="40" value="<?php if($herbarium_diameter != "") echo($herbarium_diameter); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Flower</td>
                <td width="400px"><input type="text" name="flower" id="flower" class="inputBox" size="40" value="<?php if($herbarium_flower != "") echo($herbarium_flower); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Fruit</td>
                <td width="400px"><input type="text" name="fruit" id="fruit" class="inputBox" size="40" value="<?php if($herbarium_fruit != "") echo($herbarium_fruit); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">&nbsp;</td>
                <td width="400px"><input type="text" name="specimenVoucherIdentifierFirstName" id="specimenVoucherIdentifierFirstName" value="<?php if($herbarium_identifierfirstname != "") echo($herbarium_identifierfirstname); else echo"First Name"?>" onfocus="clearText(this)" onblur="clearText(this)" class="inputBox" size="40"/></td>
            </tr>
            <tr>
                <td width="200px">Specimen Voucher Identifier</td>
                <td width="400px"><input type="text" name="specimenVoucherIdentifierMiddleName" id="specimenVoucherIdentifierMiddleName" value="<?php if($herbarium_identifiermi != "") echo($herbarium_identifiermi); else echo"Middle Initial"?>" onfocus="clearText(this)" onblur="clearText(this)" class="inputBox" size="10"/></td>
            </tr>
            <tr>
                <td width="200px">&nbsp;</td>
                <td width="400px"><input type="text" name="specimenVoucherIdentifierSurname" id="specimenVoucherIdentifierSurname" value="<?php if($herbarium_identifierlastname != "") echo($herbarium_identifierlastname); else echo"Last Name"?>" onfocus="clearText(this)" onblur="clearText(this)" class="inputBox" size="40"/></td>
            </tr>
            <tr>
                <td width="200px">Date of Identification of Specimen Voucher</td>
                <td width="400px"><input  type="text" name="dateOfIdentificationOfSpecimenVoucher" id="dateOfIdentificationOfSpecimenVoucher" class="inputBox" size="40" value="<?php if($herbarium_dateofidentification != "0000-00-00") echo($herbarium_dateofidentification); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Specimen Voucher Kept at</td>
                <td width="400px"><input type="text" name="specimenVoucherKeptAt" id="specimenVoucherKeptAt" class="inputBox" size="40" value="<?php if($herbarium_specimenkeptat != "") echo($herbarium_specimenkeptat); ?>"/></td>
            </tr>
            <tr>
                <td colspan="2"><center><input type="submit" value="Edit Herbarium" /></center></td>
            </tr>
        </table>
    </form>
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
        tr.id = "other" + num;
        for(var i = 0; i < 3; i++) {
            option[i] = document.createElement('option');
            option[i].text = values[i];
            list.options[i] = option[i];
            td[i] = document.createElement('td');
            td[i].setAttribute('width' , '133px');
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
            var main = document.getElementById('otherTable');
            var tr = document.getElementById('other' + num);
            main.removeChild(tr);
            num--;
            number.value = num;
        }
    }
</script>

