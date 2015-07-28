<?php
$pagetitle = 'Edit Research Entry';
require_once("configure.php");
$studyid = $_GET['studyid'];
$query = "SELECT * FROM study WHERE study_id ='$studyid'";
$result = mysql_query($query) or die("Query Failed!");
$study = mysql_fetch_array($result, MYSQL_ASSOC);
extract($study);
?>
<script type="text/javascript">
    function showContent(opt){
        if(opt.value == "Y"){
            document.getElementById('formContent1').style.display = "";
            document.getElementById('formContent2').style.display = "none";
        }
        else{
            document.getElementById('formContent1').style.display = "none";
            document.getElementById('formContent2').style.display = "";
        }
    }
    showContent(document.getElementById('studyPublished'));

    function showAuthorPicker(studyid){
        window.open("authorPicker.php?studyid=" + studyid + "","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
    }

    function showLibraryPicker(){
        window.open("libraryPicker.php","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
    }

    function removeAuthor(authorID){
        var table = document.getElementById("authorTable");
        var authorCount = document.getElementById("authorCount");
        var tr = document.getElementById("studyAuthor" + authorID);
        var count = authorCount.value;
        table.removeChild(tr);

        for(var i = authorID; i < count; i++){
            tr = document.getElementById("studyAuthor" + (i+1));
            var content = document.getElementById("study" + (i+1));
            var remove = document.getElementById("remove" + (i+1));

            content.setAttribute('name', "study" + i);
            content.setAttribute('id', "study" + i);
            remove.setAttribute('id', "remove" + i);

            tr.setAttribute('name', 'studyAuthor' + i);
            tr.setAttribute('id', 'studyAuthor' + i);
            remove.setAttribute('onclick', 'Javascript: removeAuthor(' + i + ')');
        }
        document.newResearch.authorCount.value = (count-1);
    }

    function removeLibrary(libraryID){
        var table = document.getElementById("libraryTable");
        var libraryCount = document.getElementById("libraryCount");
        var tr = document.getElementById("studyLibrary" + libraryID);
        var count = libraryCount.value;
        table.removeChild(tr);

        for(var i = libraryID; i < count; i++){
            tr = document.getElementById("studyLibrary" + (i+1));
            var content = document.getElementById("library" + (i+1));
            var remove = document.getElementById("removelib" + (i+1));

            content.setAttribute('name', "library" + i);
            content.setAttribute('id', "library" + i);
            remove.setAttribute('id', "removelib" + i);

            tr.setAttribute('name', 'studyLibrary' + i);
            tr.setAttribute('id', 'studyLibrary' + i);
            remove.setAttribute('onclick', 'Javascript: removeLibrary(' + i + ')');
        }

        document.newResearch.libraryCount.value = (count-1);
    }
</script>

<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <h1><?php echo $pagetitle;?></h1>
    <form name="newResearch" id="newResearch" method="post" action="./editresearchentry.php?studyid=<?php echo $studyid; ?>">
        <table width="650px" style="margin-left: 50px; text-align: left;">
            <thead>
                <tr>
                    <td width="200px" style="vertical-align: top;">
										Author/s &nbsp;
                        <?php echo"<button type='button' onclick='showAuthorPicker(" . $studyid . ")'>+</button>"; ?>
                    </td>
                    <td id="authorContent" width="450px">
                        <table>
                            <tbody id ="authorTable">
                                <?php
                                $i = 1;
                                $query = "SELECT * FROM study_author WHERE study_id = '$studyid'";
                                $result = mysql_query($query) or die("Query Failed!");
                                while ($row = mysql_fetch_assoc($result)) {
                                    $authorid = $row["author_id"];
                                    $query2 = "SELECT * FROM author WHERE author_id='$authorid'";
                                    $result2 = mysql_query($query2) or die("Query Failed!");
                                    $author = mysql_fetch_array($result2, MYSQL_ASSOC);
                                    if($author) extract($author);

                                    echo"<tr name='studyAuthor" . $i . "' id='studyAuthor" . $i . "'>";
                                    echo"<input name='study" . $i . "' id='study" . $i . "' type='hidden' value='" . $author_id . "'><td>";
                                    echo $author_lastname . ", " . $author_firstname;
                                    if($author_mi != "") echo " " . $author_mi . ".";
                                    echo"<input onclick='Javascript: removeAuthor(" . $i . ")' value='remove' type='button' id='remove" . $i . "'></td></tr>";
                                    $i++;
                                }
                                echo"<input type='hidden' id='authorCount' name='authorCount' value='" . ($i-1) . "'/>"
                                ?>
                            <tbody>
                        </table>
                    </td>
                </tr>
                <tr>
                    <td width="200px">
										Database
                    </td>
                    <td width="450px">
                        <select name="studyDatabase" onchange="" class="inputBox">
                            <option value="Ethnopharmacological">Ethnopharmacological Study</option>
                        </select>
                    </td>
                </tr>
                <tr>
                    <td width="200px">
										Title
                    </td>
                    <td width="450px">
                        <?php echo"<input type='text' name='studyTitle' size='40' class='inputBox' value='" . $study_title . "'>"; ?>
                    </td>
                </tr>
                <tr>
                    <td>
										Published?
                    </td>
                    <td>
                        <select name="studyPublished" id="studyPublished" onchange="showContent(this)" class="inputBox">
                            <option value="Y">Yes</option>
                            <?php
                            if ($study_published== "Y") echo"<option value='N'>No</option>";
                            else echo"<option value='N' selected='true'>No</option>";
                            ?>
                        </select>
                    </td>
                </tr>
            </thead>
                <?php
                if($study_published == "Y") {
                    $query = "SELECT * FROM study_published WHERE study_id='$studyid'";
                    $result = mysql_query($query) or die("Query Failed!");
                    $studypublished = mysql_fetch_array($result, MYSQL_ASSOC);
                    if($studypublished) extract($studypublished);
                }
                else {
                    $query = "SELECT * FROM study_unpublished WHERE study_id='$studyid'";
                    $result = mysql_query($query) or die("Query Failed!");
                    $studyunpublished = mysql_fetch_array($result, MYSQL_ASSOC);
                    if($studyunpublished) extract($studyunpublished);
                }
                ?>
            <tbody id="formContent1" <?php if($study_published == "N") echo "style='display:none'";?>>
                <tr>
                    <td>Publication</td>
                    <td><input size="40" class="inputBox" name="studyPublication" <?php if($study_published == "Y") echo "value='" . $study_publication. "'";?>></td>
                </tr>
                <tr>
                    <td>Year Published</td>
                    <td><input size="4" class="inputBox" name="studyYearPublished" <?php if($study_published == "Y" && $study_yearpublished != "0000") echo "value='" . $study_yearpublished. "'";?>></td>
                </tr>
                <tr>
                    <td>Volume Number</td>
                    <td><input size="40" class="inputBox" name="studyVolumeNumber" <?php if($study_published == "Y") echo "value='" . $study_volumenumber. "'";?>></td>
                </tr>
                <tr>
                    <td>Pages Inclusive</td>
                    <td><input size="40" class="inputBox" name="studyPagesInclusive" <?php if($study_published == "Y") echo "value='" . $study_pagesinclusive. "'";?>></td>
                </tr>
                <tr>
                    <td colspan="2" style="text-align: center;"><input type="submit" value="Edit"></td>
                </tr>
            </tbody>
            <tbody id="formContent2" <?php if($study_published == "Y") echo "style='display:none'";?>>
                <tr>
                    <td>Type</td>
                    <td><select class="inputBox" name="studyType">
                            <option value="Dissertation"<?php if ($study_published == 'N') if($study_type == 'Dissertation') echo "selected='true'"; ?>>Dissertation</option>
                            <option value="Masteral Thesis" <?php if ($study_published == 'N') if($study_type == 'Masteral Thesis') echo "selected='true'"; ?>>Masteral Thesis</option>
                            <option value="Undergraduate Thesis" <?php if ($study_published == 'N') if($study_type == 'Undergraduate Thesis') echo "selected='true'"; ?>>Undergraduate Thesis</option>
                            <option value="Student Report" <?php if ($study_published == 'N') if($study_type == 'Student Report') echo "selected='true'"; ?>>Student Report</option>
                            <option value="Technical Report" <?php if ($study_published == 'N') if($study_type == 'Technical Report') echo "selected='true'"; ?>>Technical Report</option>
                        </select></td>
                </tr>
                <tr>
                    <td>Year Completed</td>
                    <td><input size="40" class="inputBox" name="studyYearCompleted" <?php if ($study_published == 'N' && $study_yearcompleted != "0000") echo "value='" . $study_yearcompleted . "'"; ?>></td>
                </tr>
                <tr>
                    <td style="vertical-align: top;">Library/ies  <button type="button" onclick="showLibraryPicker()">+</button></td>
                    <td id="libraryContent">
                        <table>
                            <tbody id ="libraryTable">
                                <?php
                                $i = 1;
                                $query = "SELECT * FROM study_library WHERE study_id = '$studyid'";
                                $result = mysql_query($query) or die("Query Failed!");
                                while ($row = mysql_fetch_assoc($result)) {
                                    $libraryid = $row["library_id"];
                                    $query2 = "SELECT * FROM library WHERE library_id='$libraryid'";
                                    $result2 = mysql_query($query2) or die("Query Failed!");
                                    $library = mysql_fetch_array($result2, MYSQL_ASSOC);
                                    extract($library);

                                    echo"<tr name='studyLibrary" . $i . "' id='studyLibrary" . $i . "'>";
                                    echo"<input name='library" . $i . "' id='library" . $i . "' type='hidden' value='" . $library_id . "'><td>";
                                    echo $library_name;
                                    echo"<input onclick='Javascript: removeLibrary(" . $i . ")' value='remove' type='button' id='removelib" . $i . "'></td></tr>";
                                    $i++;
                                }
                                echo"<input type='hidden' id='libraryCount' name='libraryCount' value='" . ($i-1) . "'/>"
                                ?>
                            <tbody>
                        </table>
                    </td>
                </tr>
                <tr>
                    <td colspan="2" style="text-align: center;"><input type="submit" value="Edit">
                    </td>
                </tr>
            </tbody>
        </table>
    </form>
</div>

