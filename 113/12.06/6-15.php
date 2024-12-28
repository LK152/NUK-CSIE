<?php
session_start(); //宣告session之前不可以有html的字串輸出
?>

<html>

<body>
    <p>傳過來的參數:
        <?php
        echo "<p>帳號: " . $filename;
        echo "<p>密碼: " . $fileid;
        ?>
    <p>SESSION的參數:
        <?php
        echo "<p>帳號: " . $_SESSION["name"];
        echo "<p>密碼: " . $_SESSION["id"];
        ?>
    </p>
</body>

</html>