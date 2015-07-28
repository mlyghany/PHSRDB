<?php 
require_once("configure.php");
$query = "SELECT * FROM members ORDER BY member_since ASC";
$result = mysql_query($query) or die("Query Failed!");

$i = 0;
echo ("<h1>Approved Accounts</h1>");
?>
<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
<div name="contentBox" style="background: transparent;">
    <table id='approvedUserAccountsTable' style = "margin-left: 50px;" width="500px">
        <tr>
            <td width="40" align="right"></td>
            <td width="120" align="center"><strong>Username</strong></td>
            <td width="120" align="center"><strong>Member Type</strong></td>
            <td width="120" align="center"><strong>Date Approved</strong></td>
        </tr>
        <tr>
            <td width="40" align="right">&nbsp;</td>
            <td width="120" align="center">&nbsp;</td>
            <td width="120" align="center">&nbsp;</td>
            <td width="120" align="center">&nbsp;</td>
        </tr>
        <?php
        while ($row = mysql_fetch_assoc($result)) {
            $i++;
            echo "<tr>";
            echo "<td width='40' align='right'>" . $i. "</td>";
            echo "<td width='120' align='center'>" . $row['member_username'] . "</td>";
            echo "<td width='120' align='center'>" . $row['member_type'] . "</td>";
            echo "<td width='120' align='center'>" . $row['member_since'] . "</td>";
            echo "</tr>";
        }
        if($i == 0) echo("<tr><td><em>There are no approved accounts to display.</em></td></tr>");

        ?>
    </table>
</div>
