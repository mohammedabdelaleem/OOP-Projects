#pragma once

#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include <iomanip>
#include"clsManageUsersScreen.h"
#include"Global.h"
#include"clsLoginScreen.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeScreen.h"

class clsMainScreen:protected clsScreen
{
private:

	enum enMainMenuOption {
		eListClients = 1, eAddNewClient = 2,
		eDeleteClent = 3, eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eMangeUsers = 7,eLoginRegister=8 ,eCurrencyExchange=9,eExit = 10
	};

	static void _GoBackToMainMenu()
	{
		cout << "\n\nPress Any Key To Back To Main Menu......";
		system("Pause>0");
		ShowMainMenu();
	}

	//The Skeleton ///////////////////////////////////////////////////////////////////////////////
	static void _ShowAllClientsScreen()
	{
		//cout << "\nThis Is Show All Clients Screen.\n\n";
		clsClientListScreen::ShowClientsListScreen();
	}

	static void _ShowAddNewClientsScreen()
	{
		//cout << "\nThis Is Show Add New Clients Screen.\n\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}

	static void	_ShowDeleteClientScreen()
	{
	//	cout << "\nThis Is ShowDeleteClientScreen.\n\n"; 
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}

	static void	_ShowUpdateClientScreen()
	{
		//cout << "\nThis Is ShowUpdateClientScreen.\n\n";
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}

	static void	_ShowFindClientScreen()
	{
	//	cout << "\nThis Is ShowFindClientScreen.\n\n";
		clsFindClientScreen::ShowFindClientScreen();
	}

	static void	_ShowTransactionMenu()
	{
		//cout << "\nThis Is ShowTransactionMenu.\n\n";
		clsTransactionsScreen::ShowTransactionsMenue();
	}

	static void	_ShowManageUsersMenu()
	{
		//cout << "\nThis Is Show Manage Users Menu.\n\n";
		clsManageUsersScreen::ShowManageUsersMenueScreen();
	}

	static void	_ShowLoginRegisterScreen()
	{
		clsLoginRegisterScreen::ShowRegisterdUsersList();
	}

	static void	_ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

	static short _ReadOption( short From, short To, string Message)
	{
		cout << setw(37) << left << "";
		return clsInputValidate::ReadShortNumberBetween( From, To,Message);
	}

	//static void _ShowEndScreen()
	//{
	//	system("cls");
	//	cout << "\n------------------------------------------";
	//	cout << "\n**************End Of Program************** ";
	//	cout << "\n------------------------------------------";
	//}

	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		//Then It Will Go Back To Main Function.
		

		//This Is Called Circular Reference , Compiler Confiused Here ==>LoginScreen called MainMenu ,At MainMenu You Called LoginScreen And So On....
	//	clsLoginScreen::ShowLoginScreen();
	}

	//Performe Main Menu Option
	static void _PerformMainMenuOption(enMainMenuOption MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case enMainMenuOption::eListClients:
			system("cls");
			//load(5); //Windows Library Will Make A Problem 
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eAddNewClient:
			system("cls");
			_ShowAddNewClientsScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eDeleteClent:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eTransactions:
			system("cls");
			_ShowTransactionMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eMangeUsers:
			system("cls");
			_ShowManageUsersMenu();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenu();
			break;

		case enMainMenuOption::eExit:
		{
			_Logout();
			//_ShowEndScreen();
			break;
		}

		}
	}

public:

	//Print Main Menu List To User
	static void ShowMainMenu()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");


		cout <<setw(37)<<left<<""<< "============================================\n";
		cout <<setw(37)<<left<<""<< "\t\tMain Menu Screen\n";
		cout <<setw(37)<<left<<""<< "=============================================\n";
		cout <<setw(37)<<left<<""<< "\t[1] Show Clients List.\n";
		cout <<setw(37)<<left<<""<< "\t[2] Add New Client.\n";
		cout <<setw(37)<<left<<""<< "\t[3] Delete Client.\n";
		cout <<setw(37)<<left<<""<< "\t[4] Update Client.\n";
		cout <<setw(37)<<left<<""<< "\t[5] Find Client.\n";
		cout <<setw(37)<<left<<""<< "\t[6] Transactions.\n";
		cout <<setw(37)<<left<<""<< "\t[7] Manage Users.\n";
		cout <<setw(37)<<left<< ""<<"\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout <<setw(37)<<left<<""<< "\t[10] Logout\n";	   
		cout << setw(37) << left << ""<< "============================================\n";

		_PerformMainMenuOption((enMainMenuOption)_ReadOption( 1, 10, "Enter Your Choice"));
	}




};

