<?php
require_once("./configure.php");
//define all variables
$researcherid = $_POST['researcherid'];
$memberid = $_POST['memberid'];
$password = $_POST['newpassword'];

date_default_timezone_set("Asia/Manila");
$date =  date("Y-m-d");
$query1 = "UPDATE researcher SET researcher_password = '" . md5($password) . "', researcher_retype = '$password' WHERE researcher_id = '$researcherid'";
$query2 = "UPDATE members SET member_password = '" . md5($password) . "' WHERE member_id = '$memberid'";

$result1= mysql_query($query1)
    or die("Query Failed! 1");

$result2= mysql_query($query2)
    or die("Query Failed! 2");

if($result1 &&  result2) {
    header("location: ./changepasswordsuccessful.php");
}
else {
    header("location: ");
}
?>
