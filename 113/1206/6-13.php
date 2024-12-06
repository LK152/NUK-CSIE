<?php session_start(); //宣告session之前不可以有html的字串輸出 
?>
<html>

<head>
    <title>Session</title>
</head>

<body>
    <p><a href=6-14.php?usrname=john&id=123>這是一個超連結，會傳"john"</a></p>
    <p><a href=6-14.php?usrname=cindy&id=456>這是一個超連結，會傳"cindy"</a></p>
    <p><a href=6-14.php?usrname=andy&id=789>這是一個超連結，會傳"andy"</a></p>
</body>

</html>