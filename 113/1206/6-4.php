<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>性別顯示</title>
</head>

<body>
    <p>傳過來的參數：
        <?php

        $sex = $_GET['sex'];

        echo "<p>性別： " . $sex;

        ?>
</body>

</html>