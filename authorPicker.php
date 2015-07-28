<?php
include('header.inc');
include('configure.php');
 $pagetitle = 'Add an Author for the Research';
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
            <form name="pickAuthorTrigger" id="pickAuthorTrigger" method="post" action="">
                <input type="radio" name="pickerContentTrigger" value="Existing" onclick="submit()" <?php if($contentFlag == "Existing") echo "checked"; ?>>Existing Author
                <input type="radio" name="pickerContentTrigger" value="New" onclick="submit()" <?php if($contentFlag == "New") echo "checked"; ?>>New Author
            </form>
        </center>
        </thead>
        <tbody id="authorPickerContent">
            <?php
            if($contentFlag == "Existing") {
                $query = "SELECT * FROM author";
                $result = mysql_query($query) or die("Query Failed");

                if($result) {
                    echo("<table width='400px' align='center' border='1'>");
                    echo("<tr>");
                    echo("<th>&nbsp;</th>");
                    echo("<th>Last Name</th>");
                    echo("<th>First Name</th>");
                    echo("<th>Middle Initial</th>");
                    echo("</tr>");
                    while($author = mysql_fetch_array($result, MYSQL_ASSOC)) {
                        extract($author);

                        echo("<tr>");
                        echo("<td><a href='javascript: pick($author_id);'>Add</a></td>");
                        echo("<td id='lastname$author_id'>$author_lastname</td>");
                        echo("<td id='firstname$author_id'>$author_firstname</td>");
                        echo("<td id='mi$author_id'>$author_mi</td>");
                        echo("</tr>");
                    }
                    echo("</table>");
                }
            }
            else {

                echo"<form name='pickAuthor' id='pickAuthor' method='post' action='./addauthorentry.php'>";
            ?>
            <tr>
        <br />
        <td width="100px">Last Name</td>
        <td width="400px"><input type="text" name="authorLastName" size="40" class="inputBox" /></td>
        </tr>
        <tr>
            <td width="100px">First Name</td>
            <td width="400px"><input type="text" name="authorFirstName" size="40" class="inputBox" /></td>
        </tr>
        <tr>
            <td width="100px">Middle Inital</td>
            <td width="400px"><input type="text" name="authorMI" size="10" class="inputBox" /></td>
        </tr>
        <tr>
            <td colspan="2" style="text-align: center;"><input type="submit" value="Add Author" /></td>
        </tr>
        </form>
        <?php } ?>
        </tbody>
    </table>
</div>
</body>

<script type="text/javascript">
    function pick(author_id){
        var lastname = document.getElementById('lastname' + author_id).lastChild.nodeValue;
        var firstname = document.getElementById('firstname' + author_id).lastChild.nodeValue;
        var mi = document.getElementById('mi' + author_id);
        if(mi.hasChildNodes()) mi = mi.lastChild.nodeValue;
        else mi = "";
        var parentWindow = opener.document;
        var root = parentWindow.getElementById('authorTable');
        var authorCount = parentWindow.newResearch.authorCount.value;

        authorCount++;
        var tr = document.createElement('tr');
        var td1 = document.createElement('td');

        var content = document.createElement('input');
        var remove = document.createElement('input');

        content.setAttribute('name', "study" + authorCount);
        content.setAttribute('id', "study" + authorCount);
        content.setAttribute('type', 'hidden');
        content.setAttribute('value', author_id);
        tr.appendChild(content);

        tr.setAttribute('name', 'studyAuthor' + authorCount);
        tr.setAttribute('id', 'studyAuthor' + authorCount);
        remove.setAttribute('onclick', 'Javascript: removeAuthor(' + authorCount + ')');
        remove.setAttribute('value', 'remove');
        remove.setAttribute('type', 'button');
        remove.setAttribute('id', 'remove' + authorCount);

        content = document.createTextNode(lastname + ', ' + firstname + ' ');
        if(mi != "") content = document.createTextNode(lastname + ', ' + firstname + ' ' + mi + ".");
        td1.appendChild(content);
        td1.appendChild(remove);
        tr.appendChild(td1);
        root.appendChild(tr);

        parentWindow.newResearch.authorCount.value = authorCount;
        self.close();
    }
</script>

</html>

