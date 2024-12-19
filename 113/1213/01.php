<html>

<head>
    <title>ph連接資料庫</title>
</head>
<?php
include "connection.php";
?>

<body>
    <p>ph連接資料庫
        <hr>
        <?php
        $database = "school";
        $select_db = @mysqli_select_db($link, $database);
        if (!$select_db) {
            echo "資料庫選擇失敗";
        } else {
            $sql_query = "SELECT * FROM classes";
            $result = @mysqli_query($link, $sql_query);

            echo '<p>資料筆數: ' . mysqli_num_rows($result) . '<br>';
            echo '<table border="1" width=50%>';
            echo '<tr>';
            echo '<td>eid</td>';
            echo '<td>sid</td>';
            echo '<td>C_no</td>';
            echo '<td>time</td>';
            echo '<td>room</td>';
            echo '<td>score</td>';
            while ($row = mysqli_fetch_array($result)) {
                echo '<tr>';
                echo '<td>' . $row['0'] . '</td>';
                echo '<td>' . $row['1'] . '</td>';
                echo '<td>' . $row['2'] . '</td>';
                echo '<td>' . $row['3'] . '</td>';
                echo '<td>' . $row['4'] . '</td>';
                echo '<td>' . $row['5'] . '</td>';
            }
            echo '</table>';
        }
        ?>
</body>

</html>