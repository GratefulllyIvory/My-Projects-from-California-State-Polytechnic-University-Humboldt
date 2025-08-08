<!--quiz.php-->
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
          
	<title> Project6_2phpCS328</title>
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
            <legend> Enter Oracle username/password: </legend>

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
$wolfq = $_POST["wolfq"];
$oceanq = $_POST["oceanq"];
$alaskaq = $_POST["alaskaq"];

echo "<p>Succesfully Submitted</p>";

//procedure to post to table	
$response_query_str = 'select* wolfq, oceanq, alaskaq from quizResponse';
$response_query_stmt = oci_parse($conn, $response_query_str);
oci_execute($response_query_str, OCI_DEFAULT);
?>
	<table>
		<caption> Quiz Response</caption>
		<tr><th scope="col"> wolfq </th>
			<th scope="col"> oceanq </th>
			<th scope="col"> alaskaq </th>
		</tr>
		<?php
			while(oci_fetch($buyer_query_stmt)
			{
				$insert_wolfq = oci_result($response_query_stmt, 'wolfq');
				$insert_oceanq = oci_result($response_query_stmt, 'oceanq');
				$insert_alaskaq = oci_result($response_query_stmt, 'alaskaq');	
				?>
				<tr><td> <?= $insert_wolfq ?> </td>
					<td> <?= $insert_oceanq ?> </td>
					<td> <?= $insert_alaskaq ?> </td>
				</tr>
			}
		<?php
?>
		</table>
<?php
	oci_free_statement($response_query_stmt_query_stmt);
	oci_close($conn)
}
?>