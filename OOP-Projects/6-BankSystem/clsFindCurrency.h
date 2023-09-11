#pragma once

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"


class clsFindCurrency:protected clsScreen						
{

	static short _ReadChoice()
	{
		cout << "Find By: [1] Code Or [2] Country ? ";
		return clsInputValidate::ReadShortNumberInRange(1, 2);
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << clsString::Get_N_Chars('-', 12);
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode(); 
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n" << clsString::Get_N_Chars('-', 12) << endl;
	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n\nCurrency Found :-)\n\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found\a\n\n";
		}

	}

	static void _PerformFindOperateion(clsCurrency::enFindBy FindBy)
	{
		switch (FindBy)
		{
		case clsCurrency::eCode:
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode=clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Currency);
			break;
		}

		case clsCurrency::eCountry:
		{
			cout << "Please Enter Country Name: ";
			string Country = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			_ShowResults(Currency);
		}
		}
	}

public:
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t  Find Currency Screen.");

		_PerformFindOperateion((clsCurrency::enFindBy)_ReadChoice());




	}
};

