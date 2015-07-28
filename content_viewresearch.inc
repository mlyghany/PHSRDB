<?php 
require_once("configure.php");

$studyid = $_GET['studyid'];
$studydatabase = $_GET['studydatabase'];

$query = "SELECT * FROM study WHERE study_id= '$studyid' ";
$result = mysql_query($query) or die("Query Failed!");
$study = mysql_fetch_array($result, MYSQL_ASSOC);
if($study) extract($study);

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

    <!--GENERAL ETHNOPHARMACOLOGICAL FRAMEWORK-->
    <h1>General Ethnopharmacological Frameworks <?php if($member_id == $researcher_id) {?><a href="addmaterial.php?studyid=<?php echo($studyid); ?>" class="viewLinks">[add]</a><?php } ?></h1>

    <?php
    $query = "SELECT DISTINCT * FROM study_material WHERE study_id='$studyid'";
    $result = mysql_query($query) or die("Query Failed!");
    $count = 0;
    while($materialdetail = mysql_fetch_array($result, MYSQL_ASSOC)) {
        extract($materialdetail);
        $query2 = "SELECT * FROM material where material_id='$material_id'";
        $result2 = mysql_query($query2) or die("Query Failed!");

        $count++;

        $material = mysql_fetch_array($result2, MYSQL_ASSOC);
        if($material) {
            extract($material);

            echo("<a href='./viewmaterial.php?materialid=$material_id' style='margin-left: 50px;'>");
            echo("Material No. $material_id");
            echo("</a>");

        }

        if($count < mysql_num_rows($result)) {
            echo("<br />");
        }
    }
    ?>

    <br /><br />
    <!--END OF GENERAL ETHNOPHARMACOLOGICAL FRAMEWORK-->

    <!--HERBARIUM FRAMEWORK-->
    <h1>Herbarium Frameworks <?php if($member_id == $researcher_id) {?><a href="addherbarium.php?studyid=<?php echo($studyid); ?>" class="viewLinks">[add]</a><?php } ?></h1>

    <?php
    $query = "SELECT DISTINCT * FROM study_herbarium WHERE study_id='$studyid'";
    $result = mysql_query($query) or die("Query Failed!");
    $count = 0;
    while($herbariumdetail = mysql_fetch_array($result, MYSQL_ASSOC)) {
        extract($herbariumdetail);
        $query2 = "SELECT * FROM herbarium where herbarium_id='$herbarium_id'";
        $result2 = mysql_query($query2) or die("Query Failed!");

        $count++;

        $herbarium = mysql_fetch_array($result2, MYSQL_ASSOC);
        if($herbarium) {
            extract($herbarium);

            echo("<a href='./viewherbarium.php?herbariumid=$herbarium_id&studyid=$studyid' style='margin-left: 50px;'>");
            if($herbarium_scientificname != "") echo(ucfirst($herbarium_scientificname));
            echo("</a>");

        }

        if($count < mysql_num_rows($result)) {
            echo("<br />");
        }
    }
    ?>
    <br /><br />
    <!--END OF HERBARIUM FRAMEWORK-->

    <!--INDICATION FRAMEWORK-->
    <h1>Indication Frameworks <?php if($member_id == $researcher_id) {?><a href="addindication.php?studyid=<?php echo($studyid); ?>" class="viewLinks">[add]</a><?php } ?></h1>
    <?php
    $query = "SELECT DISTINCT * FROM study_indication WHERE study_id='$studyid'";
    $result = mysql_query($query) or die("Query Failed!");
    $count = 0;
    while($indicationdetail = mysql_fetch_array($result, MYSQL_ASSOC)) {
        extract($indicationdetail);
        $query2 = "SELECT * FROM indication where indication_id='$indication_id'";
        $result2 = mysql_query($query2) or die("Query Failed!");

        $count++;

        $indication = mysql_fetch_array($result2, MYSQL_ASSOC);
        if($indication) {
            extract($indication);

            echo("<a href='./viewindication.php?indicationid=$indication_id&studyid=$studyid' style='margin-left: 50px;'>");
            if($indication_name != "") echo(ucfirst($indication_name));
            echo("</a>");

        }

        if($count < mysql_num_rows($result)) {
            echo("<br />");
        }
    }
    ?>
    <br /><br />
    <!--END OF INDICATION FRAMEWORK-->

    <!--INFORMANT FRAMEWORK-->
    <h1>Informant Frameworks <?php if($member_id == $researcher_id) {?><a href="addinformant.php?studyid=<?php echo($studyid); ?>" class="viewLinks">[add]</a><?php } ?></h1>

    <?php
    $query = "SELECT DISTINCT * FROM study_informant WHERE study_id='$studyid'";
    $result = mysql_query($query) or die("Query Failed!");
    $count = 0;
    while($informantdetail = mysql_fetch_array($result, MYSQL_ASSOC)) {
        extract($informantdetail);
        $query2 = "SELECT * FROM informant where informant_id='$informant_id'";
        $result2 = mysql_query($query2) or die("Query Failed!");

        $count++;

        $informant = mysql_fetch_array($result2, MYSQL_ASSOC);
        if($informant) {
            extract($informant);

            echo("<a href='./viewinformant.php?informantid=$informant_id&studyid=$studyid' style='margin-left: 50px;'>");
            if($informant_lastname != "") echo(ucfirst($informant_lastname));
            if($informant_firstname != "") echo(", " . ucfirst($informant_firstname));
            if($informant_mi != "") echo(" " . ucfirst($informant_mi) . ".");
            echo("</a>");

        }

        if($count < mysql_num_rows($result)) {
            echo("<br />");
        }
    }
    ?>

    <br /><br />
    <!--END OF INFORMANT FRAMEWORK-->
</div>

