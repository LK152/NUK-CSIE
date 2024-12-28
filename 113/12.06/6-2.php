<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>血型顯示</title>
</head>

<body>
    <p>傳過來的參數：
        <?php

        $bloodtype = $_GET['bloodtype'];

        echo "<p>血型： " . $bloodtype;

        ?>
</body>

</html>