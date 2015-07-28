<?php
$pagetitle = 'Informant Information';
require_once("configure.php");
$informantid = $_GET['informantid'];
$query = "SELECT * FROM informant WHERE informant_id ='$informantid'";

$result = mysql_query($query) or die("Query Failed!");

$informant = mysql_fetch_array($result, MYSQL_ASSOC);

if($informant) {
    extract($informant);
}
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


<h1><?php echo $pagetitle . " "; ?><a href="editinformant.php?informantid=<?php echo($informantid); ?>&studyid=<?php echo($studyid); ?>" class="viewLinks">[edit]</a></h1>

<table width="600px" style="margin-left: 50px;">
    <tr>
        <td width="200px"><b>Informant Name</b></td>
        <td><?php
            if($informant_lastname != "") { echo($informant_lastname); }
            if($informant_firstname != "") { echo(', ' . $informant_firstname); }
            if($informant_mi != "") { echo(' ' . $informant_mi . '.'); }
            ?></td>
    </tr>
    <tr>
        <?php if($informant_address != "") { ?>
        <td width="200px"><b>Address</b></td>
        <td><?php echo $informant_address; ?></td>
        <?php }?>
    </tr>

    <tr>
        <?php if($informant_birthday != "") { ?>
        <td width="200px"><b>Birth Date</b></td>
        <td><?php

                $bday = preg_split('/-/', $informant_birthday);

                echo($bday[0] . "" . date("M", $bday[1]) . "" . $bday[2]);
                ?></td>

    </tr>
    <tr>
        <td width="200px"><b>Age</b></td>
        <td><?php
                function computeAge($birth) {
                //parse birthday

                    $bday = preg_split('/-/', $birth);

                    $date[0] = date("Y");
                    $date[1] = date("m");
                    $date[2] = date("d");

                    $age = ($date[0]-$bday[0]) + ($date[1]-$bday[1])/12 + ($date[2]-$bday[2])/364.25;

                    echo((int)$age);
                }
                computeAge($informant_birthday);
                ?></td>
            <?php }?>
    </tr>
    <tr>
        <?php if($informant_sex != "") { ?>
        <td width="200px"><b>Sex </b></td>
        <td><?php echo $informant_sex; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_occupation != "") { ?>
        <td width="200px"><b>Occupation</b></td>
        <td><?php echo $informant_occupation; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_educationalattainment != "") { ?>
        <td width="200px"><b>Education Attainment</b></td>
        <td ><?php echo $informant_educationalattainment; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_maritalstatus != "") { ?>
        <td width="200px"><b>Marital Status</b></td>
        <td><?php echo $informant_maritalstatus; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_religion != "") { ?>
        <td width="200px"><b>Religion </b></td>
        <td><?php echo $informant_religion; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_type != "") { ?>
        <td width="200px"><b>Type</b></td>
        <td><?php echo $informant_type; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_healingpractice != "") { ?>
        <td width="200px"><b> Healing Practice</b></td>
        <td ><?php echo $informant_healingpractice; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_lengthofexperience != "") { ?>
        <td width="200px"><b> Length of Experience </b></td>
        <td><?php echo $informant_lengthofexperience; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_casehistory != "") { ?>
        <td width="200px"><b>Case History</b></td>
        <td><?php echo $informant_casehistory; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($informant_familymembers != "") { ?>
        <td width="200px"><b> Family Members</b></td>
        <td ><?php echo $informant_familymembers; ?></td>
        <?php }?>
    </tr>
    <?php
    $query2 = "SELECT * FROM informant_gatherer WHERE informant_id='$informantid'" ;
    $result2 = mysql_query($query2) or die("Query Failed!");
    echo("<tr>");
    echo("<td width='200px'><strong>Gatherer/s</strong></td>");
    echo("<td width='400px'>");
    $count = 0;

    while($informant_gatherer = mysql_fetch_array($result2, MYSQL_ASSOC)) {
        extract($informant_gatherer);
        $query3 = "SELECT * FROM gatherer WHERE gatherer_id=$gatherer_id" ;
        $result3 = mysql_query($query3) or die("Query Failed!");

        if(mysql_num_rows($result3) > 0) {
            while($gatherer = mysql_fetch_array($result3, MYSQL_ASSOC)) {
                extract($gatherer);
                $count++;
                echo ($count . '. ');
                if($gatherer_firstname != "") echo($gatherer_firstname);
                if($gatherer_mi != "") echo(' ' . $gatherer_mi . '.');
                if($gatherer_lastname!= "") echo(' ' . $gatherer_lastname);

                echo("<br />");

                if($count < mysql_num_rows($result)) {
                    echo("<br />");
                }
            }
        }
    }
    ?>
    <tr>
        <?php if($informant_dategathered != "") { ?>
        <td width="200px"><b> Date Gathered </b></td>
        <td><?php if($informant_dategathered != "0000-00-00") echo $informant_dategathered; else echo "-"?></td>
        <?php }?>
    </tr>


</table>