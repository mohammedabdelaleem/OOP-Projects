#pragma once

#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"
#include"Global.h"

class clsClientListScreen:protected  clsScreen
{
private:

    static void  PrintClientsHeader(short ClientsNumber)
    {
      //  cout << setw(8) << left << clsUtil::Tabs(4) << "Clients List (" << ClientsNumber << ") Client(s).\n";

        string Title = "\t Clients List Screen.";
        string SubTitle = "\t(" + to_string(ClientsNumber) + ") Client(s).";
        _DrawScreenHeader(Title, SubTitle);

        cout <<setw(8)<<left<<""<< clsUtil::Get_N_Chars('=', 96 + 4) << endl;
        cout << setw(8) << left << "" << "|" << left << setw(15) << "Account Number";
        cout << "|" << left << setw(25) << "Client Name";
        cout << "|" << left << setw(12) << "Phone";
        cout << "|" << left << setw(20) << "Email";
        cout << "|" << left << setw(10) << "Pin Code";
        cout << "|" << left << setw(11) << "Balance" << "|" << endl;
        cout << setw(8) << left <<""<< clsUtil::Get_N_Chars('=', 96 + 4) << endl;
    }

    static  void PrintClientRecordLine(clsBankClient& Client)
    {
        cout << setw(8) << left <<"" << "|" << left << setw(15) << Client.AccountNumber();
        cout << "|" << left << setw(25) << Client.FullName();
        cout << "|" << left << setw(12) << Client.Phone;
        cout << "|" << left << setw(20) << Client.Email;
        cout << "|" << left << setw(10) << Client.PinCode;
        cout << "|" << left << setw(11) << Client.AccountBalance << "|" << endl;
        cout << setw(8) << left <<"" << clsUtil::Get_N_Chars('-', 96 + 4) << endl;
    }

public:

   static void ShowClientsListScreen()
    {
       if (!CheckAccessRights(clsUser::enMainMenuePermissions::pListClients))
       {
           return;
       }


        vector<clsBankClient>vClients = clsBankClient::GetClientsList();

        PrintClientsHeader(vClients.size());

        if (vClients.size())
        {
            for (clsBankClient& Client : vClients)
            {
                PrintClientRecordLine(Client);
            }
        }
        else {
            cout << "\nNo Clients Available In The System\a\n";
        }

    }

};

