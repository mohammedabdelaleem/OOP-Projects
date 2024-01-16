#pragma once

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

class clsUsersListScreen :protected clsScreen
{

	static void _PrintShowUsersHeader(short NumberOfUsers)
	{
		string Title = "\tUsers List Screen.";
		string SubTitle = "\t  (" + to_string(NumberOfUsers) + ") User(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << clsUtil::Get_N_Chars('-', 96)<<"\n";
		cout << setw(8) << left << "" << "|" << setw(10) << left << "User Name";
		cout << "|" << setw(25) << left << "Full Name";
		cout << "|" << setw(12) << left << "Phone";
		cout << "|" << setw(20) << left << "Email";
		cout << "|" << setw(11) << left << "Password";  
		cout << "|" << setw(12) << left << "Permissions"<<"|\n";
		cout << setw(8) << left << "" << clsUtil::Get_N_Chars('-', 96) << "\n";

	}

	static void _PrintUsersRecordLine(clsUser& User)
	{
		cout << setw(8) << left << "" << "|" << setw(10) << left << User.UserName;
		cout << "|" << setw(25) << left << User.FullName();
		cout << "|" << setw(12) << left << User.Phone;
		cout << "|" << setw(20) << left << User.Email;
		cout << "|" << setw(11) << left << User.Password;
		cout << "|" << setw(12) << left << User.Permissions << "|\n";
		cout << setw(8) << left << "" << clsUtil::Get_N_Chars('-', 96) << "\n";
	}

public:
	static void ShowUsersListScreen()
	{
		vector<clsUser>vUsers = clsUser::GetUsersList();
		_PrintShowUsersHeader(vUsers.size());

		if (vUsers.size())
		{
			for (clsUser& User : vUsers)
			{
				_PrintUsersRecordLine(User);
			}
		}
		else {
			cout << "\nNo Users Avilable In The System\a\n";
		}
	}

};

