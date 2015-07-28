	<?php 
		$member = $_SESSION['member'];
		if($member){
			extract($member);
		}
	?>
	<table class="post1" width="900px" align="center">
	<thead>
		<tr>
			<td colspan="2" width="900px">
				<img src="./images/banner.gif" width="900px"/>
			</td>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td colspan="2">
				<strong>
					<table align="left" id="navigation1" width="900px">
						<tbody>
							<tr>
								<td width="80px">&nbsp;<a href="main.php">| Home |</a>&nbsp;</td>
								<td width="80px">&nbsp;<a href="about.php">| About |</a>&nbsp;</td>
								<td width="100px">&nbsp;<a href="researchdatabase.php">| Database |</a>&nbsp;</td>
								<td width="660px">
									<form name="search" method="post" action="./quicksearch.php">
										<table id="qs" align="left">
											<tbody>
												<tr>
													<td width="105px"><strong><font color="#005826">| Quick Search |</font></strong></td>
													<td><select name="source">
															<option value="">All Databases</option>
															<option value="Ethnopharmacological">Ethnopharmacological Study</option>
															<option value="Biological">Biological Activity</option>
														</select>
													</td>
													<td>
														<input type="text "size="20px" name="search"/>
													</td>
													<td><button name="Search" value="submit" /> Search</td>
													<td><a href="./advancedsearch.php"><u> Advanced Search</u>&nbsp;</a></td>
													<td><a href="#"><u> Help </u></a></td>
												</tr>
											</tbody>
										</table>
									</form>
								</td>
							</tr>
						</tbody>
					</table>
				</strong>
			</td>
				
		</tr>
		<tr>
			<td colspan="1" class="shortcutBox">
				<div>
					<?php if($member == ''){
						include("login_form.html");		
					}
					else{
						if($member_type=="admin"){
					?>
					<p><strong><?php echo("Welcome " . ucfirst($member_username)  . "!"); ?></strong></p>
					<ul class="par">
						<li><a href="./approveresearcher.php" class="link2">Approve Researcher Accounts</a><br /></li>
						<li><a href="./logout.php" class="link2">Logout</a><br /></li>
					</ul>
					<?php }
						else{
					?>
					<p><strong><?php echo("Welcome " . ucfirst($member_username)  . "!"); ?></strong></p>
					<ul class="par">
						<li><a href="addresearch.php" class="link2">Add Research Entry</a><br /></li>
						<li><a href="./editprofile.php" class="link2">Edit Profile</a><br /></li>
						<li><a href="logout.php" class="link2">Logout</a><br /></li>

					</ul>
					<?php }} ?>
					
					<p><strong><font color="#FFF568"><u>Research:</u></font></strong></p>
					<ul class="par">
						<li><a href="#" class="link2">Research Prototype Protocols</a><br /></li>
						<li><a href="./researchdatabase.php" class="link2">Research Databases </a><br /></li>
						<li><a href="./viewresearcher.php" class="link2">Researchers </a><br /></li>
						<li><a href="#" class="link2">Researcher Institutions</a><br /></li>
						<li><a href="#" class="link2">Funding Agencies </a><br /></li>
						<li><a href="#" class="link2">Other Resources </a></li>
					</ul>
					<p><strong><font color="#FFF568"><u>Information:</u></font></strong></p>
					<ul class="par">
						<li><a href="#" class="link2">Public Information </a><br /></li>
						<li><a href="#" class="link2">Health Care Provider Guidelines</a><br /></li>
						<li><a href="#" class="link2">Policy Briefs </a><br /></li>
						<li><a href="#" class="link2">Media Advisories </a><br /></li>
						<li><a href="#" class="link2">Monographs </a><br /></li>
					</ul>
					<p><strong><font color="#FFF568"><u>Archives & Publications:</u></font></strong></p>
					<ul class="par">
						<li><a href="#" class="link2">Books & Manuscripts </a><br /></li>
						<li><a href="#" class="link2">Product Archives </a><br /></li>
						<li><a href="#" class="link2">Regulations </a><br /></li>
						<li><a href="#" class="link2">Media Advisories </a><br /></li>
						<li><a href="#" class="link2">Industry & Market News</a><br /></li>
					</p>
				</div>
			</td>
			<td colspan="1" class="content">
			