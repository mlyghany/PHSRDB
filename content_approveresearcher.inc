			<?php $pagetitle = 'Approve Researcher Accounts'; ?>
				<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
				<div name="contentBox" style="background: transparent;">
					<h1><?php echo $pagetitle;?></h1>
					
					<p style="margin-left: 30px;"><strong><br />The following people are requesting researcher access to our website:</strong></p>
					
					<?php
						require_once("./configure.php");
						$query = "SELECT * from researcher WHERE researcher_approveFlag = 'D'";
						$result = mysql_query($query);
					?>
					
					<table width="500px" style="text-align: center; margin-left: 50px;">
					<?php
						if(mysql_num_rows($result) > 0){
							while($researcher = mysql_fetch_array($result)){
								extract($researcher);
								echo("<tr>");
								echo("<td style='text-align: left'><b><a href='./viewresearcherinfo.php?researcherid=" . $researcher_id . "'>" . $researcher_lastname . ", " . $researcher_firstname . " ");
								if($researcher_mi != "") echo $researcher_mi . ".";
								echo("</a></b></td>");
								echo("<td><a href='./approveprocess.php?id=$researcher_id'>Approve</a></td>");
								echo("<td><a href='./denyprocess.php?id=$researcher_id'>Deny</a></td>");
								echo("</tr>");
							}
						}
						else{
							echo("<tr align='left'><td><br/><br /><em>No more pending accounts are waiting for approval.</em></td></tr>");
						}
						?>
					</table>
					</div>
			
		