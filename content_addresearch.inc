<?php $pagetitle = 'New Research Entry'; ?>
<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <h1><?php echo $pagetitle;?></h1>
    <form name="newResearch" id="newResearch" method="post" action="./addresearchentry.php">
        <table width="650px" style="margin-left: 50px; text-align: left;">
            <thead>
                <tr>
                    <td width="200px" style="vertical-align: top;">
                                                                                Author/s &nbsp;
                        <button type="button" onclick="showAuthorPicker()">+</button>
                    </td>
                    <td width="450px">
                        <table>
                            <tbody id ="authorTable">
                            <input type="hidden" id="authorCount" name="authorCount" value= "0"/>
                            </tbody>
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
                        <input type="text" name="studyTitle" size="40" class="inputBox">
                    </td>
                </tr>
                <tr>
                    <td>
										Published?
                    </td>
                    <td>
                        <select name="studyPublished" onchange="showContent(this)" class="inputBox">
                            <option value="Y">Yes</option>
                            <option value="N">No</option>
                        </select>
                    </td>
                </tr>
            </thead>
            <tbody id="formContent1">
                <tr>
                    <td>Publication</td>
                    <td><input size="40" class="inputBox" name="studyPublication"></td>
                </tr>
                <tr>
                    <td>Year Published</td>
                    <td><input size="4" class="inputBox" name="studyYearPublished"></td>
                </tr>
                <tr>
                    <td>Volume Number</td>
                    <td><input size="40" class="inputBox" name="studyVolumeNumber"></td>
                </tr>
                <tr>
                    <td>Pages Inclusive</td>
                    <td><input size="40" class="inputBox" name="studyPagesInclusive"></td>
                </tr>
                <tr>
                    <td colspan="2" style="text-align: center;"><input type="submit" value="Add"></td>
                </tr>
            </tbody>
            <tbody id="formContent2" style="display:none">
                <tr>
                    <td>Type</td>
                    <td><select class="inputBox" name="studyType">
                            <option value="Dissertation">Dissertation</option>
                            <option value="Masteral Thesis">Masteral Thesis</option>
                            <option value="Undergraduate Thesis">Undergraduate Thesis</option>
                            <option value="Student Report">Student Report</option>
                            <option value="Technical Report">Technical Report</option>
                        </select></td>
                </tr>
                <tr>
                    <td>Year Completed</td>
                    <td><input size="40" class="inputBox" name="studyYearCompleted"></td>
                </tr>
                <tr>
                    <td style="vertical-align: top;">Library/ies  <button type="button" onclick="showLibraryPicker()">+</button></td>
                    <td id="libraryContent">
                        <table>
                            <tbody id ="libraryTable">
                            <input type='hidden' id='libraryCount' name='libraryCount' value='0'>
                            </tbody>
                        </table>
                    </td>
                </tr>
                <tr>
                    <td colspan="2" style="text-align: center;"><input type="submit" value="Add">
                    </td>
                </tr>
            </tbody>
        </table>
    </form>
</div>

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

    function showAuthorPicker(){
        window.open("authorPicker.php","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
    }

    function showLibraryPicker(){
        window.open("libraryPicker.php","Ratting","width=550,height=400,left=150,top=200,toolbar=1,status=1,");
    }

    function remove(authorID){
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
            remove.setAttribute('onclick', 'Javascript: remove(' + i + ')');
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

