#pragma once

#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsScreen.h"


class clsUpdateClientScreen:protected clsScreen
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


    //Try To Separate Ui From A Class***************
    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFloatNumber();
    }

    static void UpdateClient() {

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
        cout << "\nAre You Sure You Want To Update This Client Info[Y/N]?";
        cin >> Choice;
        
        if (toupper(Choice) != 'Y')
            return;

        cout << "\n\n--------------------------\n";
        cout << "Update Client Info: ";
        cout << "\n--------------------------\n";

        //This Function Will Update Client In Memory Not File
        ReadClientInfo(Client);


        //You Can Update Each Character At Object unless AccountNumber Read Only
      /*  Client.Email = "MY-Email@gmail.com";
        Client.Save();*/

        clsBankClient::enSaveResults SaveResults;
        SaveResults = Client.Save();

        switch (SaveResults)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nAccount Updated Successfully :-)\n";
            _PrintClient(Client);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }

        }
    }

public:
    static void ShowUpdateClientScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pUpdateClients))
        {
            return;
        }

        _DrawScreenHeader("\tUpdate Client");
        UpdateClient();
    }


};

