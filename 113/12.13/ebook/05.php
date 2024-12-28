<?php
$location = "localhost";
$account = "root";
$password = "90134";

if (isset($location) && isset($account) && isset($password)) {
    $link = @mysqli_connect($location, $account, $password);
    if ($link) {
        echo"hi";
    } else {
        echo "連接失敗: " . mysqli_connect_error();
    }
}

$filename = $_GET['id'];
$filepasswd = $_GET['name'];

echo "id: " . $filename;
echo "<br>pwd: " . $filepasswd;
?>

<?php
$database = "school";
$select_db = @mysqli_select_db($link, $database);
if (!$select_db) {
    echo "資料庫選擇失敗";
} else {
    $sql_query = "select * from usr where userid = '" . $filename . "' and passwd = '" . $filepasswd . "'";
    $result = @mysqli_query($link, $sql_query);
    if (mysqli_num_rows($result) == 1) {
        echo "登入成功";
    } else {
        echo "登入失敗";
    }
}
