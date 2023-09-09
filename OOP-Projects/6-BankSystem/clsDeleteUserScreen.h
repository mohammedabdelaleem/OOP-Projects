#pragma once

#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsDeleteUserScreen:protected clsScreen
{

private:

	static void _PrintUser(clsUser& User)
	{
		cout << "\nUser Info: \n";
		cout << clsUtil::Get_N_Chars('-', 15)<< "\n";
		cout << "User Name  : " << User.UserName << "\n";
		cout << "Full Name  : " << User.FullName() << "\n";
		cout << "Email      : " << User.Email << "\n";
		cout << "Phone      : " << User.Phone << "\n";
		cout << "Password   : " << User.Password << "\n";
		cout << "Permissions: " << User.Permissions << "\n";
        cout << clsUtil::Get_N_Chars('-', 15) << endl;
	}


    static void _DeleteUser()
    {
        cout << "\nEnter A User Name : ";
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Not Found ,Enter Another One: ";
            UserName = clsInputValidate::ReadString();
        }

        //Can't Remove The Admin.
        if (UserName == "Admin")
        {
            cout << "\n\nCan't Remove The Admin.\a\n";
            return;
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        char Choice = 'n';
        cout << "Are You Sure To Delete This User? [Y/N] ";
        cin >> Choice;

        if (toupper(Choice) == 'Y')
        {
            if (User.Delete())// Client Will Be Empty 
            {
                cout << "\nClient Deleted Successfully.\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError Client Wasn't Deleted.\n\a";
            }
        }

    }


public:

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen.");
        _DeleteUser();
    }
};



