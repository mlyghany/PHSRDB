<?php
require_once("./configure.php");
$lastname = mb_convert_case($_POST['gathererLastName'], MB_CASE_TITLE, "UTF-8");
$firstname = mb_convert_case($_POST['gathererFirstName'], MB_CASE_TITLE, "UTF-8");
$middleinitial = mb_convert_case($_POST['gathererMI'], MB_CASE_TITLE, "UTF-8");

$query = "INSERT INTO gatherer (gatherer_lastname, gatherer_firstname, gatherer_mi) VALUES ('$lastname', '$firstname', '$middleinitial')";
$result = mysql_query($query) or die ("Query Failed!");
$query = "SELECT * FROM gatherer WHERE gatherer_lastname = '$lastname' and gatherer_firstname = '$firstname' and gatherer_mi = '$middleinitial'";
$result = mysql_query($query) or die("Query Failed!");
$gatherer = mysql_fetch_array($result, MYSQL_ASSOC);
extract($gatherer);
?>

<html>
    <body>
        <script type="text/javascript">
            function sendToParent(){
                var parentWindow = opener.document;
                var gathererCount = parentWindow.addInformant.gathererCount.value;
                gathererCount++;
                var root = parentWindow.getElementById('gathererContent');;

                var tr = document.createElement('tr');
                var td1 = document.createElement('td');

                var content = document.createElement('input');
                var remove = document.createElement('input');
                content.setAttribute('name', "gatherer" + gathererCount);
                content.setAttribute('id', "gatherer" + gathererCount);
                content.setAttribute('type', 'hidden');
                content.setAttribute('value', <?php echo $gatherer_id; ?>);
                tr.appendChild(content);
                tr.setAttribute('name', 'informantGatherer' + gathererCount);
                tr.setAttribute('id', 'informantGatherer' + gathererCount);
                remove.setAttribute('onclick', 'Javascript: removeGatherer(' + gathererCount + ')');
                remove.setAttribute('value', 'remove');
                remove.setAttribute('type', 'button');
                remove.setAttribute('id', 'remove' + gathererCount);
                content = document.createTextNode('<?php echo(mb_convert_case($lastname, MB_CASE_TITLE, 'UTF-8') . ", " . mb_convert_case($firstname, MB_CASE_TITLE, 'UTF-8')); if($middleinitial != "") echo " " . ucfirst($middleinitial) . "."; ?>');
                td1.appendChild(content);
                td1.appendChild(remove);
                tr.appendChild(td1);
                root.appendChild(tr);


                parentWindow.addInformant.gathererCount.value = gathererCount;
                self.close();
            }
            sendToParent();
        </script>
    </body>
</html>