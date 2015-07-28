<?php
	//start session
	session_start();
	
	//connect to the database
	require_once("./configure.php");
	require("./clean.php");
	
	//clean all data given
	$username = clean($_POST['username']);
	$password = clean($_POST['pword']);
	
	if($username == '' || $password == ''){
		$errflag = true;
	}
	
	if($errflag){
		session_write_close();
		header("location: ./main.php");
		exit();
	}
	
	$password = md5($password);
	
	$query = "SELECT * FROM members where member_username='$username' AND member_password='$password'";
	$result = mysql_query($query);
	
	if($result){
		if(mysql_num_rows($result) == 1){
			session_regenerate_id();
			$member = mysql_fetch_array($result, MYSQL_ASSOC);
			$_SESSION['member'] = $member;
		
			session_write_close();
			header("location: ./login_success.php");
			exit();
		}
		else{
			header("location: ./login_failed.php");
			exit();
		}
	}
	else{
		die("Query failed!");
	}
?>
		
	