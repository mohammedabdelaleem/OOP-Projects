#pragma once

#include<vector>
#include"clsCurrency.h"
#include"clsScreen.h"

class clsCurrenciesListScreen:protected clsScreen
{

	static void _PrintCurrencyRecord(clsCurrency& Currency)
	{
		cout << setw(15) << left << "" << "| " << setw(30) << left << Currency.Country()<< "| " << setw(8) << left << Currency.CurrencyCode() << "| " << setw(40) << left << Currency.CurrencyName() << "| " << setw(10) << left << Currency.Rate() << "|\n";
		cout << setw(15) << left << "" << clsString::Get_N_Chars('-', 97) << "\n";
	}

public:
	static void ShowCurrenciesListScreen()
	{
		
		vector<clsCurrency>vCurrencies = clsCurrency::GetCurrenciesList();

		string Title = "\t Currencies List Screen.";
		string SubTitle = "\t   (" + to_string(vCurrencies.size()) + ") Currencies.";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n\n";
		cout << setw(15) << left << "" << clsString::Get_N_Chars('-', 97)<<"\n";
		cout << setw(15) << left << "" << "| " << setw(30) << left << "Country" << "| " << setw(8) << left << "Code" << "| " << setw(40) << left << "Name" << "| " << setw(10) << left << "Rate/(1$)" << "|\n";
		cout << setw(15) << left << "" << clsString::Get_N_Chars('-', 97) << "\n";


		for (clsCurrency& C : vCurrencies)
		{
			_PrintCurrencyRecord(C);
		}
	}
};

