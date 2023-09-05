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
int main()
{
    DeleteCLient();

    system("pause>0");
    return 0;
}