#pragma once

#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsFindClientScreen:protected clsScreen
{
private:

    enum enSearchBy {
        sAccountNumber = 1, sAccountNumberAndPinCode = 2
    };

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
    

    static void _PerformFindClient()
    {
        //We Can Loop Until We Found One , But Here I'm Searcheing And Print The Result At Time. 
        enSearchBy Choice;
        cout << endl << setw(37) << left << "" << "[1]Search By Account Number.\n";
        cout << setw(37) << left << "" << "[2]Search By Account Number And Pin Code .\n";
        cout << setw(37) << left << "" << clsUtil::Get_N_Chars('-',50)<<"\n";
        //cout << setw(37) << left << "" << "Enter Your Choice: ";
        cout << setw(37) << left << "";
        Choice = (enSearchBy)clsInputValidate::ReadShortNumberBetween(1, 2);

        switch (Choice)
        {

        case enSearchBy::sAccountNumber:
        {
            cout << "Enter Your Account Number: ";
            string AccountNumber = clsInputValidate::ReadString();

            clsBankClient Client = clsBankClient::Find(AccountNumber);
            if (!Client.IsEmpty())
            {
                cout << "\nClient Found :-)\n";
                cout << "-----------------------\n\n";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nClient Was not Found :-(\n";
            }
            break;
        }

        case enSearchBy::sAccountNumberAndPinCode:
        {
            cout << "Enter Your Account Number: ";
            string AccountNumber = clsInputValidate::ReadString();

            cout << "Enter Your Pin Code: ";
            string PinCode = clsInputValidate::ReadString();

            clsBankClient Client = clsBankClient::Find(AccountNumber, PinCode);
            if (!Client.IsEmpty())
            {
                cout << "\nClient Found :-)\n";
                cout << "-----------------------\n\n";
                _PrintClient(Client);
            }
            else
            {
                cout << "\nClient Was not Found :-(\n";
            }
            break;
        }

        }

    }


public:

  static void ShowFindClientScreen()
    {
      if (!CheckAccessRights(clsUser::enMainMenuePermissions::pFindClient))
      {
          return;
      }

        _DrawScreenHeader("\tFind Client Screen");
        _PerformFindClient();
    }

};

