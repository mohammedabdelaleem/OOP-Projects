#pragma once

#include "clsUser.h"
#include "clsInputValidate.h"
#include"clsScreen.h"


class clsUpdateUserScreen :protected clsScreen
{

private:

    static void _PrintUser(clsUser& User)
    {
        cout << "\nUser Info: \n";
        cout << clsUtil::Get_N_Chars('-', 15) << "\n";
        cout << "User Name  : " << User.UserName << "\n";
        cout << "Full Name  : " << User.FullName() << "\n";
        cout << "Email      : " << User.Email << "\n";
        cout << "Phone      : " << User.Phone << "\n";
        cout << "Password   : " << User.Password << "\n";
        cout << "Permissions: " << User.Permissions << "\n";
        cout << clsUtil::Get_N_Chars('-', 15)<<"\n";
    }
  
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

    //Try To Separate Ui From A Class***************
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

        User.Permissions = _ReadPermissionsToSet(User);
    }

    static void _UpdateUser() {

        cout << "\nEnter Your User Name : ";
        string UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Name Not Found ,Enter Another One: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        char Choice = 'n';
        cout << "\nAre You Sure You Want To Update This Client Info[Y/N]?";
        cin >> Choice;

        if (toupper(Choice) != 'Y')
            return;

        cout << "\n\n--------------------------\n";
        cout << "Update Client Info: ";
        cout << "\n--------------------------\n";

        //This Function Will Update Client In Memory Not File
        _ReadUserInfo(User);


        //You Can Update Each Character At Object unless AccountNumber Read Only
      /*  Client.Email = "MY-Email@gmail.com";
        Client.Save();*/

        clsUser::enSaveResults SaveResults;
        SaveResults = User.Save();

        switch (SaveResults)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintUser(User);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }

        }
    }

public:
    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");
        _UpdateUser();
    }


};

