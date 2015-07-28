<?php include('header.inc'); ?>
<?php include('configure.php'); ?>
<?php $pagetitle = 'Add a Library for the Research'; ?>
<?php 
if($_POST['pickerContentTrigger']) {
    $contentFlag = $_POST['pickerContentTrigger'];
}
else {
    $contentFlag = "Existing";
}	
?>
<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <center><h1><?php echo $pagetitle;?></h1></center>

    <table width="500px" style="margin-left: 50px; text-align: left;">
        <thead>

        <center>
            <form name="pickLibraryTrigger" id="pickLibraryTrigger" method="post" action="">
                <input type="radio" name="pickerContentTrigger" value="Existing" onclick="submit()" <?php if($contentFlag == "Existing") echo "checked"; ?>>Existing Library
                <input type="radio" name="pickerContentTrigger" value="New" onclick="submit()" <?php if($contentFlag == "New") echo "checked"; ?>>New Library
            </form>
        </center>
        </thead>
        <tbody id="libraryPickerContent">
            <?php
            if($contentFlag == "Existing") {
                $query = "SELECT * FROM library";
                $result = mysql_query($query) or die("Query Failed");

                if($result) {
                    echo("<table width='400px' align='center' border='1'>");
                    echo("<tr>");
                    echo("<th>&nbsp;</th>");
                    echo("<th>Library Name</th>");
                    echo("</tr>");
                    while($library = mysql_fetch_array($result, MYSQL_ASSOC)) {
                        extract($library);
                        echo("<tr>");
                        echo("<td><a href='javascript: pick($library_id);'>Add</a></td>");
                        echo("<td id='libraryName$library_id'>$library_name</td>");
                        echo("</tr>");
                    }
                    echo("</table>");
                }
            }
            else {
                ?>
        <form name="pickLibrary" id="pickLibrary" method="post" action="./addlibraryentry.php">
            <tr>
            <br />
            <td width="100px">Library Name</td>
            <td width="400px"><input type="text" name="libraryName" size="40" class="inputBox" /></td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center;"><input type="submit" value="Add Library" /></td>
            </tr>
        </form>
        <?php } ?>
        </tbody>
    </table>
</div>
</body>

<script type="text/javascript">
    function pick(library_id){
        var libraryname = document.getElementById('libraryName' + library_id).lastChild.nodeValue;
        var parentWindow = opener.document;
        var root = parentWindow.getElementById('libraryTable');
        var libraryCount = parentWindow.newResearch.libraryCount.value;
        libraryCount++;
        alert(libraryCount);
        var tr = document.createElement('tr');
        var td1 = document.createElement('td');
        var content = document.createElement('input');
        var remove = document.createElement('input');

        content.setAttribute('name', "library" + libraryCount);
        content.setAttribute('id', "library" + libraryCount);
        content.setAttribute('type', 'hidden');
        content.setAttribute('value', library_id);
        tr.appendChild(content);

        tr.setAttribute('name', 'studyLibrary' + libraryCount);
        tr.setAttribute('id', 'studyLibrary' + libraryCount);
        remove.setAttribute('onclick', 'Javascript: removeLibrary(' + libraryCount + ')');
        remove.setAttribute('value', 'remove');
        remove.setAttribute('type', 'button');
        remove.setAttribute('id', 'removelib' + libraryCount);

        content = document.createTextNode(libraryname);
        td1.appendChild(content);
        td1.appendChild(remove);
        tr.appendChild(td1);
        root.appendChild(tr);

        parentWindow.newResearch.libraryCount.value = libraryCount;
        self.close();
    }
</script>

</html>

