<?php
	$pagetitle = 'Reseach Database';
	require_once("configure.php");
?>

<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
				<div name="contentBox" style="background: transparent;">
					<h1><?php echo $pagetitle ?></h1>
					<p style="margin-left:10px;">These are the available studies as of the moment:</p>
					<!--SECTION 1: DISPLAY LIST OF ETHNOPHARMACOLOGICAL STUDIES-->
					<h3 style="margin-left:20px;">A. Ethnopharmacological</h3>
						<ul>
						<?php
						$query = "SELECT * FROM study where study_database = 'Ethnopharmacological' ORDER BY study_title";
						$result = mysql_query($query) or die("Query Failed!");
							while ($study = mysql_fetch_array($result, MYSQL_ASSOC)) { ?>
									<li><a href="viewresearch.php?studyid=<?php echo $study['study_id']; ?>">
									 &nbsp; <?php echo $study['study_title'];?></li></a><?php } ?>
						</ul>
					<!--END OF SECTION 1-->
					<!--SECTION 2: DISPLAY LIST OF BIOLOGICAL STUDIES-->
					<h3 style="margin-left:20px;">B. Biological</h3>
						<ul>
						<?php
							$query2 = "SELECT * FROM study where study_database = 'Biological' ORDER BY study_title ";
							$result2 = mysql_query($query2) or die("Query Failed!");
							while ($study = mysql_fetch_array($result2, MYSQL_ASSOC)) { ?>
									<li><a href="viewresearch.php?studyid=<?php echo $study['study_id']; ?>">
									 &nbsp; <?php echo $study['study_title'];?></li></a>	<?php } ?>
						</ul>
					</div>
					<!--END OF SECTION 2-->
				</div>