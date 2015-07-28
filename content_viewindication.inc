<?php
$pagetitle = 'Indication Information';
require_once("configure.php");
$indicationid = $_GET['indicationid'];

$query = "SELECT * FROM indication WHERE indication_id = '$indicationid'";
$result = mysql_query($query) or die("Query Failed");
if($result) {
    $indication = mysql_fetch_array($result, MYSQL_ASSOC);
    if($indication) extract($indication);
}
if($indication_type == "Medical") {
    $query = "SELECT * FROM indication_medical WHERE indication_id = '$indicationid'";
    $result = mysql_query($query) or die("Query Failed");
    if($result) {
        $indication_medical = mysql_fetch_array($result, MYSQL_ASSOC);
        if($indication_medical) extract($indication_medical);
}}
if($indication_type == "Other") {
    $query = "SELECT * FROM indication_other WHERE indication_id = '$indicationid'";
    $result = mysql_query($query) or die("Query Failed");
    if($result) {
        $indication_other = mysql_fetch_array($result, MYSQL_ASSOC);
        if($indication_other) extract($indication_other);
}}

?>

<?php 


$studyid = $_GET['studyid'];
$studydatabase = $_GET['studydatabase'];

$query = "SELECT * FROM study WHERE study_id= '$studyid' ";
$result = mysql_query($query) or die("Query Failed!");
$study = mysql_fetch_array($result, MYSQL_ASSOC);
extract($study);

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

$query = "SELECT * FROM study_researcher WHERE study_id='$studyid'";
$result = mysql_query($query) or die("Query Failed!");
$studyresearcher = mysql_fetch_array($result, MYSQL_ASSOC);
if($studyresearcher) extract($studyresearcher);

?>
<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <!--BIBLIOGRAPHIC REFERENCE-->
    <h1>Bibliographic Reference <?php if($member_id == $researcher_id) {?><a href="editstudy.php?studyid=<?php echo($studyid); ?>" class="viewLinks">[edit]</a><?php } ?></h1>
    <table id="bibliographicReference" style="margin-left: 50px;" width="600px">
        <!--AUTHOR-->
        <?php
        $query = "SELECT * FROM study_author WHERE study_id='$studyid' ";
        $result = mysql_query($query) or die("Query Failed!");

        if(mysql_num_rows($result)> 0) {
            echo("<tr>");
            echo("<td width='200px'><strong>Author/s</strong></td>");
            echo("<td width='400px'>");

            while($author = mysql_fetch_array($result, MYSQL_ASSOC)) {
                extract($author);

                $nameinitials = "";

                $query2 = "SELECT * FROM author WHERE author_id='$author_id'";
                $result2 = mysql_query($query2) or die("Query Failed!");
                $studyauthor = mysql_fetch_array($result2, MYSQL_ASSOC);
                if($studyauthor) extract($studyauthor);

                $firstnametokens = Preg_split('/ /', $author_firstname);
                for($i=0; $i<count($firstnametokens); $i++) {
                    $nameinitials = $nameinitials . substr($firstnametokens[$i], 0, 1);
                }

                $nameinitials = $nameinitials . $author_mi;

                echo(ucfirst($author_lastname) . " " . $nameinitials);

                $count++;

                if($count < mysql_num_rows($result)) {
                    echo(", ");
                }

            }
            echo("</td>");
            echo("</tr>");
        }
        ?>
        <!--END OF AUTHOR-->

        <!--TITLE-->
        <?php
        if($study_title != "") {
            echo("<tr>");
            echo("<td width='200px'><strong>Title</strong></td>");
            echo("<td width='400px'>$study_title");
            if($study_published == "N") {
                echo(" ($study_type)");
                echo(" $study_yearcompleted.");
            }
            echo("</td>");
            echo("</tr>");
        }
        ?>
        <!--END OF TITLE-->

        <!--SOURCE-->
        <?php
        if($study_published == "Y") {
            if ($study_publication != "") {
                echo("<tr>");
                echo("<td width='200px'><strong>Source</strong></td>");
                echo("<td width='400px'>");
                echo("<i>$study_publication</i>");
                if ($study_yearpublished != "") echo(" $study_yearpublished");
                if ($study_volumenumber != "") echo(";$study_volumenumber");
                if ($study_pagesinclusive != "") echo(":$study_pagesinclusive");
                echo(".");
                echo("</td>");
                echo("</tr>");
            }
        }
        else {
            $query = "SELECT * FROM study_library WHERE study_id='$studyid'";
            $result = mysql_query($query) or die("Query Failed!");

            if(mysql_num_rows($result) > 0) {
                echo("<tr>");
                echo("<td width='200px'><strong>Source</strong></td>");
                echo("<td width='400px'>");
                $count = 0;

                while($library = mysql_fetch_array($result, MYSQL_ASSOC)) {
                    extract($library);

                    $query2 = "SELECT * FROM library WHERE library_id='$library_id'";
                    $result2 = mysql_query($query2) or die("Query Failed!");
                    $studylibrary = mysql_fetch_array($result2, MYSQL_ASSOC);
                    if($studylibrary) extract($studylibrary);

                    echo($library_name);

                    $count++;

                    if($count < mysql_num_rows($result)) {
                        echo(", ");
                    }
                }
            }
        }
        ?>
        <!--END OF SOURCE-->
    </table>
    <!--END OF BIBLIOGRAPHIC REFERENCE-->



