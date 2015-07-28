<?php

require_once("./configure.php");

$id = $_GET['id'];

date_default_timezone_set("Asia/Manila");
$date =  date("Y-m-d");

$query = "UPDATE researcher SET researcher_approveFlag='A', researcher_approveDate='$date' WHERE researcher_id=$id";
$result = mysql_query($query) or die("Query failed");

if($result){
	
	$query2 = "SELECT * from researcher WHERE researcher_id=$id";
	$result2 = mysql_query($query2) or die("Query failed");
	
	
	if($result2){
		$researcher = mysql_fetch_array($result2);
		extract($researcher);
	
		if(mysql_num_rows($result2) == 1){
			$query3 = "INSERT into members (member_username, member_password, member_firstname, member_lastname, member_middleinitial, member_email, member_since, member_type) VALUES ('$researcher_username', '$researcher_password', '$researcher_firstname', '$researcher_lastname', '$researcher_mi', '$researcher_email', '$date', 'researcher')";
			$result3 = mysql_query($query3);
			
			if($result3){
				header("location: ./memberapproved.php");
				exit();
			}
			else{
				die("Query Failed!");
				exit();
			}
			
		}
	}
	
}

?>