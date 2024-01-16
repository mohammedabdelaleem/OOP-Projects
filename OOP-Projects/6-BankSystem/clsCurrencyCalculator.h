#pragma once

#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"



class clsCurrencyCalculator:protected clsScreen
{
private:
	static float _ReadAmount()
	{
		cout << "\nEnter Amount To Exchange: ";
		return	clsInputValidate::ReadFloatNumber();
	}

	static void _PrintCurrency(clsCurrency Currency,string Destination="From")
	{

		cout<<endl << Destination << " :\n";
		cout << clsString::Get_N_Chars('-', 22);
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n" << clsString::Get_N_Chars('-', 22) << endl;
	}

	static clsCurrency _ReadCurrency(string FromTo)
	{
		cout << "\nPlease Enter Currency Code " << "\'"<<FromTo<<"\' : ";
		string CurrencyCode = clsInputValidate::ReadString();

		if (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrencyCode Not Found,Please Enter Another One: ";
			 CurrencyCode = clsInputValidate::ReadString();
		}

	return clsCurrency::FindByCode(CurrencyCode);

	}

	static float _GetAmountInUSD(float Amount, float Rate)
	{
		return Amount / Rate;
	}

	static void _PrintCalculationsResults(clsCurrency CurrencyFrom, clsCurrency CurrencyTo,float Amount)
	{
		cout<< "\n\n-------------------------";
		cout << "\nConvert From " << CurrencyFrom.CurrencyCode() << " To " << CurrencyTo.CurrencyCode() << " :\n-------------------------\n";

		

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			_PrintCurrency(CurrencyFrom, "From");
			cout<<Amount<<" " << CurrencyFrom.CurrencyCode() <<" = " << _GetAmountInUSD(Amount, CurrencyFrom.Rate())<<" USD\n";
		}
		else
		{
			cout << "\n\nConvert From " << CurrencyFrom.CurrencyCode() << " To USD" << " :\n--------------------------\n";
			_PrintCurrency(CurrencyFrom, "From");


			float AmountInUSD = _GetAmountInUSD(Amount, CurrencyFrom.Rate());
			cout<<Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInUSD << " USD\n";

			cout << "\n\nConvert From USD To "<<CurrencyTo.CurrencyCode() << " :\n";
			cout << "--------------------------------\n";
			_PrintCurrency(CurrencyTo,"To");

			float AmountInCurrencyTo = AmountInUSD * CurrencyTo.Rate();

			cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountInCurrencyTo  <<" "<<CurrencyTo.CurrencyCode()<<" \n";
		}
	}


public:

	static void ShowCurrencyCalculatorScreen()
	{

		char TryAgain = 'N';
		do {
			system("cls");
			_DrawScreenHeader("\t   Currency Calculator.");

			clsCurrency CurrencyFrom = _ReadCurrency(" From ");
			clsCurrency CurrencyTo = _ReadCurrency(" To ");

			float Amount = _ReadAmount();

			_PrintCalculationsResults(CurrencyFrom, CurrencyTo, Amount);


			cout << "\n\nDo You Want To Perform Another Calculation [Y/N]? ";
			cin >> TryAgain;
		} while(toupper(TryAgain) == 'Y');
		

	}
};



/*
*
* 
* This Is A Dr's Code But I Depends On My Code
* 
* 
#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

	static float _ReadAmount()
	{
		cout << "\nEnter Amount to Exchange: ";
		float Amount = 0;

		Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message)
	{

		string CurrencyCode;
		cout << Message << endl;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return Currency;

	}


	static  void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{

		cout << "\n" << Title << "\n";
		cout << "_____________________________\n";
		cout << "\nCountry       : " << Currency.Country();
		cout << "\nCode          : " << Currency.CurrencyCode();
		cout << "\nName          : " << Currency.CurrencyName();
		cout << "\nRate(1$) =    : " << Currency.Rate();
		cout << "\n_____________________________\n\n";

	}

	static void _PrintCalculationsResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{

		_PrintCurrencyCard(Currency1, "Convert From:");

		float AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD")
		{
			return;
		}

		cout << "\nConverting from USD to:\n";

		_PrintCurrencyCard(Currency2, "To:");

		float AmountInCurrrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);

		cout << Amount << " " << Currency1.CurrencyCode()
			<< " = " << AmountInCurrrency2 << " " << Currency2.CurrencyCode();

	}


public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'y';

		while (Continue == 'y' || Continue == 'Y')
		{
			system("cls");

			_DrawScreenHeader("\tUpdate Currency Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Continue;

		}


	}
};


*/