<?php
include 'db_connect.php';

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $id = $_POST['id'];
    $name = $_POST['name'];
    $semester = $_POST['semester'];
    $address = $_POST['address'];

    $sql = "UPDATE bca SET name='$name', semester='$semester', address='$address' WHERE id=$id";

    if ($conn->query($sql) === TRUE) {
        header("Location: index.php");
    } else {
        echo "Error updating record: " . $conn->error;
    }
}

$id = $_GET['id'];
$sql = "SELECT * FROM bca WHERE id=$id";
$result = $conn->query($sql);
$row = $result->fetch_assoc();
?>

<!DOCTYPE html>
<html>
<head>
     <title>Edit Student</title>
</head>
<body>
    <h2>Edit Student</h2>
    <form method="post">
        <input type="hidden" name="id" value="<?php echo $row['id']; ?>">
        Name: <input type="text" name="name" value="<?php echo $row['name']; ?>" required><br>
        Semester: <input type="number" name="semester" value="<?php echo $row['semester']; ?>" required><br>
        Address: <input type="text" name="address" value="<?php echo $row['address']; ?>" required><br>
        <input type="submit" value="Update">
    </form>
    <br>
    <a href="index.php">Back to List</a>
</body>
</html>
<?php
$conn->close();
?>
