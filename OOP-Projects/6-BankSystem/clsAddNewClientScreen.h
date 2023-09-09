#pragma once

#include "clsBankClient.h"
#include "clsInputValidate.h"
#include"clsScreen.h"

class clsAddNewClientScreen : protected clsScreen
{

private:
    //Try To Separate Ui From A Class***************
    static void _ReadClientInfo(clsBankClient& Client)
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
   
    static void _AddNewClient()
    {
        cout << "\nEnter An AccountNumber: ";
        string AccountNumber = clsInputValidate::ReadString();

        //Loop Untill Enter A Unique AccountNumber.
        while (clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccountNumber Already Exist, Enter Another One: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        //Update Mode To -> AddNew And Return An Obj.
        clsBankClient NewClient = clsBankClient::GetNewClientObject(AccountNumber);

        _ReadClientInfo(NewClient);

        clsBankClient::enSaveResults SaveResults;
        SaveResults = NewClient.Save();

        switch (SaveResults)
        {
        case  clsBankClient::enSaveResults::svSucceeded:
        {
            cout << "\nClient Added Successfully :-)\n";
            _PrintClient(NewClient);
            break;
        }
        case clsBankClient::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError account was not saved because it's Empty";
            break;
        }
        case clsBankClient::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError account was not saved because account number is used!\n";
            break;
        }
        }
    }

    static void _PrintClient(clsBankClient& Client)
	{
		//clsPerson::Print(); //Copy Paste Just For Formating.
		cout << "\nClient Card Info:";
		cout << "\n___________________________\n";
		cout << "\nFirstName     : " <<Client.FirstName;
		cout << "\nLastName      : " <<Client.LastName;
		cout << "\nFull Name     : " <<Client.FullName();
		cout << "\nEmail         : " <<Client.Email;
		cout << "\nPhone         : " <<Client.Phone;
		cout << "\nAcc. Num.     : " <<Client.AccountNumber();
		cout << "\nPassword      : " <<Client.PinCode;
		cout << "\nAcc. Balance  : " <<Client.AccountBalance;
		cout << "\n___________________________\n";
	}


public:

    static void ShowAddNewClientScreen()
    {
        if (!CheckAccessRights(clsUser::enMainMenuePermissions::pAddNewClient))
        {
            return;
        }
        _DrawScreenHeader("\tAdd New Client");

        _AddNewClient();
    }
	
};

