#pragma once

#include <fstream>
#include <vector>

#include "clsPerson.h"
#include "clsString.h"
#include"Global.h"

const string FileName = "ClientsInfo.txt";
const string TransferLogFileName = "TransferLog.txt";

class clsBankClient : public clsPerson
{
private:
	struct stTransferLogRecord;
	
	enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode=2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete=false;

	

	static clsBankClient _ConvertLineToClientObject(string sLine)
	{
		vector<string>vClientDate = clsString::Split(sLine, "#//#");

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

	static stTransferLogRecord _ConvertLineToTransferLogRecord(string Line)
	{
		vector<string>vRecordLine=clsString::Split(Line,"#//#");

		stTransferLogRecord Record;

		Record.DateTime = vRecordLine[0];
		Record.SourceAccountNumber = vRecordLine[1];
		Record.DestinationAccountNumber = vRecordLine[2];
		Record.Amount =stoi(vRecordLine[3]);
		Record.SourceBalanceAfter = stoi(vRecordLine[4]);
		Record.DestinationBalanceAfter = stoi(vRecordLine[5]);
		Record.UserName = vRecordLine[6];

		return Record;
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

	static vector<stTransferLogRecord>_LoadTransferLogRecordsFromFile()
	{
		fstream MyFile;
		MyFile.open(TransferLogFileName, ios::in);

		vector<stTransferLogRecord>vTransferLogRecord;
		stTransferLogRecord Record;

		if (MyFile.is_open())
		{
			string sLine;
			while (getline(MyFile, sLine))
			{
				Record = _ConvertLineToTransferLogRecord(sLine);
				vTransferLogRecord.push_back(Record);
			}
		}

		MyFile.close();
		return vTransferLogRecord;
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
				if(!C._MarkedForDelete)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
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

	void _AddNew()
	{
		_AddDatelineToFile(FileName, _ConvertClientObjectToLine(*this));
	}

	void _AddDatelineToFile(string FileName, string sClient)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << sClient << endl;
			MyFile.close();
		}
	}



	 string _PrepareTransferLogRecord(double Amount, clsBankClient& DestinationClient,string Separator="#//#")
	{
		 //Date/Time , AccountFrom , AccountTo , Amount , BalanceFromAfter ,BalanceToAfter, ResposableUser
		string CurrentTransferLog = clsDate::GetSystemDateTimeString()+Separator;
		CurrentTransferLog += (_AccountNumber + Separator);
		CurrentTransferLog += DestinationClient.AccountNumber() + Separator;
		CurrentTransferLog += to_string(Amount) + Separator;
		CurrentTransferLog += to_string (AccountBalance) + Separator;
		CurrentTransferLog += to_string(DestinationClient.AccountBalance) + Separator;
		CurrentTransferLog += CurrentUser.UserName;

		return CurrentTransferLog;
	}

	 void _RegisterTransferLog(double Amount, clsBankClient& DestinationClient)
	 {
		 string TransferLogLine = _PrepareTransferLogRecord(Amount, DestinationClient);

		 fstream MyFile;
		 MyFile.open(TransferLogFileName, ios::out | ios::app);

		 if (MyFile.is_open())
		 {
			 MyFile << TransferLogLine << endl;

			 MyFile.close();
		 }
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

	struct stTransferLogRecord
	{
		string DateTime;
		string	SourceAccountNumber;
		string DestinationAccountNumber;
		double Amount;
		double SourceBalanceAfter;
		double DestinationBalanceAfter;
		string UserName;
	};

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

	////No UI Related Inside Object...... 
	//void Print()
	//{
	//	
	//	//clsPerson::Print(); //Copy Paste Just For Formating.
	//	cout << "\nClient Card Info:";
	//	cout << "\n___________________________\n";
	//	cout << "\nFirstName     : " << FirstName;
	//	cout << "\nLastName      : " << LastName;
	//	cout << "\nFull Name     : " << FullName();
	//	cout << "\nEmail         : " << Email;
	//	cout << "\nPhone         : " << Phone;
	//	cout << "\nAcc. Num.     : " << _AccountNumber;
	//	cout << "\nPassword      : " << PinCode;
	//	cout << "\nAcc. Balance  : " << AccountBalance;
	//	cout << "\n___________________________\n";
	//}

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

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	//Try To Separate Ui From A Class***************
	enum enSaveResults {svFaildEmptyObject=0 , svSucceeded=1, svFaildAccountNumberExists=2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
			
		case enMode::EmptyMode:
		{
			if (IsEmpty())
			{
				return enSaveResults::svFaildEmptyObject;
			}
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;
		}

		case enMode::AddNewMode:
			//This Will Added To DB | File
			if (IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				//Adding Current Object To File
				_AddNew();

				//We Need To Update Mode After Addition
			_Mode = enMode::UpdateMode;
			return enSaveResults::svSucceeded;
			}

		}
	}

	static clsBankClient GetNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "","",AccountNumber, "", 0);
	}


	bool Delete()
	{
		vector<clsBankClient>vClients = _LoadClientsDateFromFile(FileName);
		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}

		_SaveCleintsDataToFile(FileName, vClients);
		
		//this is Super 
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector<clsBankClient>GetClientsList()
	{
		return _LoadClientsDateFromFile(FileName);
	}

	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients = GetClientsList();
		double TotalBalances = 0;

		for (clsBankClient& Client : vClients)
		{
			TotalBalances += Client.AccountBalance;
		}
		return TotalBalances;

	}

	 void Deposite(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	 void Withdraw(double Amount)
	 {
		 _AccountBalance -= Amount;
		 Save();
	 }

	 //This For Object Not For The Whole Objects->Don't Make It Static.
	  void Transfer(double Amount, clsBankClient& DestinationClient)
	 {
		  //I Validate Amount From Transfer Screen.
		 Withdraw(Amount);
		 DestinationClient.Deposite(Amount);

		 _RegisterTransferLog(Amount, DestinationClient);
	 }

	  static vector<stTransferLogRecord>GetTransferLogList()
	  {
		  return _LoadTransferLogRecordsFromFile();
	  }
	
};


 