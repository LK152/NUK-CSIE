<html>

<head>
    <title>複選式表單</title>
</head>

<body>
    <form method="get" action="6-6.php">
        <p>喜歡的食物</p>
        <p><input type="checkbox" name="fruit[]" value="apple">apple</p>
        <p><input type="checkbox" name="fruit[]" value="orange">orange</p>
        <p><input type="checkbox" name="fruit[]" value="banana">banana</p>
        <p><input type="checkbox" name="fruit[]"
                value="strawberry">strawberry</p>
        <p><input value=" 送出 " type="submit"><input value=" 清 除 " type="reset" name="reset"></p>
    </form>
</body>

</html>