<?php
	require_once("./configure.php");
	
	//define all variables
	$username = $_POST['username'];
	$password = $_POST['password'];
	$retype = $_POST['retype'];
	$email = $_POST['email'];
	$title = mb_convert_case($_POST['title'], MB_CASE_TITLE, "UTF-8");
	$firstname = mb_convert_case($_POST['firstname'], MB_CASE_TITLE, "UTF-8");
	$lastname = mb_convert_case($_POST['lastname'], MB_CASE_TITLE, "UTF-8");
	$middleinitial = ucfirst($_POST['middleinitial']);
	$sex = $_POST['sex'];
	$birthday = $_POST['birthday'];
	$address = $_POST['address'];
	$location = mb_convert_case($_POST['location'], MB_CASE_TITLE, "UTF-8");
	$occupation = mb_convert_case($_POST['occupation'], MB_CASE_TITLE, "UTF-8");
	$workaddress = mb_convert_case($_POST['workaddress'], MB_CASE_TITLE, "UTF-8");
	
	date_default_timezone_set("Asia/Manila");
	$date =  date("Y-m-d");
	
	$query="INSERT INTO researcher (researcher_lastname, researcher_firstname, researcher_mi, researcher_username, researcher_password, researcher_retype, researcher_email, researcher_title, researcher_sex, researcher_birthday, researcher_address, researcher_location, researcher_occupation, researcher_workAddress, researcher_approveFlag, researcher_requestDate) VALUES ('$lastname', '$firstname', '$middleinitial', '$username', '" . md5($password) . "', '$password', '$email', '$title', '$sex', '$birthday', '$address', '$location', '$occupation', '$workaddress', 'D', '$date')";
	
	$result= mysql_query($query)
		or die("Query Failed!");
	
	if($result){
		header("location: ./accountcreatesuccess.php");
	}
	
?>
