<?php
require_once("./configure.php");
    $lastname = mb_convert_case($_POST['authorLastName'], MB_CASE_TITLE, "UTF-8");
    $firstname = mb_convert_case($_POST['authorFirstName'], MB_CASE_TITLE, "UTF-8");
    $middleinitial = mb_convert_case($_POST['authorMI'], MB_CASE_TITLE, "UTF-8");

    $query = "INSERT INTO author (author_lastname, author_firstname, author_mi) VALUES ('$lastname', '$firstname', '$middleinitial')";
    $result = mysql_query($query) or die ("Query Failed!");
    $query = "SELECT * FROM author WHERE author_lastname = '$lastname' and author_firstname = '$firstname' and author_mi = '$middleinitial'";
    $result = mysql_query($query) or die("Query Failed!");
    $author = mysql_fetch_array($result, MYSQL_ASSOC);
    extract($author);
?>

<html>
    <body>
        <script type="text/javascript">
            function sendToParent(){
                var parentWindow = opener.document;

                var authorCount = parentWindow.newResearch.authorCount.value;

                authorCount++;
                var root = parentWindow.getElementById('authorTable');;

                var tr = document.createElement('tr');
                var td1 = document.createElement('td');

                var content = document.createElement('input');
                var remove = document.createElement('input');
                content.setAttribute('name', "study" + authorCount);
                content.setAttribute('id', "study" + authorCount);
                content.setAttribute('type', 'hidden');
                content.setAttribute('value', <?php echo $author_id; ?>);
                tr.appendChild(content);

                tr.setAttribute('name', 'studyAuthor' + authorCount);
                tr.setAttribute('id', 'studyAuthor' + authorCount);
                remove.setAttribute('onclick', 'Javascript: remove(' + authorCount + ')');
                remove.setAttribute('value', 'remove');
                remove.setAttribute('type', 'button');
                remove.setAttribute('id', 'remove' + authorCount);
                content = document.createTextNode('<?php echo(mb_convert_case($lastname, MB_CASE_TITLE, 'UTF-8') . ", " . mb_convert_case($firstname, MB_CASE_TITLE, 'UTF-8')); if($middleinitial != "") echo " " . ucfirst($middleinitial) . "."; ?>');
                td1.appendChild(content);
                td1.appendChild(remove);
                tr.appendChild(td1);
                root.appendChild(tr);


                parentWindow.newResearch.authorCount.value = authorCount;
                self.close();
            }
            sendToParent();
        </script>
    </body>
</html>