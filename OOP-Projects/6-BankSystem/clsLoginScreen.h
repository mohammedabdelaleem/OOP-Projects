#pragma once

#include"clsScreen.h"
#include"clsUser.h"
#include"clsMainScreen.h"

#include"Global.h"

class clsLoginScreen:protected clsScreen
{
static	void _Login()
	{

		bool LoginFaild = false;
		string UserName, Password;

		do
		{

			if (LoginFaild)
			{
				cout << "\nInvalid UserName/Password!\n\n";
			}

			cout << "Enter UserName : ";
			UserName=clsInputValidate::ReadString();

			cout << "Enter Password : ";
			Password = clsInputValidate::ReadString();

			//I Define CurrentUser And Make It Globaly For The Whole System.
			//I Need Its Accessability From The Whole Classes To Him. 
			//Each Class Incude [#include"Global.h"] Can Access The Current User. 
			 CurrentUser=clsUser::Find(UserName, Password);
			 LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		clsMainScreen::ShowMainMenu();
	}



public:

	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		_Login();

	}
	
};

