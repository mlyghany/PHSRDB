<?php
$pagetitle = 'Herbarium Information';
require_once("configure.php");
$herbariumid = $_GET['herbariumid'];
$query = "SELECT * FROM herbarium WHERE herbarium_id ='$herbariumid'";

$result = mysql_query($query) or die("Query Failed!");

$herbarium = mysql_fetch_array($result, MYSQL_ASSOC);
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


<h1><?php echo $pagetitle . " "; ?><a href="editherbarium.php?herbariumid=<?php echo($herbariumid); ?>&studyid=<?php echo($studyid); ?>" class="viewLinks">[edit]</a></h1>



<table width="600px" style='margin-left:50px;'>

    <tr>
        <?php if($herbarium['herbarium_scientificname']) { ?>
        <td width="200px"><b> Scientific Name </b></td>
        <td><?php echo $herbarium['herbarium_scientificname']; ?></td>
        <?php }?>
    </tr>
    <?php
    $query2 = "SELECT * FROM herbarium_othername WHERE herbarium_id='$herbariumid' && othername_type='Local'" ;
    $result2 = mysql_query($query2) or die("Query Failed!");

    if(mysql_num_rows($result2) > 0) {
        echo("<tr>");
        echo("<td width='200px'><strong>Local Names</strong></td>");
        echo("<td width='400px'>");
        $count = 0;

        while($herbarium_othername = mysql_fetch_array($result2, MYSQL_ASSOC)) {
            extract($herbarium_othername);
            if($othername_name == "") $othername_name = "Unnamed";
            echo ($count+1 . '. ');
            echo($othername_name);
            if($othername_language != "")
                echo('  (' . $othername_language . ')');
            echo("<br />");
            $count++;

            if($count < mysql_num_rows($result)) {
                echo("<br />");
            }
        }
    }
    $query3 = "SELECT * FROM herbarium_othername WHERE herbarium_id='$herbariumid' && othername_type='Foreign'" ;
    $result3 = mysql_query($query3) or die("Query Failed!");

    if(mysql_num_rows($result3) > 0) {
        echo("<tr>");
        echo("<td width='200px'><strong>Foreign Names</strong></td>");
        echo("<td width='400px'>");
        $count = 0;

        while($herbarium_othername = mysql_fetch_array($result3, MYSQL_ASSOC)) {
            extract($herbarium_othername);
            echo ($count+1 . '. ');
            echo($othername_name);
            echo('  (' . $othername_language . ')');
            echo("<br />");
            $count++;

            if($count < mysql_num_rows($result)) {
                echo("<br />");
            }
        }
    }

    $query4 = "SELECT * FROM herbarium_othername WHERE herbarium_id='$herbariumid' && othername_type='Common'" ;
    $result4 = mysql_query($query4) or die("Query Failed!");

    if(mysql_num_rows($result4) > 0) {
        echo("<tr>");
        echo("<td width='200px'><strong>Common Names</strong></td>");
        echo("<td width='400px'>");
        $count = 0;

        while($herbarium_othername = mysql_fetch_array($result4, MYSQL_ASSOC)) {
            extract($herbarium_othername);
            echo ($count+1 . '. ');
            echo($othername_name);
            echo('  (' . $othername_language . ')');
            echo("<br />");
            $count++;

            if($count < mysql_num_rows($result)) {
                echo("<br />");
            }
        }
    }
    ?>
    <tr>
        <?php if($herbarium['herbarium_fieldnumber']) { ?>
        <td width="200px"><b>Herbarium Field Number</b></td>
        <td><?php echo $herbarium['herbarium_fieldnumber']; ?></td>
        <?php }?>
    </tr>

    <tr>
        <?php if($herbarium['herbarium_number']) { ?>
        <td width="200px"><b>Herbarium Number</b></td>
        <td><?php echo $herbarium['herbarium_number']; ?></td>
        <?php }?>
    </tr>

    <tr>
        <?php if($herbarium['herbarium_collector']) { ?>
        <td width="200px"><b>Herbarium Collector </b></td>
        <td><?php echo $herbarium['herbarium_collector']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_collectornumber']) { ?>
        <td width="200px"><b>Collector Number</b></td>
        <td><?php echo $herbarium['herbarium_collectornumber']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_geographicarea']) { ?>
        <td width="200px"><b>Geographic Area</b></td>
        <td ><?php echo $herbarium['herbarium_geographicarea']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_latitude']) { ?>
        <td width="200px"><b>Latitude</b></td>
        <td><?php echo $herbarium['herbarium_latitude']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_habitat']) { ?>
        <td width="200px"><b>Habitat </b></td>
        <td><?php echo $herbarium['herbarium_habitat']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_altitude']) { ?>
        <td width="200px"><b>Altitude</b></td>
        <td><?php echo $herbarium['herbarium_altitude']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_habit']) { ?>
        <td width="200px"><b> Habit</b></td>
        <td ><?php echo $herbarium['herbarium_habit']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_height']) { ?>
        <td width="200px"><b> Height </b></td>
        <td><?php echo $herbarium['herbarium_height']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_diamater']) { ?>
        <td width="200px"><b>Diameter of Trunk</b></td>
        <td><?php echo $herbarium['herbarium_diameter']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_flower']) { ?>
        <td width="200px"><b> Flower</b></td>
        <td ><?php echo $herbarium['herbarium_flower']; ?></td>
        <?php }?>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_fruit']) { ?>
        <td width="200px"><b> Fruit </b></td>
        <td><?php echo $herbarium['herbarium_fruit']; ?></td>
        <?php }?>
    </tr>

    <tr>
        <td width="200px"><b>Herbarium Identifier's Name</b></td>
        <td><?php if($herbarium['herbarium_identifierlastname'] != "")
                echo $herbarium['herbarium_identifierlastname'] . ', ';
            echo $herbarium['herbarium_identifierfirstname'] . ' ';
            if($herbarium['herbarium_identifiermi'] != " ") echo $herbarium['herbarium_identifiermi'];
            if ($herbarium['herbarium_identifierlastname'] == "" && $herbarium['herbarium_identifierfirstname'] == "" && $herbarium['herbarium_identifiermi'] == "") echo "-";?></td>
    </tr>
    <tr>
        <?php if($herbarium['herbarium_dateofidentification']) { ?>
        <td width="200px"><b>Date Of Identification</b></td>
        <td><?php if($herbarium['herbarium_dateofidentification'] != "0000-00-00") echo $herbarium['herbarium_dateofidentification']; else echo"-"?></td>
        <?php }?>
    </tr>

    <tr>
        <?php if($herbarium['herbarium_specimenkeptat']) { ?>
        <td width="200px"><b> Specimen Voucher Kept At</b></td>
        <td ><?php echo $herbarium['herbarium_specimenkeptat']; ?></td>
        <?php }?>
    </tr>
</table>