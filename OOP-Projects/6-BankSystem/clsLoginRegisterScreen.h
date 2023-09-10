#pragma once

#include"clsUser.h"
#include"clsScreen.h"
#include"clsUtil.h"

class clsLoginRegisterScreen:protected clsScreen
{
private:

	static void PrintRegisterdUsersListHeader(short NumberOfRegisterdUsers)
	{
		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t    (" + to_string(NumberOfRegisterdUsers) + ") Registerd User(s). ";

		system("cls");
		_DrawScreenHeader(Title,SubTitle);

		cout << setw(9) << left << "" << clsString::Get_N_Chars('=', 71) << "\n";
		cout << setw(9) << left << "" << "| " << setw(30) << left << "Date/Time" << "| " << setw(10) << left << "User Name" << "| " << setw(11) << left << "Password" << "| " << setw(12) << left << "Permissions" << "|\n";
		cout << setw(9) << left << "" << clsString::Get_N_Chars('=', 71) << "\n";
}


	static void PrintRegisterdUserLine(clsUser::stLoginRegisterRecord RegisterdUserRecord)
	{
		cout << setw(9) << left << "" << "| " << setw(30) << left << RegisterdUserRecord.DateTime << "| " << setw(10) << left << RegisterdUserRecord.UserName << "| " << setw(11) << left << RegisterdUserRecord.Password << "| " << setw(12) << left << RegisterdUserRecord.Permissions << "|\n";
		cout << setw(9) << left << "" << clsString::Get_N_Chars('-', 71) << "\n";
	}


public:
	static void ShowRegisterdUsersList()
	{	
		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pListLoginRegister))
		{
			return;
		}

		vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecords= clsUser::GetLoginRegisterList();

		if (vLoginRegisterRecords.size())
		{
			PrintRegisterdUsersListHeader(vLoginRegisterRecords.size());

			for (clsUser::stLoginRegisterRecord& RegisterdUserRecord : vLoginRegisterRecords)
			{
				PrintRegisterdUserLine(RegisterdUserRecord);
			}
		}
		else
			cout << "\n\t\tNo Logins Available In The System\a\n";
	}
};

