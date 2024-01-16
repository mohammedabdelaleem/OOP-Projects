#pragma once

#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"


class clsTotalBalancesScreen:protected clsScreen 
{
private:

  static void PrintClientRecordBalanceLine(clsBankClient& Client)
    {

      cout << setw(37) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
        cout << "|" << left << setw(25) << Client.FullName();
        cout << "|" << left << setw(11) << Client.AccountBalance << "|" << endl;
        cout << setw(37) << left << "" << clsUtil::Get_N_Chars('-', 55) << endl;
    }

public:

  static void ShowTotalBalancesScreen()
    {

      vector<clsBankClient>vClients = clsBankClient::GetClientsList();
      double TotalBalances = clsBankClient::GetTotalBalances();

      string Title = "\tTotal Balances Screen.";
      string SubTitle = "\t  (" + to_string(vClients.size()) + ") Client(s).";

      _DrawScreenHeader(Title, SubTitle);
        
        cout<<setw(37)<<left<<"" << clsUtil::Get_N_Chars('=', 55) << endl;
        cout<<setw(37)<<left<<"" << "|" << left << setw(15) << "Account Number";
        cout << "|" << left << setw(25) << "Client Name";
        cout << "|" << left << setw(11) << "Balance" << "|" << endl;
        cout<<setw(37)<<left<<"" << clsUtil::Get_N_Chars('=', 55) << endl;

        if (vClients.size())
        {
            for (clsBankClient& Client : vClients)
            {
                PrintClientRecordBalanceLine(Client);
            }
        }
        else
        {
            cout << setw(37) << left << "" << "\n\nNo Clients Avilable At The System.\n\n";
        }

        cout << setw(37) << left << ""  << clsUtil::Tabs(2) << "Total Balances = " << TotalBalances << endl;
        cout << setw(37) << left << "" << clsUtil::Tabs(2) << "(" << clsUtil::NumberToText(TotalBalances) << ").";

    }


};

