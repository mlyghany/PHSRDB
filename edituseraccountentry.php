<?php
session_start();

require_once("./configure.php");
//define all variables
$researcherid = $_POST['researcherid'];
$memberid = $_POST['memberid'];
$username = $_POST['username'];
$email = $_POST['email'];
$title = $_POST['title'];
$firstname = $_POST['firstname'];
$lastname = $_POST['lastname'];
$middleinitial = $_POST['middleinitial'];
$sex = $_POST['sex'];
$birthday = $_POST['birthday'];
$address = $_POST['address'];
$location = $_POST['location'];
$occupation = $_POST['occupation'];
$workaddress = $_POST['workaddress'];

date_default_timezone_set("Asia/Manila");
$date =  date("Y-m-d");

$query1 = "UPDATE researcher SET researcher_lastname='$lastname', researcher_firstname = '$firstname', researcher_mi = '$middleinitial', researcher_username = '$username', researcher_email = '$email', researcher_title = '$title', researcher_sex = '$sex', researcher_birthday = '$birthday', researcher_address = '$address', researcher_location = '$location', researcher_occupation = '$occupation', researcher_workAddress = '$workaddress' WHERE researcher_id = '$researcherid'";
$query2 = "UPDATE members SET member_lastname = '$lastname', member_firstname = '$firstname', member_middleinitial = '$middleinitial', member_username = '$username', member_email = '$email' WHERE member_id = '$memberid'";

$result1= mysql_query($query1)
    or die("Query Failed! 1");

$result2= mysql_query($query2)
    or die("Query Failed! 2");

$query3 = "SELECT * FROM members WHERE member_id = '$memberid'";
$result3 = mysql_query($query3) or die("Query Failed!");

$_SESSION['member'] = mysql_fetch_array($result3);


if($result1 &&  result2) {
    header("location: ./accounteditsuccess.php");
}
else {
    header("location: ");
}
?>
