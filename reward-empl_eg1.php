<?php
// CS328 Example Solution

?>

<!DOCTYPE html>
<html  xmlns="http://www.w3.org/1999/xhtml">

<!--
    demo connecting from PHP on nrs-projects
    to the Oracle student database on cedar

    adapted from an example by Peter Johnson
    adapted by: Sharon Tuttle
    last modified: 2018-03-08
-->

<head>
    <title> Connecting to Oracle! </title>
    <meta charset="utf-8" />

    <link href="http://users.humboldt.edu/smtuttle/styles/normalize.css"
          type="text/css" rel="stylesheet" />
    <link href="try-oracle.css" type="text/css" rel="stylesheet" />
</head>

<body>

<h1> Connecting PHP to Oracle </h1>
<h2> Max Pierce and James Pelligra </h2>

<?php
    // request username and password

    if ( ! array_key_exists("username", $_POST) )
    {
        // no username in $_POST? they need a login form!
        ?>

        <form method="post"
              action="<?= htmlentities($_SERVER['PHP_SELF'], ENT_QUOTES) ?>">
        <fieldset>
            <legend>
                    Please enter Oracle username/password <br>
                    Along with employee last name and raise amount:
            </legend>

            <label for="username"> Username: </label>
            <input type="text" name="username" id="username" />

            <label for="password"> Password: </label>
            <input type="password" name="password" id="password" />

            <label for="last_name"> Last Name: </label>
            <input type="last_name" name="last_name" id="last_name" />

            <label for="raise_amount"> Raise Amount: </label>
            <input type="raise_amount" name="raise_amount" id="raise_amount" />

            <div class="submit">
                <input type="submit" value="Log in" />
            </div>
        </fieldset>
        </form>
    <?php
    }

    // otherwise, handle the submitted login form
    //    (or try to) -- and show the user desired employee information

    else
    {
        // I am a little paranoid -- I'm stripping
        //    tags from the username

        $username = strip_tags($_POST['username']);

        // the ONLY thing I am doing with this is
        //    trying to log in -- so I HOPE this is OK

        $password = $_POST['password'];

        $last_name = strip_tags($_POST['last_name']);
        $raise_amount = strip_tags($_POST['raise_amount']);

        // set up connection string

        $db_conn_str =
            "(DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)
                                       (HOST = cedar.humboldt.edu)
                                       (PORT = 1521))
                            (CONNECT_DATA = (SID = STUDENT)))";

        // connect and log into Oracle using this

        $conn = oci_connect($username, $password, $db_conn_str);

        // exiting if connection/log in failed

        if (! $conn)
        {
            ?>
            <p> Could not log into Oracle, sorry </p>

</body>
</html>
            <?php
            exit;
        }

        // if I get here -- I connected!

        $password = NULL; // I won't be using this anymore

        // let's set up a SQL SELECT statement and ask the
        //     data tier to execute it for us

        $empl_query_str = 'update empl
                           set
                               salary = salary + :raise_amount_bv
                           where empl_last_name = :last_name_bv';
        $empl_query_stmt = oci_parse($conn, $empl_query_str);
        oci_bind_by_name($empl_query_stmt, ":raise_amount_bv", $raise_amount);
        oci_bind_by_name($empl_query_stmt, ":last_name_bv", $last_name);
        oci_execute($empl_query_stmt, OCI_DEFAULT);

        $empl_raise_str = 'select count(*)
                             from empl
                             where empl_last_name = :last_name_bv';
        $empl_raise_stmt = oci_parse($conn, $empl_raise_str);
        oci_bind_by_name($empl_raise_stmt, ":last_name_bv", $last_name);
        $empl_raise_count = oci_execute($empl_raise_stmt, OCI_DEFAULT);

        $total_empl_str = 'select count(empl_last_name)
                           from empl';
        $total_empl_stmt = oci_parse($conn, $total_empl_str);
        $total_empl_count = oci_execute($total_empl_stmt, OCI_DEFAULT);
        ?>

        <p>
            <?php
                echo "This many people got raises: ".$empl_raise_count;
                echo "<br>";
                echo "By the way, you have ".$total_empl_count." employees in total, do any more need raises?";
            ?>

        </p>

        <?php

         // FREE your statement, CLOSE your connection!

         oci_free_statement($empl_query_stmt);
         oci_close($conn);
    }
?>

</body>
</html>
