<?php
session_start();
require_once("./configure.php");

$authorcount = $_POST['authorCount'];
$studydatabase = $_POST['studyDatabase'];
$studytitle = $_POST['studyTitle'];
$studypublished = $_POST['studyPublished'];

$researcher = $_SESSION['member'];
extract($researcher);

date_default_timezone_set("Asia/Manila");
$date =  date("Y-m-d");

$query = "INSERT INTO study (study_title, study_date, study_database, study_published) VALUES ('$studytitle', '$date', '$studydatabase', '$studypublished')";
$result = mysql_query($query) or die("Query Failed!");

$studyid = mysql_insert_id();

$query = "INSERT INTO study_researcher (study_id, researcher_id) VALUES ('$studyid', '$member_id')";
$result = mysql_query($query) or die("Query Failed!");


for($i=1; $i<=$authorcount; $i++) {
    $studyauthor = $_POST['study' . $i];

    $query = "INSERT INTO study_author (study_id, author_id) VALUES ('$studyid', '$studyauthor')";
    $result = mysql_query($query) or die("Query Failed");
}

if($studypublished == 'Y') {
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

    for($i=1; $i<=$librarycount; $i++) {
        $studylibrary = $_POST['library' . $i];

        $query = "INSERT INTO study_library (study_id, library_id) VALUES ('$studyid', '$studylibrary')";
        $result = mysql_query($query) or die("Query Failed!");

    }

    $query = "INSERT INTO study_unpublished (study_id, study_type, study_yearcompleted) VALUES ('$studyid', '$studytype', '$studyyearcompleted')";
    $result = mysql_query($query) or die("Query Failed");

}

header("location: viewresearch.php?studyid=$studyid&studydatabase=$studydatabase");

?>