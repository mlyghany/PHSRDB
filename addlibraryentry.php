<?php
        require_once("./configure.php");

        $libraryName = mb_convert_case($_POST['libraryName'], MB_CASE_TITLE, "UTF-8");
        $query = "INSERT INTO library (library_name) VALUES ('$libraryName')";
        $result = mysql_query($query) or die ("Query Failed!");

        $query = "SELECT * FROM library WHERE library_name = '$libraryName'";
        $result = mysql_query($query) or die("Query Failed!");
        $library = mysql_fetch_array($result, MYSQL_ASSOC);
        extract($library);
?>

<html>
    <body>
        <script type="text/javascript">
            function sendToParent(){
                var parentWindow = opener.document;
                var libraryCount = parentWindow.newResearch.libraryCount.value;
                libraryCount++;
                var root = parentWindow.getElementById('libraryTable');;
                var tr = document.createElement('tr');
                var td1 = document.createElement('td');
                var content = document.createElement('input');
                var remove = document.createElement('input');

                content.setAttribute('name', "library" + libraryCount);
                content.setAttribute('id', "library" + libraryCount);
                content.setAttribute('type', 'hidden');
                content.setAttribute('value', <?php echo $library_id;?> ) ;
                tr.appendChild(content);

                tr.setAttribute('name', 'studyLibrary' + libraryCount);
                tr.setAttribute('id', 'studyLibrary' + libraryCount);
                remove.setAttribute('onclick', 'Javascript: removeLibrary(' + libraryCount + ')');
                remove.setAttribute('value', 'remove');
                remove.setAttribute('type', 'button');
                remove.setAttribute('id', 'removelib' + libraryCount);
                content = document.createTextNode('<?php echo $library_name;?>');
                td1.appendChild(content);
                td1.appendChild(remove);
                tr.appendChild(td1);
                root.appendChild(tr);

                parentWindow.newResearch.libraryCount.value = libraryCount;
                self.close();
            }
            sendToParent();
        </script>
    </body>
</html>