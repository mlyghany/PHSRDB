<?php
require_once("configure.php");

$studyid = $_GET['studyid'];
$indicationid = $_GET['indicationid'];
$indicationname = $_POST['indicationName'];
$indicationdescription = $_POST['indicationDescription'];
$indicationtype = $_POST['indicationType'];

$query = "UPDATE indication SET indication_name = '$indicationname', indication_description = '$indicationdescription',
        indication_type= '$indicationtype' WHERE indication_id = '$indicationid'";
$result = mysql_query($query) or die("Query Failed!");

if($indicationtype == "Medical") {
    $query = "DELETE from indication_medical WHERE indication_id = '$indicationid'";
    $result = mysql_query($query) or die("Query Failed");

    $indicationfullcourse = $_POST['indicationFullCourse'];
    $indicationcause = $_POST['indicationCause'];
    $indicationdiagnosis = $_POST['indicationDiagnosis'];
    $indicationtreatmentherb = $_POST['indicationTreatmentHerb'];
    $indicationtreatmentnonmat = $_POST['indicationTreatmentNonMat'];
    $indicationtreatmentwestern = $_POST['indicationTreatmentWestern'];

    $query = "INSERT into indication_medical (indication_id, indication_fullcourse, indication_cause, indication_materialtreatment, indication_nonmaterialtreatment, indication_westerntreatment, indication_diagnosis) VALUES ('$indicationid', '$indicationfullcourse' , '$indicationcause', '$indicationtreatmentherb' , '$indicationtreatmentnonmat', '$indicationtreatmentwestern', '$indicationdiagnosis')";
    $result = mysql_query($query) or die("Query Failed");
}
else {
    $indicationantidote = $_POST['indicationAntidote'];
    $query = "DELETE from indication_other WHERE indication_id = '$indicationid'";
    $result = mysql_query($query) or die("Query Failed");

    $query = "INSERT into indication_other (indication_id, indication_antidote) VALUES ('$indicationid', '$indicationantidote')";
    $result = mysql_query($query) or die("Query Failed!");
}

header("location: ./viewindication.php?indicationid=$indicationid&studyid=$studyid");
?>