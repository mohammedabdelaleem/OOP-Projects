#pragma once

#include"clsUtil.h"

class clsInputValidate
{

public:

	template<class Type>
	static bool IsNumberBetween(Type Number, short From, short To)
	{
		//I Suppuse User Enterd 10,15,9 As Ex 
		return (Number >= clsUtil::Min(From, To) && Number <= clsUtil::Max(From, To));
	}

	static bool IsDateBetween(const clsDate& Date, const clsDate& StartDate, const clsDate& EndDate)
	{
		return clsDate::IsDateBetween(Date, StartDate, EndDate);
	}

	static short ReadShortNumber(string Message="", string ErrorMessage = "Invalid Number, Enter again: ")
	{
		short Number;
		cout << Message;
		cin >> Number;

		while (cin.fail()) {
			// user didn't input a number   
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage ;
			cin >> Number;
		}

		return Number;
	}
	

	static short ReadShortNumberBetween(int From, int To,string Message="")
	{
		
			short Number = 1;
			bool validInput = true;
			do
			{
				if (!validInput) {
					// If input was invalid, clear the error flag and ignore any remaining input in the stream
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Invalid input. Please enter a number between " << From << " and " << To << "." << endl;
				}
				if(Message!="")
				{
					cout <<Message <<" [" << From << " - " << To << "] ? ";
				}
				else
				{
					cout << "Enter A Number [" << From << "-" << To << "] ? ";
				}
				cin >> Number;
				validInput = cin.good() && Number >= From && Number <= To;
			} while (!validInput);

			return Number;
	

	}

	static short ReadShortNumberInRange(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		short Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}
		return Number;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number;
		while (!(cin >> Number)) {
			cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadFloatNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		float Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}


	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValidDate(const clsDate& Date)
	{
		return clsDate::IsAValidDate(Date);
	}

	static string ReadString()
	{
		string Str = "";
		getline(cin >> ws, Str);

		return Str;
	}


};
