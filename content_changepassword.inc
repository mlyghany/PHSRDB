<?php 
    $pagetitle = 'Change Password';
    require_once("./configure.php");

    $query = "SELECT * FROM members WHERE member_id = '$member_id' ";
    $result = mysql_query($query) or die("Query Failed!");
    $member = mysql_fetch_array($result, MYSQL_ASSOC);
    extract($member);

    $query = "SELECT * FROM researcher WHERE researcher_username = '$member_username' ";
    $result = mysql_query($query) or die("Query Failed!");
    $researcher = mysql_fetch_array($result, MYSQL_ASSOC);
    extract($researcher);
?>
<html>
<head>
    <script type="text/javascript">
        function verify(F, orig){
            if(F.currentpassword.value != orig)
                alert('You did not enter the correct password.');
            else if(F.newpassword.value == '' || F.retype.value == '')
                alert('Do not leave empty fields.');
            else if(F.newpassword.value != F.retype.value)
                alert('The new password you entered did not match.');
            else return true;
            return false;
        }
    </script>
</head>
<body>
    <!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
    <div name="contentBox" style="background: transparent;">
        <h1><?php echo $pagetitle;?></h1>
        <?php
        echo "<form name=\"changePwd\" id=\"changePwd\" method=\"POST\" action=\"./changepasswordentry.php\" onsubmit=\"return verify(this, '" . $researcher_retype . "')\">";
        echo "<input type=\"hidden\" name=\"researcherid\" size=\"40\" value = \"". $researcher_id . "\"/>";
        echo "<input type=\"hidden\" name=\"memberid\" size=\"40\" value = \"". $member_id . "\"/>";
        ?>
        <table width="650px" style="margin-left: 50px; text-align: left;">
            <tr>
                <td width="200px">
									Current Password:
                </td>

                <td width="450px">
                    <input type="password" name="currentpassword" id="currentpassword" size="40" class="inputBox"/>
                </td>
            </tr>
            <tr>
                <td width="200px">
									New Password:
                </td>

                <td width="450px">
                    <input type="password" name="newpassword" id="newpassword" size="40" class="inputBox"/>
                </td>
            </tr>
            <tr>
                <td width="200px">
									Retype Password:
                </td>

                <td width="450px">
                    <input type="password" name="retype" id="retype" size="40" class="inputBox"/>
                </td>
            </tr>
            <tr>

                <td colspan="2" style="text-align: center;"><input type="submit" value="Submit"></td>

            </tr>
        </table>
    </form>
</div>
</body>
</html>