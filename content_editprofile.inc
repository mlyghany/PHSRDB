<?php $pagetitle = 'Edit User Account'; 
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

    <form name="userAccount" id="userAccount" method="post" action="./edituseraccountentry.php">
        <?php
        echo "<input type=\"hidden\" name=\"researcherid\" size=\"40\" value = \"". $researcher_id . "\"/>";
        echo "<input type=\"hidden\" name=\"memberid\" size=\"40\" value = \"". $member_id . "\"/>";
        ?>
        <table width="650px" style="margin-left: 50px; text-align: left;">
            <tr>
                <td colspan="2"><h3>Account Details</h3></td>
            </tr>
            <tr>
                <td width="200px">
									Username:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"username\" size=\"40\" class=\"inputBox\" value = \"". $researcher_username . "\"/>*";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
									E-mail Address:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"email\" size=\"40\" class=\"inputBox\" value = \"". $researcher_email . "\"/>";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
                </td>
                <td width="450px">
                    <a href= "changepassword.php"><strong><em>Change your password</em></strong></a>
                </td>
            </tr>
            <tr>
                <td colspan="2"><h3>Personal Information</h3></td>
            </tr>
            <tr>
                <td width="200px">
									Title:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"title\" size=\"40\" class=\"inputBox\" value = \"". $researcher_title . "\"/>";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
									First Name:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"firstname\" size=\"40\" class=\"inputBox\" value = \"". $researcher_firstname . "\"/>*";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Last Name:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"lastname\" size=\"40\" class=\"inputBox\" value = \"". $researcher_lastname . "\"/>*";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Middle Initial:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"middleinitial\" size=\"40\" class=\"inputBox\" value = \"". $researcher_mi . "\"/>";
                    ?>
                </td>
            </tr>

            <tr>
                <td width="200px">
									Sex:
                </td>

                <td width="450px">
                    <select name="sex" class="inputBox">
                    <option value="M" <?php if($researcher_sex == 'M') echo "selected";?>>Male</option>";
                    <option value="F" <?php if($researcher_sex == 'F') echo "selected";?>>Female</option>";
                    </select>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Birthday:
                </td>

                <td width="450px">
                    <input type="text" name="birthday" size="20" class="inputBox"/>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Address:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"address\" size=\"40\" class=\"inputBox\" value = \"";
                    if(!$researcher_address == "0") echo $researcher_address;
                    echo "\"/>";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Location:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"location\" size=\"40\" class=\"inputBox\" value = \"". $researcher_location . "\"/>";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Occupation:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"occupation\" size=\"40\" class=\"inputBox\" value = \"". $researcher_occupation . "\"/>";
                    ?>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Work Address:
                </td>

                <td width="450px">
                    <?php
                    echo "<input type=\"text\" name=\"workaddress\" size=\"40\" class=\"inputBox\" value = \"". $researcher_workAddress . "\"/>";
                    ?>
                </td>
            </tr>

            <tr>
                <td colspan="2"><br/><br/>* Required Fields</td>
            </tr>
            <tr>
                <td colspan="2" style="text-align: center;"><input type="submit" value="Submit"></td>
            </tr>

        </table>
    </form>
</div>

