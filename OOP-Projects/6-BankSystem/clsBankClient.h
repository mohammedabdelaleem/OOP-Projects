#pragma once

#include <fstream>
#include <vector>

#include "clsPerson.h"
#include "clsString.h"

const string FileName = "ClientsInfo.txt";

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;


	static clsBankClient _ConvertLineToClientObject(string sLine)
	{
		vector<string>vClientDate = clsString::SpiltString(sLine, "#//#");

		return clsBankClient(enMode::UpdateMode, vClientDate[0], vClientDate[1], vClientDate[2]
			, vClientDate[3], vClientDate[4], vClientDate[5], stof(vClientDate[6]));

	}

	static string _ConvertClientObjectToLine(clsBankClient& Client, string Separator = "#//#")
	{
		string sClient = "";
		sClient += Client.FirstName + Separator;
		sClient += Client.LastName + Separator;
		sClient += Client.Email + Separator;
		sClient += Client.Phone + Separator;
		sClient += Client.AccountNumber() + Separator;
		sClient += Client.PinCode + Separator;
		sClient += to_string(Client.AccountBalance);

		return sClient;
	}

	static vector<clsBankClient> _LoadClientsDateFromFile(string FileName)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		vector<clsBankClient>vClients;

		if (MyFile.is_open())
		{
			string sLine;
			while (getline(MyFile, sLine))
			{
				clsBankClient BankClient = _ConvertLineToClientObject(sLine);
				vClients.push_back(BankClient);
			}
		}

		MyFile.close();
		return vClients;
	}

	static void _SaveCleintsDataToFile(string FileName, vector<clsBankClient>& vClients)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);//overwrite

		string DataLine;

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vClients)
			{

				DataLine = _ConvertClientObjectToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
		
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	void _Update()
	{
		vector<clsBankClient>_vClients = _LoadClientsDateFromFile(FileName);

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber()) //Super
			{
				C = *this;
				break;
			}
		}

		_SaveCleintsDataToFile(FileName, _vClients);
	}


public:
	clsBankClient(enMode Mode=enMode::EmptyMode, string FirstName="", string LastName = "", string Email = "",
		string Phone = "", string AccountNumber = "", string PinCode = "", float AccountBalance = 0) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	//Read Only Property
	string AccountNumber()
	{
		return _AccountNumber;
	}

	////////////////////////////////////////////

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	/////////////////////////////////////////////////

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	/////////////////////////////////////////////

	void Print()
	{
		//clsPerson::Print(); //Copy Paste Just For Formating.
		cout << "\nClient Card Info:";
		cout << "\n___________________________\n";
		cout << "\nFirstName     : " << FirstName;
		cout << "\nLastName      : " << LastName;
		cout << "\nFull Name     : " << FullName();
		cout << "\nEmail         : " << Email;
		cout << "\nPhone         : " << Phone;
		cout << "\nAcc. Num.     : " << _AccountNumber;
		cout << "\nPassword      : " << PinCode;
		cout << "\nAcc. Balance  : " << AccountBalance;
		cout << "\n___________________________\n";
	}

	//I Need A Way For Searching For A Client,If Found Make An Object Else Return An Empty Obj.
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string sLine;
			while (getline(MyFile, sLine))
			{
				clsBankClient BankClient = _ConvertLineToClientObject(sLine);

				if (BankClient._AccountNumber == AccountNumber)
				{
					MyFile.close();
					return BankClient;
				}
			}

			MyFile.close();
		}

		 return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber,string PinCode)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);

		if (MyFile.is_open())
		{
			string sLine;
			while (getline(MyFile, sLine))
			{
				clsBankClient BankClient = _ConvertLineToClientObject(sLine);

				if (BankClient._AccountNumber == AccountNumber && BankClient._PinCode == PinCode)
				{
					MyFile.close();
					return BankClient;
				}
			}

			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient BankClient = Find(AccountNumber);
		return (!BankClient.IsEmpty());
	}

	//Try To Separate Ui From A Class***************
	enum enSaveResults {svFaildEmptyObject=0 , svSucceeded=1 };

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case clsBankClient::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		}
	}



};

