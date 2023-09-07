#pragma once

#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsScreen.h"

class clsWithdrawScreen :protected clsScreen
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

public:
	static void ShowWithdrawScreen()
	{

		_DrawScreenHeader("\t   Withdraw Screen");

		cout << "\nEnter An AccountNumber: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			cout << "\nEnter An AccountNumber: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		//Amount>=AccountBalance && Amount%5==0
		cout << "\nPlease Enter A WithDraw Amount [Multiple Of 5's]: ";
		double Amount=clsInputValidate::ReadDblNumber();

		//cout << Client.AccountBalance << endl << endl;

		while (Amount > Client.AccountBalance)
		{
			cout << "\n\nAmount Exceeds The Balance ,You Can WithDraw Up To " << Client.AccountBalance << "\n Please Enter Anoter WithDraw Number : ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		while (fmod(Amount , 5) != 0)
		{
			cout << "\n\nPlease Enter A WithDraw Amount [Multiple Of 5's]: ";
			Amount = clsInputValidate::ReadDblNumber();
		}

		char Answer = 'n';
		cout << "Are You Sure You Want Perform This Transaction[Y/N]? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			Client.Withdraw(Amount);
			cout << "\nWithdraw Proccess Completed Successfully.\n New Balance Is : " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "Operation Was Cancelled....\n";
		}


	}


};

