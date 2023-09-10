#pragma once

#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsAddNewUserScreen: protected clsScreen
{
private:

	

	static int _ReadPermissionsToSet(clsUser& User)
	{
		int Permission = 0;
		char Choice = 'n';

		cout << "\nDo You Want To Give Full Access[Y/N]? ";
		cin >> Choice;

		if (toupper(Choice) == 'Y')
		{
			return (short)clsUser::enMainMenuePermissions::eAll;
		}
		else
		{
			cout << "\nDo You Want To Give Access To : \n";

			cout << "Show Clients List [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pListClients;


			cout << "\nAdd New Client [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pAddNewClient;


			cout << "\nDelete Client [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pDeleteClient;

			cout << "\nUpdate Client [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pUpdateClients;

			cout << "\nFind Client [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pFindClient;

			cout << "\nTransactions [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pTranactions;

			cout << "\nManage Users [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pManageUsers;

			cout << "\nShow Login Registers? [Y/N]?";
			cin >> Choice;
			if (toupper(Choice) == 'Y')
				Permission += clsUser::enMainMenuePermissions::pListLoginRegister;
		}

		return Permission;
	}

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First Name: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "Enter Last Name: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "Enter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "Enter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "Enter Password: ";
		User.Password = clsInputValidate::ReadString();

		User.Permissions=_ReadPermissionsToSet(User);
	}

	static void _PrintUser( clsUser& User)
	{
		cout << "\nUser Info: \n";
		cout << clsUtil::Get_N_Chars('-', 15)<<"\n";
		cout << "User Name  : "<<User.UserName<<"\n";
		cout << "Full Name  : " << User.FullName() << "\n";
		cout << "Email      : " << User.Email << "\n";
		cout << "Phone      : " << User.Phone << "\n";
		cout << "Password   : " << User.Password << "\n";
		cout << "Permissions: " << User.Permissions << "\n";
		cout << clsUtil::Get_N_Chars('-', 15)<<"\n";
	}

	static void _AddNewUser()
	{
		cout << "\nEnter User Name: ";
		string UserName = clsInputValidate::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nThis UserName Already Found ,Enter Another One: ";
			 UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(NewUser);

		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}
		case clsUser::svFaildUserExists:
		{
			cout << "\nError account was not saved because User Name is used!\n";
			break;
		}
		}
	}


	public:
		static void AddNewUserScreen()
		{
			_DrawScreenHeader("\tAdd New User Screen");
			_AddNewUser();
		}
};

