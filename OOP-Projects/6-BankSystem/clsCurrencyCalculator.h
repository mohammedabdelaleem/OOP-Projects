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

	static void _ConversionProcess(clsCurrency CurrencyFrom, clsCurrency CurrencyTo,float Amount)
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

			_ConversionProcess(CurrencyFrom, CurrencyTo, Amount);


			cout << "\n\nDo You Want To Perform Another Calculation [Y/N]? ";
			cin >> TryAgain;
		} while(toupper(TryAgain) == 'Y');
		

	}
};

