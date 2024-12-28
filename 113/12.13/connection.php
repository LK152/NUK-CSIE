<?php
$location = "localhost";
$account = "root";
$password = "90134";

if (isset($location) && isset($account) && isset($password)) {
    $link = @mysqli_connect($location, $account, $password);
    if ($link) {
    } else {
        echo "連接失敗: " . mysqli_connect_error();
    }
}
