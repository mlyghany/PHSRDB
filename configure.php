<?php
    define('DB_HOST', 'localhost');
    define('DB_PASSWORD', '');
    define('DB_USER', 'root');
    define('DB_DATABASE', 'phsrdb');
    $conn=mysql_pconnect(DB_HOST, DB_USER, DB_PASSWORD) or die ("Error connecting to DB_DATABASE");
    mysql_select_db(DB_DATABASE) or die ("Error: Cannot access $dbname database");
?>