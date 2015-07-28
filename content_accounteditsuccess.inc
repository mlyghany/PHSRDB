<?php 
    $pagetitle = 'Account Edit Successful';
    require_once("configure.php");
    $query = "SELECT * FROM members WHERE member_id = '$member_id' ";
    $result = mysql_query($query) or die("Query Failed!");
    $member = mysql_fetch_array($result, MYSQL_ASSOC);
    extract($member);

    $query = "SELECT * FROM researcher WHERE researcher_username = '$member_username' ";
    $result = mysql_query($query) or die("Query Failed!");
    $researcher = mysql_fetch_array($result, MYSQL_ASSOC);
    extract($researcher);
?>
<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <h1><?php echo $pagetitle;?></h1>
    <p style="margin-left:30px;">To view your profile, click <?php echo"<a href=\"./viewresearcherinfo.php?researcherid=". $researcher_id . "\"><strong>here</strong>."; ?></a></p>
    <p style="margin-left:30px;"><strong>Welcome to the Philippine Herbs and Supplements Research Website.</strong></p>
    <p style="text-indent:15px; margin-left:40px; margin-right:35px;">
					The Philippine Herbs and Supplements Research Database hosts objective and updated information for the purposes of researchers, health care providers, the public, and the policy makers who are interested in herbs and supplements.</p>
    <p style="text-indent:15px; margin-left:40px; margin-right:35px;">
					The goal of this website is to ensure the effective and efficient collection, 
					synthesis, and dissemination of information on herbal medicine research and development.</p>
</div>

