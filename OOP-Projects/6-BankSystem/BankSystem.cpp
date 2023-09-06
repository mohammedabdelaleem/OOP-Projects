#pragma once

#include "clsBankClient.h"
#include "clsInputValidate.h"

//Try To Separate Ui From A Class***************
void ReadClientInfo(clsBankClient& Client)
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

void UpdateClient() {

    cout << "\nEnter Your AccountNumber : ";
    string AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccountNumber Not Found ,Enter Another One: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    system("cls");
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
        Client.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;
    }

    }
}

void AddNewClient()
{
    cout << "\nEnter An AccountNumber: ";
    string AccountNumber = clsInputValidate::ReadString();

    //Loop Untill Enter A Unique AccountNumber.
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccountNumber Already Exist, Enter Another One: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    system("cls");
    cout << "\n---------------------------\n";
    cout << "  Adding New Client.\n";
    cout << "---------------------------\n\n";


    //Update Mode To -> AddNew And Return An Obj.
    clsBankClient NewClient = clsBankClient::GetNewClientObject(AccountNumber);

    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResults;
    SaveResults = NewClient.Save();

    switch (SaveResults)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Added Successfully :-)\n";
        NewClient.Print();
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

void DeleteCLient()
{
    cout << "\nEnter Your AccountNumber : ";
    string AccountNumber = clsInputValidate::ReadString();

    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccountNumber Not Found ,Enter Another One: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient Client = clsBankClient::Find(AccountNumber);
    Client.Print();

    char Choice = 'n';
    cout << "Are You Sure To Delete This Client? [Y/N] ";
    cin >> Choice;

    if (toupper(Choice) == 'Y')
    {
        if (Client.Delete())// Client Will Be Empty 
        {
            cout << "\nClient Deleted Successfully.\n";
            Client.Print();
        }

        else
        {
            cout << "\nError Client Wasn't Deleted.\n\a";
        }
    }

}

void  PrintShowClientsHeader(short ClientsNumber)
{
     cout << clsUtil::Tabs(4) << "Clients List (" << ClientsNumber << ") Client(s).\n";

    cout << clsUtil::Get_N_Chars('=', 96+4) << endl;
    cout << "|" << left << setw(15) << "Account Number";
    cout << "|" << left << setw(25) << "Client Name";
    cout << "|" << left << setw(12) << "Phone";
    cout << "|" << left << setw(20) << "Email";
    cout << "|" << left << setw(10) << "Pin Code";
    cout << "|" << left << setw(11) << "Balance" << "|"<<endl;
    cout << clsUtil::Get_N_Chars('=', 96+4) << endl;
}

void PrintClientRecordLine(clsBankClient& Client)
{
    cout << "|" << left << setw(15) << Client.AccountNumber();
    cout << "|" << left << setw(25) << Client.FullName();
    cout << "|" << left << setw(12) << Client.Phone;
    cout << "|" << left << setw(20) << Client.Email;
    cout << "|" << left << setw(10) << Client.PinCode;
    cout << "|" << left << setw(11) << Client.AccountBalance << "|" << endl;
    cout << clsUtil::Get_N_Chars('-', 96 + 4) << endl;
}

void ShowClientsList()
{
    vector<clsBankClient>vClients = clsBankClient::GetClientsList();

    PrintShowClientsHeader(vClients.size());

    if (vClients.size())
    {
        for(clsBankClient& Client : vClients)
        {
            PrintClientRecordLine(Client);
        }
    }
    else {
        cout << "\nNo Clients Available In The System\a\n";
    }

  

}

void PrintClientRecordBalanceLine( clsBankClient &Client)
{

    cout << "|" << left << setw(15) << Client.AccountNumber();
    cout << "|" << left << setw(25) << Client.FullName();
    cout << "|" << left << setw(11) << Client.AccountBalance << "|" << endl;
    cout << clsUtil::Get_N_Chars('-', 55) << endl;
}

void ShowTotalBalances()
{
    vector<clsBankClient>vClients = clsBankClient::GetClientsList();
    double TotalBalances = clsBankClient::GetTotalBalances();

    cout << clsUtil::Tabs(1) << "Total Balances List (" << vClients.size()<< ") Client(s).\n";

    cout << clsUtil::Get_N_Chars('=', 55) << endl;
    cout << "|" << left << setw(15) << "Account Number";
    cout << "|" << left << setw(25) << "Client Name";
    cout << "|" << left << setw(11) << "Balance" << "|" << endl;
    cout << clsUtil::Get_N_Chars('=', 55) << endl;


    for (clsBankClient& Client : vClients)
    {
        PrintClientRecordBalanceLine(Client);
    }

    cout << "\n" << clsUtil::Tabs(1) << "Total Balances = " << TotalBalances << endl;
    cout << clsUtil::Tabs(1) <<"(" << clsUtil::NumberToText(TotalBalances)<<").";

}

int main()
{
    ShowTotalBalances();

    system("pause>0");
    return 0;
}