<?php $pagetitle = 'Add Informant for the Study'; 
if($_POST['contentTrigger']) {
    $contentFlag = $_POST['contentTrigger'];
}
else {
    $contentFlag = "Existing";
}	
?>

<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <h1><center><?php echo $pagetitle;?></h1>
    <table width="600px" style="margin-left: 50px; text-align: left;">
        <tr>
            <td>
                <center>
                    <form name="addInformantTrigger" id="addInformantTrigger" method="post" action="">
                        <input type="radio" name="contentTrigger" value="Existing" onclick="submit()" <?php if($contentFlag == "Existing") echo "checked"; ?>>Existing Informant
                        <input type="radio" name="contentTrigger" value="New" onclick="submit()" <?php if($contentFlag == "New") echo "checked"; ?>>New Informant
                    </form>
                </center>
            </td>
        </tr>
    </table>
    <?php
    if($contentFlag == "Existing") {
        $query = "SELECT * FROM informant";
        $result = mysql_query($query) or die("Query Failed");

        if($result) {
            echo("<table width='400px' align='center' border='1'>");
            echo("<tr>");
            echo("<th>&nbsp;</th>");
            echo("<th>Last Name</th>");
            echo("<th>First Name</th>");
            echo("<th>Middle Initial</th>");
            echo("</tr>");
            while($informant = mysql_fetch_array($result, MYSQL_ASSOC)) {
                extract($informant);
                echo("<tr>");
                echo("<td><a href='addexistinginformantprocess.php?studyid=$studyid&informantid=$informant_id'>Add</a></td>");
                echo("<td id='lastname$informant_id'>$informant_lastname</td>");
                echo("<td id='firstname$informant_id'>$informant_firstname</td>");
                echo("<td id='mi$informant_id'>$informant_mi</td>");
                echo("</tr>");
            }
            echo("</table>");
        }
    }
    else {
        ?>
    <form name="addInformant" id="addInformant" method="post" action='./addnewinformantprocess.php?studyid=<?php echo($studyid); ?>'>
        <table width="600px" style="margin-left: 50px; text-align: left;">
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
                <td width="200px">
                    <table>
                        <tbody  id="gathererContent">
                        <input type="hidden" name="gathererCount" id="gathererCount" />
                        </tbody>
                    </table>

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

