#pragma once

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"


class clsUpdateCurrencyRate:protected clsScreen
{

	static float _ReadNewRate()
	{
		cout << "Enter New Rate: ";
		return clsInputValidate::ReadFloatNumber();
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

	static bool _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\n\nCurrency Found :-)\n\n";
			_PrintCurrency(Currency);
			return true;
		}
		else
		{
			cout << "\nCurrency Not Found\a\n\n";
			return false;
		}

	}


public:
	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t    Update Currency Rate.");

		cout << "\nPlease Enter A CurrencyCode: ";
		string CurrencyCode =clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		if (!_ShowResults(Currency))//We Can Loop Until Get A Right Code
			return;

		char Choice = 'n';
		cout << "\n\nAre You Sure You Want To Update This Currency Rate [Y/N]? ";
		cin >> Choice;

		if (toupper(Choice) == 'Y')
		{
			cout << "\n\nUpdate Currency Rate:\n-----------------------------------\n";
			Currency.UpdateRate(_ReadNewRate());

			cout << "\n\nRate Updated Successfully\n\n";
			_PrintCurrency(Currency);
		}else
		{
			cout << "\n\n\aOperation Was Cancelled\n\n\n";
		}

	}

};

