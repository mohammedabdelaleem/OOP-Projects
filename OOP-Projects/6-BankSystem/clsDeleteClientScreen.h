#pragma once

#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsScreen.h"

class clsDeleteClientScreen : protected clsScreen
{

private:
    
    static void _PrintClient(clsBankClient& Client)
    {
        //clsPerson::Print(); //Copy Paste Just For Formating.
        cout << "\nClient Card Info:";
        cout << "\n___________________________\n";
        cout << "\nFirstName     : " << Client.FirstName;
        cout << "\nLastName      : " << Client.LastName;
        cout << "\nFull Name     : " << Client.FullName();
        cout << "\nEmail         : " << Client.Email;
        cout << "\nPhone         : " << Client.Phone;
        cout << "\nAcc. Num.     : " << Client.AccountNumber();
        cout << "\nPassword      : " << Client.PinCode;
        cout << "\nAcc. Balance  : " << Client.AccountBalance;
        cout << "\n___________________________\n";
    }



   static void _DeleteCLient()
    {
        cout << "\nEnter Your AccountNumber : ";
        string AccountNumber = clsInputValidate::ReadString();

        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccountNumber Not Found ,Enter Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClient(Client);

        char Choice = 'n';
        cout << "Are You Sure To Delete This Client? [Y/N] ";
        cin >> Choice;

        if (toupper(Choice) == 'Y')
        {
            if (Client.Delete())// Client Will Be Empty 
            {
                cout << "\nClient Deleted Successfully.\n";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nError Client Wasn't Deleted.\n\a";
            }
        }

    }



public:

    static void ShowDeleteClientScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pDeleteClient))
        {
            return;
        }

        _DrawScreenHeader("\tDelete Client");
        _DeleteCLient();
    }
};

