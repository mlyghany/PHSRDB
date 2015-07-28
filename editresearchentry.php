<?php
session_start();
require_once("./configure.php");

$studyid = $_GET['studyid'];
$authorcount = $_POST['authorCount'];
$studydatabase = $_POST['studyDatabase'];
$studytitle = $_POST['studyTitle'];
$studypublished = $_POST['studyPublished'];

$researcher = $_SESSION['member'];
extract($researcher);

date_default_timezone_set("Asia/Manila");
$date =  date("Y-m-d");

$query = "UPDATE study SET study_title = '$studytitle', study_date = '$date', study_database = '$studydatabase', study_published = '$studypublished' WHERE study_id = '$studyid'";
$result = mysql_query($query) or die("Query Failed!");

$query = "DELETE FROM study_author WHERE study_id = '$studyid'";
$result = mysql_query($query) or die("Query Failed");

for($i=1; $i<=$authorcount; $i++) {
    $studyauthor = $_POST['study' . $i];

    $query = "INSERT INTO study_author (study_id, author_id) VALUES ('$studyid', '$studyauthor')";
    $result = mysql_query($query) or die("Query Failed");
}

if($studypublished == 'Y') {
    $query = "DELETE from study_published WHERE study_id = '$studyid'";
    $result = mysql_query($query) or die("Query Failed");

    $studypublication = $_POST['studyPublication'];
    $studyyearpublished = $_POST['studyYearPublished'];
    $studyvolumenumber = $_POST['studyVolumeNumber'];
    $studypagesinclusive = $_POST['studyPagesInclusive'];

    $query = "INSERT into study_published (study_id, study_publication, study_volumenumber, study_pagesinclusive, study_yearpublished) VALUES ('$studyid', '$studypublication', '$studyvolumenumber', '$studypagesinclusive', '$studyyearpublished')";
    $result = mysql_query($query) or die("Query Failed!");
}
else {
    $studytype = $_POST['studyType'];
    $studyyearcompleted = $_POST['studyYearCompleted'];
    $librarycount = $_POST['libraryCount'];

    $query = "DELETE FROM study_library WHERE study_id = '$studyid'";
    $result = mysql_query($query) or die("Query Failed");
    for($i=1; $i<=$librarycount; $i++) {
        $studylibrary = $_POST['library' . $i];

        $query = "INSERT INTO study_library (study_id, library_id) VALUES ('$studyid', '$studylibrary')";
        $result = mysql_query($query) or die("Query Failed!");
    }

    $query = "UPDATE study_unpublished SET study_type = '$studytype', study_yearcompleted = '$studyyearcompleted' WHERE study_id = '$studyid'";
    $result = mysql_query($query) or die("Query Failed");

}
header("location: viewresearch.php?studyid=$studyid&studydatabase=$studydatabase");
?>