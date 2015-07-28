<?php
$pagetitle = 'Edit Indication';
$indicationid = $_GET['indicationid'];
$studyid= $_GET['studyid'];
$query = "SELECT * FROM indication WHERE indication_id = '$indicationid'";
$result = mysql_query($query) or die("Query Failed");
if($result) {
    $indication = mysql_fetch_array($result, MYSQL_ASSOC);
    if($indication) extract($indication);
}
?>
<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <center><h1><?php echo($pagetitle); ?></h1></center>

    <form name="addIndication" id="addIndication" method="post" action="./editindicationprocess.php?indicationid=<?php echo($indicationid); ?>&studyid=<?php echo($studyid); ?>">
        <table id="indicationTable" width="600px" style="margin-left: 50px; text-align: left;">
            <thead>
                <tr>
                    <td width="200px">
									Type:
                    </td>

                    <td width="450px">
                        <select id="indicationType" name="indicationType" onChange="showContent()" class="inputBox">
                            <option value="Medical" <?php if($indication_type == "Medical") echo "selected"?>>Medical Indication</option>
                            <option value="Other" <?php if($indication_type == "Other") echo "selected"?>>Other Indication</option>
                        </select>
                    </td>
                </tr>
                <?php
                if($indication_type == "Medical"){
                $query = "SELECT * FROM indication_medical WHERE indication_id = '$indicationid'";
                $result = mysql_query($query) or die("Query Failed");
                if($result) {
                    $indication_medical = mysql_fetch_array($result, MYSQL_ASSOC);
                    if($indication_medical) extract($indication_medical);
                }}
                if($indication_type == "Other"){
                $query = "SELECT * FROM indication_other WHERE indication_id = '$indicationid'";
                $result = mysql_query($query) or die("Query Failed");
                if($result) {
                    $indication_other = mysql_fetch_array($result, MYSQL_ASSOC);
                    if($indication_other) extract($indication_other);
                }}
                ?>
                <tr>
                    <td width="200px">
									Name of Indication:
                    </td>

                    <td width="450px">
                        <input type="text" name="indicationName" size="33" class="inputBox" value="<?php echo($indication_name); ?>"/>
                    </td>
                </tr>
                <tr>
                    <td width="200px">
									Description:
                    </td>
                    <td width="450px">
                        <textarea cols="26" name="indicationDescription" class="inputBox"><?php echo($indication_description); ?></textarea>
                    </td>
                </tr>
            </thead>
            <tbody id="medicalIndication">
                <tr>
                    <td width="200px">Full Course:</td>
                    <td width="450px">
                        <textarea cols="26" name="indicationFullCourse" class="inputBox"><?php echo($indication_fullcourse); ?></textarea></td>
                </tr>
                <tr>
                    <td width="200px">Cause(s):</td>
                    <td width="450px"><textarea cols="26" name="indicationCause" class="inputBox"><?php echo($indication_cause); ?></textarea></td>
                </tr>
                <tr>
                    <td width="200px">How to arrive at diagnosis:</td>
                    <td width="450px"><textarea cols="26" name="indicationDiagnosis" class="inputBox"><?php echo($indication_diagnosis); ?></textarea></td>
                </tr>
                <tr>
                    <td width="200px">Treatment <br/> (Herbs and/or Other Material):</td>
                    <td width="450px">
                        <textarea cols="26" name="indicationTreatmentHerb" class="inputBox"><?php echo($indication_materialtreatment); ?></textarea></td>
                </tr>
                <tr>
                    <td width="200px">Treatment <br/>(Non-material):</td>
                    <td width="450px">
                        <textarea cols="26" name="indicationTreatmentNonMat" class="inputBox"><?php echo($indication_nonmaterialtreatment); ?></textarea></td>
                </tr>
                <tr>
                    <td width="200px">Treatment <br/>(Western Medicine):</td>
                    <td width="450px">
                        <textarea cols="26" name="indicationTreatmentWestern" class="inputBox"><?php echo($indication_westerntreatment); ?></textarea></td>
                </tr>
            </tbody>
            <tbody id="otherIndication">
                <tr>
                    <td width="200px">Antidote <br/> [if indication is as poison]:</td>
                    <td width="450px">
                        <textarea cols="26" name="indicationAntidote" class="inputBox"><?php echo($indication_antidote); ?></textarea></td>
                </tr>
            </tbody>
            <tr>
                <td colspan="2"><center><input type="submit" value="Edit Indication"></center></td>
            </tr>
        </table>
    </form>
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

</script>


