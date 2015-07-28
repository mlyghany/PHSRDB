<?php

require_once("./configure.php");

$id = $_GET['id'];

date_default_timezone_set("Asia/Manila");
$date =  date("Y-m-d");

$query = "DELETE from researcher WHERE researcher_id=$id";
$result = mysql_query($query) or die("Query failed");

header("location: ./memberdenied.php");
?>