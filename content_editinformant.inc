<?php $pagetitle = 'Edit Informant';
$informantid = $_GET['informantid'];
$studyid= $_GET['studyid'];
$query = "SELECT * FROM informant WHERE informant_id ='$informantid'";
$result = mysql_query($query) or die("Query Failed!");
$informant = mysql_fetch_array($result, MYSQL_ASSOC);
if($result) extract($informant);
?>

<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <h1><?php echo $pagetitle . " "; ?></h1>
    <form name="addInformant" id="addInformant" method="post" action="./editinformantprocess.php?informantid=<?php echo($informantid); ?>&studyid=<?php echo($studyid); ?>">
        <table width="600px" style="margin-left: 50px; text-align: left;">
            <tr>
                <td width="200px">Last Name</td>
                <td width="400px"><input type="text" name="informantLastName" size="40" class="inputBox" value="<?php if($informant_lastname != "") echo($informant_lastname); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">First Name</td>
                <td width="400px"><input type="text" name="informantFirstName" size="40" class="inputBox" value="<?php if($informant_firstname != "") echo($informant_firstname); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Middle Initial</td>
                <td width="400px"><input type="text" name="informantMI" size="4" class="inputBox" value="<?php if($informant_mi != "") echo($informant_mi); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Address</td>
                <td width="400px"><input type="text" name="informantAddress" size="40" class="inputBox" value="<?php if($informant_address != "") echo($informant_address); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Birthday</td>
                <td width="400px"><input type="text" name="informantBirthday" size="40" class="inputBox" value="<?php if($informant_birthday != "0000-00-00") echo($informant_birthday); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Sex</td>
                <td width="400px">
                    <select  name="informantSex" class="inputBox">
                        <option value="M" <?php if($informant_sex == "M") echo "selected"?>>Male</option>
                        <option value="F" <?php if($informant_sex == "F") echo "selected"?>>Female</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td width="200px">Occupation/Livelihood</td>
                <td width="400px"><input type="text" name="informantOccupation" size="40" class="inputBox" value="<?php if($informant_occupation != "") echo($informant_occupation); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Educational Attainment</td>
                <td width="400px"><textarea rows="2" cols="30" name="informantEducationalAttainment" class="inputBox"><?php if($informant_educationalattainment != "") echo($informant_educationalattainment); ?></textarea></td>
            </tr>
            <tr>
                <td width="200px">Marital Status</td>
                <td width="400px">
                    <select  name="informantMaritalStatus" class="inputBox">
                        <option value="Single" <?php if($informant_maritalstatus == "Single") echo "selected"?>>Single</option>
                        <option value="Married" <?php if($informant_maritalstatus == "Married") echo "selected"?>>Married</option>
                        <option value="Divorced" <?php if($informant_maritalstatus == "Divorced") echo "selected"?>>Divorced</option>
                        <option value="Widowed" <?php if($informant_maritalstatus == "Widowed") echo "selected"?>>Widowed</option>
                    </select>
                </td>
            </tr>
            <tr>
                <td width="200px">Religion</td>
                <td width="400px"><input type="text" name="informantReligion" size="40" class="inputBox" value="<?php if($informant_religion != "") echo($informant_religion); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Type of Informant</td>
                <td width="400px"><input type="text" name="informantType" size="40" class="inputBox" value="<?php if($informant_type != "") echo($informant_type); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Type of Healing Practice</td>
                <td width="400px"><input type="text" name="informantHealingPractice" size="40" class="inputBox" value="<?php if($informant_healingpractice != "") echo($informant_healingpractice); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Length of Experience</td>
                <td width="400px"><input type="text" name="informantLengthofExperience" size="40" class="inputBox" value="<?php if($informant_lengthofexperience != "") echo($informant_lengthofexperience); ?>"/></td>
            </tr>
            <tr>
                <td width="200px">Informant Case History</td>
                <td width="400px"><textarea rows="2" cols="30" name="informantCaseHistory" class="inputBox"><?php if($informant_casehistory != "") echo($informant_casehistory); ?></textarea></td>
            </tr>
            <tr>
                <td width="200px">Names of Immediate Family Members and Relationship</td>
                <td width="400px"><textarea rows="2" cols="30" name="informantFamily" class="inputBox"><?php if($informant_familymembers != "") echo($informant_familymembers); ?></textarea></td>
            </tr>
            <tr>
                <td width="200px">Gatherer <input type="button" value="+" onclick="showGathererPicker()" /></td>
                <td width="200px">
                    <table>
                        <tbody  id="gathererContent">
                            <?php
                            $i = 0;
                            $query = "SELECT * FROM informant_gatherer WHERE informant_id = '$informantid'";
                            $result = mysql_query($query) or die("Query Failed!");
                            while ($row = mysql_fetch_assoc($result)) {
                                $i++;
                                $gathererid = $row["gatherer_id"];
                                $query2 = "SELECT * FROM gatherer WHERE gatherer_id='$gathererid'";
                                $result2 = mysql_query($query2) or die("Query Failed!");
                                $gatherer = mysql_fetch_array($result2, MYSQL_ASSOC);
                                if($gatherer){
									extract($gatherer);
									echo"<tr name='informantGatherer" . $i . "' id='informantGatherer" . $i . "'>";
									echo"<input name='gatherer" . $i . "' id='gatherer" . $i . "' type='hidden' value='" . $gatherer_id . "'><td>";
									echo $gatherer_lastname . ", " . $gatherer_firstname;
									if($gatherer_mi != "") echo " " . $gatherer_mi . ".";
									echo"<input onclick='Javascript: removeGatherer(" . $i . ")' value='remove' type='button' id='remove" . $i . "'></td></tr>";
								}
                            }
                            echo"<input type='hidden' id='gathererCount' name='gathererCount' value='" . ($i) . "'/>"
                            ?>
                        </tbody>
                    </table>
                </td>
            </tr>
            <tr>
                <td width="200px">Date Gathered</td>
                <td width="400px"><input type="text" name="informantDateGathered" size="40" class="inputBox" value="<?php if($informant_dategathered != "0000-00-00") echo($informant_dategathered); ?>"/></td>
            </tr>
            <tr>
                <td colspan="2"><center><input type="submit" value="Edit Informant"/></center></td>
            </tr>
        </table>
    </form>
</div>

<script type="text/javascript">
    function showGathererPicker(){
        window.open("gathererPicker.php","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
    }

    function removeGatherer(gathererID){
        var table = document.getElementById("gathererContent");
        var gathererCount = document.getElementById("gathererCount");
        var tr = document.getElementById("informantGatherer" + gathererID);
        var count = gathererCount.value;
        table.removeChild(tr);

        for(var i = gathererID; i < count; i++){
            tr = document.getElementById("informantGatherer" + (i+1));
            var content = document.getElementById("study" + (i+1));
            var remove = document.getElementById("remove" + (i+1));

            content.setAttribute('name', "gatherer" + i);
            content.setAttribute('id', "gatherer" + i);
            remove.setAttribute('id', "remove" + i);

            tr.setAttribute('name', 'informantGatherer' + i);
            tr.setAttribute('id', 'informantGatherer' + i);
            remove.setAttribute('onclick', 'Javascript: removeGatherer(' + i + ')');
        }
        document.newResearch.gathererCount.value = (count-1);
    }
</script>

