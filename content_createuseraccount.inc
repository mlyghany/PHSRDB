			<?php $pagetitle = 'Create User Account'; ?>
				<!---pag nag aadd ka ng content, etong div lang na ito ang babaguhin.^^--->
				<div name="contentBox" style="background: transparent;">
					<h1><?php echo $pagetitle;?></h1>
					
					<form name="userAccount" id="userAccount" method="post" action="./createuseraccountentry.php">
						<table width="650px" style="margin-left: 50px; text-align: left;">
							<tr>
								<td colspan="2"><h3>Account Details</h3></td>
							</tr>
							<tr>
								<td width="200px">
									Username:
								</td>
								
								<td width="450px">
									<input type="text" name="username" size="40" class="inputBox"/>*
								</td>
							</tr>
							<tr>
								<td width="200px">
									Password:
								</td>
								
								<td width="450px">
									<input type="password" name="password" size="40" class="inputBox"/>*
								</td>
							</tr>
							<tr>
								<td width="200px">
									Retype Password:
								</td>
								
								<td width="450px">
									<input type="password" name="retype" size="40" class="inputBox"/>*
								</td>
							</tr>
							<tr>
								<td width="200px">
									E-mail Address:
								</td>
								
								<td width="450px">
									<input type="text" name="email" size="40" class="inputBox"/>
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
									<input type="text" name="title" size="5" class="inputBox"/>
								</td>
							</tr>
							<tr>
								<td width="200px">
									First Name:
								</td>
								
								<td width="450px">
									<input type="text" name="firstname" size="40" class="inputBox"/>*
								</td>
							</tr>
							<tr>
								<td width="200px">
									Last Name:
								</td>
								
								<td width="450px">
									<input type="text" name="lastname" size="40" class="inputBox"/>*
								</td>
							</tr>
							<tr>
								<td width="200px">
									Middle Initial:
								</td>
								
								<td width="450px">
									<input type="text" name="middleinitial" size="10" class="inputBox"/>
								</td>
							</tr>
							
							<tr>
								<td width="200px">
									Sex:
								</td>
								
								<td width="450px">
									<select name="sex" class="inputBox" />
										<option value="M">Male</option>
										<option value="F">Female</option>
									</select>
								</td>
							</tr>
							<tr>
								<td width="200px">
									Birthday:
								</td>
								
								<td width="450px">
									<input type="text" name="birthday" size="20" class="inputBox"/>
									<script language="JavaScript">
									new tcal ({
										// form name
										'formname': 'userAccount',
										// input name
										'controlname': 'birthday'
									});
									</script>
								</td>
							</tr>
							<tr>
								<td width="200px">
									Address:
								</td>
								
								<td width="450px">
									<input type="text" name="address" size="20" class="inputBox"/>
								</td>
							</tr>
							<tr>
								<td width="200px">
									Location:
								</td>
								
								<td width="450px">
									<input type="text" name="location" size="20" class="inputBox"/>
								</td>
							</tr>
							<tr>
								<td width="200px">
									Occupation:
								</td>
								
								<td width="450px">
									<input type="text" name="occupation" size="20" class="inputBox"/>
								</td>
							</tr>
							<tr>
								<td width="200px">
									Work Address:
								</td>
								
								<td width="450px">
									<input type="text" name="workaddress" size="20" class="inputBox"/>
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
			
		