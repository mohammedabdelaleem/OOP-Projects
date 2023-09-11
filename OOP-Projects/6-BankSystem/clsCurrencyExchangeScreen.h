#pragma once

#include"clsScreen.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrency.h"
#include"clsUpdateCurrencyRate.h"
#include"clsCurrencyCalculator.h"


class clsCurrencyExchangeScreen:protected clsScreen
{

	enum  enCurrenciesMainMenuOptions{eListCurrencies=1 , eFindCurrency=2 , eUpdateRate=3,
		eCurrencyCalculator=4, eMainMenue=5 };
	

	static short _ReadMainMenuOption(short From,short To, string Message)
	{
		cout << setw(40) << left << "";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 5);
		return Choice;
	}

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nShowListCurrenciesScreen.\n";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen()
	{
	//	cout << "\nShowFindCurrencyScreen.\n";
		clsFindCurrency::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nShowUpdateRateScreen.\n";
		clsUpdateCurrencyRate::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
	//	cout << "\n_ShowCurrencyCalculatorScreen.\n";
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}

	static void _ShowMainMenueScreen()
	{
	
	}

	static void _PerformCurrenciesMainMenuOprion(enCurrenciesMainMenuOptions MainMenuOption)
	{
		switch (MainMenuOption)
		{
		case clsCurrencyExchangeScreen::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBkToCurrencyExchangeMainMenuScreen();
			break;
		}
		
		case clsCurrencyExchangeScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBkToCurrencyExchangeMainMenuScreen();
			break;
		}
		
		case clsCurrencyExchangeScreen::eUpdateRate:
		{
			system("cls");
			_ShowUpdateRateScreen();
			_GoBkToCurrencyExchangeMainMenuScreen();
			break;
		}
		
		case clsCurrencyExchangeScreen::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBkToCurrencyExchangeMainMenuScreen();
			break;
		}
		
		case clsCurrencyExchangeScreen::eMainMenue:
		{
			system("cls");
			_ShowMainMenueScreen();
			break;
		}
	
		}
	}

	static void _GoBkToCurrencyExchangeMainMenuScreen()
	{
		cout << "\n\nPress any key to go back to Currency Exchange Main Menu...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}


public:
	static void ShowCurrencyExchangeScreen()
	{
		if (!CheckAccessRights(clsUser::enMainMenuePermissions::pCurrencyExchange))
		{
			return;
		} 

		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Main Screen.");

		cout <<"\n"<< setw(40) << left << "" << clsString::Get_N_Chars('=', 41) << "\n";
		cout << setw(40) << left << "" << "\t Currency Exchange Menue" << "\n";
		cout << setw(40) << left << "" << clsString::Get_N_Chars('=', 41) << "\n";
					 
		cout << setw(40) << left << "" << "[1] List Currencies.\n";
		cout << setw(40) << left << "" << "[2] Find Currency.\n";
		cout << setw(40) << left << "" << "[3] Update Rate.\n";
		cout << setw(40) << left << "" << "[4] Currency Calculator.\n";
		cout << setw(40) << left << "" << "[5] Main Menue.\n";
		cout << setw(40) << left << "" << clsString::Get_N_Chars('=', 41) << "\n";

		_PerformCurrenciesMainMenuOprion( (enCurrenciesMainMenuOptions)_ReadMainMenuOption( 1,5, "\nEnter Your Choice") );
	}

};

