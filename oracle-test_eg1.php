<?php
// CS 328 Example Solution  Lab 9
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
</html>
            <?php
            exit;
        }

        // if I get here -- I connected!

        $password = NULL; // I won't be using this anymore

        // let's set up a SQL SELECT statement and ask the
        //     data tier to execute it for us

        $book_query_str = 'select pub_id, title_name, author
                           from title';
        $book_query_stmt = oci_parse($conn, $book_query_str);

        oci_execute($book_query_stmt, OCI_DEFAULT);
        ?>

        <table>
            <caption> Book Title Information </caption>
            <tr> <th scope="col"> Pub_ID </th>
                 <th scope="col"> Title </th>
                 <th scope="col"> Author </th>
            </tr>

        <?php
            while (oci_fetch($book_query_stmt))
            {
                $curr_pub_id = oci_result($book_query_stmt, 'PUB_ID');
                $curr_title = oci_result($book_query_stmt, 'TITLE_NAME');
                $curr_author = oci_result($book_query_stmt, 'AUTHOR');

                ?>
                <tr> <td> <?= $curr_pub_id ?> </td>
                     <td> <?= $curr_title ?> </td>
                     <td> <?= $curr_author ?> </td>
                </tr>
                <?php
            }
            ?>
            </table>

            <?php

             // FREE your statement, CLOSE your connection!

             oci_free_statement($book_query_stmt);
             oci_close($conn);
    }

?>

</body>
</html>
