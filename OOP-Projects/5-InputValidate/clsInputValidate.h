#pragma once

#include"clsUtil.h"
//#include"clsDate.h"

class clsInputValidate
{

public:

	template<class Type>
	static bool IsNumberBetween(Type Number, short From, short To)
	{
		//I Suppuse User Enterd 10,15,9 As Ex 
		return (Number >= clsUtil::Min(From,To) && Number <= clsUtil::Max(From, To));
	}

	static bool IsDateBetween(const clsDate& Date, const clsDate& StartDate, const clsDate& EndDate)
	{
		return clsDate::IsDateBetween(Date, StartDate, EndDate);
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(INT_MAX, '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			//cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin.ignore(INT_MAX, '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number,From,To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

    static bool IsValidDate(const clsDate& Date)
    {
        return clsDate::ValidateDate(Date);
    }

};
