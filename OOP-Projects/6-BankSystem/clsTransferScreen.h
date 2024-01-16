#pragma once
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsTransferScreen:protected clsScreen
{
private:

    static void _PrintClient(clsBankClient& Client)
    {
        //clsPerson::Print(); //Copy Paste Just For Formating.
        cout << "\nClient Card Info:";
        cout << "\n___________________________\n";
        cout << "\nFull Name     : " << Client.FullName();
        cout << "\nAcc. Num.     : " << Client.AccountNumber();
        cout << "\nAcc. Balance  : " << Client.AccountBalance;
        cout << "\n___________________________\n";
    }

	static string _ReadAccountNumber(string Dummy)
	{
		cout << "\nPlease Enter Account Number To Transfer "<<Dummy<<": ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number Not Found,Please Enter Another One To Transfer From: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static  double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount = 0;
		cout << "\nEnter Transfer Amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds The Available Balance,Please Enter Another Amount: ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		while (fmod(Amount, 5) != 0)
		{
			cout << "\n\nPlease Enter An Amount [Multiple Of 5's]: ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		return Amount;
	}



public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t  Transfer Screen. ");

		    string AccountNum1 = _ReadAccountNumber("From");
			clsBankClient SourceClient = clsBankClient::Find(AccountNum1);
			_PrintClient(SourceClient);


			string AccountNum2 = _ReadAccountNumber("To");
			while (AccountNum2== AccountNum1)
			{
				cout << "\nWhat Are You Doing ,How Can You Transfer To Youself Into The Same AccountNumber?\a\a\n";
				AccountNum2 = _ReadAccountNumber("To");
			}
			
			clsBankClient DestinationClient = clsBankClient::Find(AccountNum2);
			_PrintClient(DestinationClient);

			 double Amount = _ReadAmount(SourceClient);

			char Answer = 'n';
			cout << "\nAre You Sure You Want Perform This Operation? [Y/N] ";
			cin >> Answer;

			if (toupper(Answer) == 'Y')
			{
				SourceClient.Transfer(Amount,DestinationClient);
				cout << "\n\nTransfer Done Successfully.\n\n";

				_PrintClient(SourceClient);
				_PrintClient(DestinationClient);
			}
			else
			{
				cout << "\n\nOperation Was Cancelled....\n";
			}


	}



};

