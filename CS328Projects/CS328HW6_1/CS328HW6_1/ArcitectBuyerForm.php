<!--ArchitectBuyerForm.php-->
<!doctype html>
<html>

<head>

	<link rel="stylesheet" type= "text/css" href="./hw2style.css">
	<meta name="author" content="Daniel Desforges, djd86@humboldt.edu" />

	<meta name="description" content="HSU CS328, "/>

	<meta name="keywords" content="CS 328,
	HSU, Humboldt, Humboldt
	State, Humboldt State University, California State University, Arcata,
	California,Homework,Web Apps" />
          
	<title> Project6_1phpCS328</title>
</head>
<?php
//credit to lab9Solution for oracle connection code
// request username and password?

    if ( ! array_key_exists("username", $_POST) )
    {
        // no username in $_POST? they need a login form!
        ?>

        <form method="post"
              action="<?= htmlentities($_SERVER['PHP_SELF'], ENT_QUOTES) ?>">
        <fieldset>
            <legend> Please enter Oracle username/password: </legend>

            <label for="username"> Username: </label>
            <input type="text" name="username" id="username" />

            <label for="password"> Password: </label>
            <input type="password" name="password"
                   id="password" />

            <div class="submit">
                <input type="submit" value="Log in" />
            </div>
        </fieldset>
        </form>
<?php
}
//credit to lab9Solution for oracle connection code
    // otherwise, handle the submitted login form
    //    (or try to) -- and show the user desired  employee information

    else
    {
        // I am a little paranoid -- I'm stripping
        //    tags from the username

        $username = strip_tags($_POST['username']);

        // the ONLY thing I am doing with this is
        //    trying to log in -- so I HOPE this is OK

        $password = $_POST['password'];

        // set up connection string

        $db_conn_str =
            "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)
                                       (HOST = cedar.humboldt.edu)
                                       (PORT = 1521))
                            (CONNECT_DATA = (SID = STUDENT)))";

        // let's try to connect and log into Oracle using this

        $conn = oci_connect($username, $password, $db_conn_str);

        // exiting if connection/log in failed

        if (! $conn)
        {
            ?>
            <p> Could not log into Oracle, sorry </p>

</body>
<?php
//
$password =NULL; //releasing pw

//variable to work with in user page print out
$first = $_POST["firstN"];
$last = $_POST["lastN"];
$email = $_POST["email"];
$telephone = $_POST["telephone"];
$descript = $_POST["descript"];
$budget = $_POST["budget"];
//problemscommentedandremovedfromtable$commercial = $_POST["commmercial"];
//problemscommentedandremovedfromtable$residential = $_POST["residential"];

echo "<p> Form Stamp First $first Last $last Email Phone Descript $descript Commercial? Residential? $residential Budget $budget TimeStamp </p>";
//function to post inputs to table
echo "<p>Succesfully Submitted</p>";

//procedure to post to table	
$buyer_query_str = 'select firstN, lastN, timestamp from ArchitectBuyerForm';
$buyer_query_stmt = oci_parse($conn, $buyer_query_str);
oci_execute($buyer_query_str, OCI_DEFAULT);
?>
	<table>
		<caption> ArchitectBuyerForm</caption>
		<tr><th scope="col"> firstN </th>
			<th scope="col"> lastN </th>
			<th scope="col"> email </th>
			<th scope="col"> telephone </th>
			<th scope="col"> descript </th>
			<th scope="col"> budget </th>
			<th scope="col"> timestamp</th>
		</tr>
		<?php
			while(oci_fetch($buyer_query_stmt)
			{
				$insert_firstN = oci_result($buyer_query_stmt, 'firstN');
				$insert_lastN = oci_result($buyer_query_stmt, 'lastN');
				$insert_email = oci_result($buyer_query_stmt, 'email');
				$insert_telephone = oci_result($buyer_query_stmt, 'telephone');
				$insert_descript = oci_result($buyer_query_stmt, 'descript');
				$insert_budget = oci_result($buyer_query_stmt, 'budget');
				$insert_timestamp = oci_result($buyer_query_stmt, 'timestamp');
				
				?>
				<tr><td> <?= $insert_firstN ?> </td>
					<td> <?= $insert_lastN ?> </td>
					<td> <?= $insert_email ?> </td>
					<td> <?= $insert_telephone ?> </td>
					<td> <?= $insert_descript ?> </td>
					<td> <?= $insert_budget ?> </td>
					<td> <?= $insert_timestamp?></td>
				</tr>
			}
		<?php
?>
		</table>
<?php
	oci_free_statement($buyer_query_stmt);
	oci_close($conn)
}
?>
</html>