<h1><?php echo $pagetitle; ?><a href="editindication.php?indicationid=<?php echo($indicationid); ?>&studyid=<?php echo($studyid); ?>" class="viewLinks">[edit]</a></h1>



<table width="600px" style='margin-left:50px;'>
    <tr>
        <td width="200px"><b>Indication Name</b></td>
        <td><?php echo $indication_name; ?></td>
    </tr>
    <tr>
        <?php if($indication_description) { ?>
        <td width="200px"><b>Description</b></td>
        <td><?php echo $indication_description; ?></td>
        <?php }?>
    </tr>

    <?php if($indication_type=='Medical') { ?>
    <tr>
            <?php if($indication_fullcourse) { ?>
        <td width="200px"><b>Full Course</b></td>
        <td><?php echo $indication_fullcourse; ?></td>
            <?php }?>
    </tr>
    <tr>
            <?php if($indication_medical['indication_cause']) { ?>
        <td width="200px"><b>Cause/s</b></td>
        <td><?php echo $indication_medical['indication_cause']; ?></td>
            <?php }?>
    </tr>
    <tr>
            <?php if($indication_medical['indication_diagnosis']) { ?>
        <td width="200px"><b>How to Arrive at Diagnosis </b></td>
        <td><?php echo $indication_medical['indication_diagnosis']; ?></td>
            <?php }?>
    </tr>
    <tr>
            <?php if($indication_medical['indication_materialtreatment']) { ?>
        <td width="200px"><b>Treatment (Herb and/or Other Material)</b></td>
        <td><?php echo $indication_medical['indication_materialtreatment']; ?></td>
            <?php }?>
    </tr>
    <tr>
            <?php if($indication_medical['indication_nonmaterialtreatment']) { ?>
        <td width="200px"><b>Treatment (Non-material)</b></td>
        <td ><?php echo $indication_medical['indication_nonmaterialtreatment']; ?></td>
            <?php }?>
    </tr>
    <tr>
            <?php if($indication_medical['indication_westerntreatment']) { ?>
        <td width="200px"><b>Treatment (Western Medicine)</b></td>
        <td><?php echo $indication_medical['indication_westerntreatment']; ?></td>
            <?php }?>
    </tr>

    <?php
    }
    else {
        ?>

    <tr>
		<?php if($indication_other['indication_antidote'] != ""){ ?>
			<td width="200px"><b>Antidote, if Indication is as Poison </td>
			<td><?php echo $indication_other['indication_antidote']; ?></td>
		<?php } ?>
    </tr>

    <?php
    } ?>
</table>