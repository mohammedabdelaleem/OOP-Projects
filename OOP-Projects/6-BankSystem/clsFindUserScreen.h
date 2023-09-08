#pragma once

#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsFindUserScreen :protected clsScreen
{
private:

    enum enSearchBy {
        sUsername = 1, sUsernameAndPassword = 2
    };

    static void _PrintUser(clsUser& User)
    {
        cout << "\nUser Info: \n";
        cout << clsUtil::Get_N_Chars('-', 15)<<"\n";
        cout << "User Name  : " << User.UserName << "\n";
        cout << "Full Name  : " << User.FullName() << "\n";
        cout << "Email      : " << User.Email << "\n";
        cout << "Phone      : " << User.Phone << "\n";
        cout << "Password   : " << User.Password << "\n";
        cout << "Permissions: " << User.Permissions << "\n";
        cout << clsUtil::Get_N_Chars('-', 15)<<"\n";
    }

    static void _PerformSearchBy(enSearchBy Choice)
    {
        switch (Choice)
        {

        case enSearchBy::sUsername:
        {
            cout << "Enter Your User Name: ";
            string UserName = clsInputValidate::ReadString();

            clsUser User = clsUser::Find(UserName);
            if (!User.IsEmpty())
            {
                cout << "\nUser Found :-)\n";
                cout << "-----------------------\n\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nUser Was not Found :-(\n";
            }
            break;
        }

        case enSearchBy::sUsernameAndPassword:
        {
            cout << "Enter Your User Name: ";
            string UserName = clsInputValidate::ReadString();

            cout << "Enter Your Password: ";
            string Password = clsInputValidate::ReadString();

            clsUser User = clsUser::Find(UserName, Password);
            if (!User.IsEmpty())
            {
                cout << "\nUser Found :-)\n";
                cout << "-----------------------\n\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nUser Was not Found :-(\n";
            }
            break;
        }
        }
    }

    static void _PerformFindUser()
    {
        
        cout << endl << setw(37) << left << "" << "[1]Search By User Name.\n";
        cout << setw(37) << left << "" << "[2]Search By User Name And Password .\n";
        cout << setw(37) << left << "" << clsUtil::Get_N_Chars('-', 50) << "\n";
        cout << setw(37) << left << "";
        _PerformSearchBy( (enSearchBy)clsInputValidate::ReadShortNumberBetween(1, 2));
    }


public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\tFind User Screen");
        _PerformFindUser();
    }

};

