<?php
include 'db_connect.php';

// Handle form submission
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $name = $_POST['name'];
    $semester = $_POST['semester'];
    $address = $_POST['address'];

    $sql = "INSERT INTO bca (name, semester, address) VALUES ('$name', '$semester', '$address')";

    if ($conn->query($sql) === TRUE) {
        echo "New record created successfully";
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }
}

// Fetch data from the table
$sql = "SELECT * FROM bca";
$result = $conn->query($sql);
?>

<!DOCTYPE html>
<html>
<head>
    <title>BCA Student Management</title>
</head>
<body>
    <h2>Add New Student</h2>
    <form method="post">
        Name: <input type="text" name="name" required><br>
        Semester: <input type="number" name="semester" required><br>
        Address: <input type="text" name="address" required><br>
        <input type="submit" value="Submit">
    </form>

    <h2>Student List</h2>
    <table border="1">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Semester</th>
            <th>Address</th>
            <th>Action</th>
        </tr>
        <?php
        if ($result->num_rows > 0) {
            while($row = $result->fetch_assoc()) {
                echo "<tr>
                        <td>".$row["id"]."</td>
                        <td>".$row["name"]."</td>
                        <td>".$row["semester"]."</td>
                        <td>".$row["address"]."</td>
                        <td>
                            <a href='edit.php?id=".$row["id"]."'>Edit</a> |
                            <a href='delete.php?id=".$row["id"]."'>Delete</a>
                        </td>
                      </tr>";
            }
        } else {
            echo "<tr><td colspan='5'>No records found</td></tr>";
        }
        ?>
    </table>
</body>
</html>
<?php
$conn->close();
?>
