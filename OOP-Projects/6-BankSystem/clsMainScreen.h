#pragma once

#include"clsClientListScreen.h"
#include"clsInputValidate.h"
#include"clsScreen.h"
#include <iomanip>

class clsMainScreen:protected clsScreen
{
private:

	enum enMainMenuOption {
		eListClients = 1, eAddNewClient = 2,
		eDeleteClent = 3, eUpdateClient = 4, eFindClient = 5, eTransactions = 6, eMangeUsers = 7, eExit = 8
	};

	static void GoBackToMainMenu()
	{
		cout << "\n\nPress Any Key To Back To Main Menu......";
		system("Pause>0");
		ShowMainMenu();
	}

	//The Skeleton ///////////////////////////////////////////////////////////////////////////////
	static void _ShowAllClientsScreen()
	{
		//cout << "\nThis Is Show All Clients Screen.\n\n";
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientsScreen()
	{
		cout << "\nThis Is Show Add New Clients Screen.\n\n";
	}

	static void	_ShowDeleteClientScreen()
	{
		cout << "\nThis Is ShowDeleteClientScreen.\n\n";
	}

	static void	_ShowUpdateClientScreen()
	{
		cout << "\nThis Is ShowUpdateClientScreen.\n\n";
	}

	static void	_ShowFindClientScreen()
	{
		cout << "\nThis Is ShowFindClientScreen.\n\n";
	}

	static void	_ShowTransactionMenu()
	{
		cout << "\nThis Is ShowTransactionMenu.\n\n";
	}

	static void	_ShowManageUsersMenu()
	{
		cout << "\nThis Is ShowManageUsersMenu.\n\n";
	}


	static short _ReadOption(string Message, short From, short To)
	{
		cout << setw(37) << left << "";
		return clsInputValidate::ReadShortNumberBetween( From, To);
	}

	static void _ShowEndScreen()
	{
		system("cls");
		cout << "\n------------------------------------------";
		cout << "\n\t\tEnd Of Program ";
		cout << "\n------------------------------------------";
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
			GoBackToMainMenu();
			break;

		case enMainMenuOption::eAddNewClient:
			system("cls");
			//load(5);
			_ShowAddNewClientsScreen();
			GoBackToMainMenu();
			break;

		case enMainMenuOption::eDeleteClent:
			system("cls");
			//load(5);
			_ShowDeleteClientScreen();
			GoBackToMainMenu();
			break;

		case enMainMenuOption::eUpdateClient:
			system("cls");
			//load(5);
			_ShowUpdateClientScreen();
			GoBackToMainMenu();
			break;

		case enMainMenuOption::eFindClient:
			system("cls");
			//load(5);
			_ShowFindClientScreen();
			GoBackToMainMenu();
			break;

		case enMainMenuOption::eTransactions:
			system("cls");
			//load(5);
			_ShowTransactionMenu();
			GoBackToMainMenu();
			break;

		case enMainMenuOption::eMangeUsers:
			system("cls");
			//load(5);
			_ShowManageUsersMenu();
			break;

		case enMainMenuOption::eExit:
			//load(5);
			_ShowEndScreen();
			//Login();
			break;

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
		cout <<setw(37)<<left<<""<< "\t[8] Logout\n";	   
		cout << setw(37) << left << ""<< "============================================\n";

		_PerformMainMenuOption((enMainMenuOption)_ReadOption("Enter Your Choice: ", 1, 8));
	}




};

