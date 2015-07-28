<?php
require_once("configure.php");

$studyid = $_GET['studyid'];

$informantid = $_GET["informantid"];
$callby = $_GET['callby'];
$informantlastname = $_POST['informantLastName'];
$informantfirstname = $_POST['informantFirstName'];
$informantmi = $_POST['informantMI'];
$informantaddress = $_POST['informantAddress'];
$informantbirthday = $_POST['informantBirthday'];
$informantsex = $_POST['informantSex'];
$informantoccupation = $_POST['informantOccupation'];
$informanteducationalattainment = $_POST['informantEducationalAttainment'];
$informantmaritalstatus = $_POST['informantMaritalStatus'];
$informantreligion = $_POST['informantReligion'];
$informanttype = $_POST['informantType'];
$informanthealingpractice = $_POST['informantHealingPractice'];
$informantlengthofexperience = $_POST['informantLengthOfExperience'];
$informantcasehistory = $_POST['informantCaseHistory'];
$informantfamily = $_POST['informantFamily'];
$informantdategathered = $_POST['informantDateGathered'];

$query = "UPDATE informant SET informant_lastname = '$informantlastname', informant_firstname = '$informantfirstname',
informant_mi = '$informantmi', informant_address = '$informantaddress', informant_birthday = '$informantbirthday', informant_sex = '$informantsex',
informant_occupation = '$informantoccupation', informant_educationalattainment = '$informanteducationalattainment', informant_maritalstatus = '$informantmaritalstatus',
informant_religion = '$informantreligion', informant_type = '$informanttype', informant_healingpractice = '$informanthealingpractice',
informant_lengthofexperience = '$informantlengthofexperience', informant_casehistory = '$informantcasehistory', informant_familymembers = '$informantfamily',
informant_dategathered = '$informantdategathered' WHERE informant_id = '$informantid'";
$result = mysql_query($query) or die("Query Failed!");

$gatherercount = $_POST['gathererCount'];

$query = "DELETE FROM informant_gatherer WHERE informant_id = '$informantid'";
$result = mysql_query($query) or die("Query Failed");
for($i=1; $i<=$gatherercount; $i++) {
    $gathererid = $_POST['gatherer' . $i];
    if($gathererid){
    $query = "INSERT INTO informant_gatherer (informant_id, gatherer_id) VALUES ('$informantid', '$gathererid')";
    $result = mysql_query($query) or die("Query Failed");
    }
}

header("location: ./viewinformant.php?informantid=$informantid&studyid=$studyid");

?>