#pragma once

#include"clsScreen.h"
#include"clsBankClient.h"

class clsTransferLogScreen:protected clsScreen
{

	static void _PrintRecoudLind(clsBankClient::stTransferLogRecord Record)
	{
		cout << setw(8) << left << "" <<
			"| " << setw(25) << left << Record.DateTime <<
			"| " << setw(10) << left <<Record.SourceAccountNumber<<
			"| " << setw(10) << left <<Record.DestinationAccountNumber<<
			"| " << setw(8) << left << Record.Amount<<
			"| " << setw(10) << left <<Record.SourceBalanceAfter<<
			"| " << setw(8) << left << Record.DestinationBalanceAfter<<
			"| " << setw(10) << left <<Record.UserName<< " |"<<endl;

		cout << setw(8) << left << "" << clsString::Get_N_Chars('=', 97) << "\n";
	}

public:
	static void showTransferLogScreen()
	{
		vector<clsBankClient::stTransferLogRecord>vRecords = clsBankClient::GetTransferLogList();

		string Title = "\t  Transfer Log Screen";
		string SubTitle = "\t     (" + to_string(vRecords.size()) + ") Records.";
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << clsString::Get_N_Chars('=', 97)<<"\n";
		cout << setw(8) << left << "" << "| " << setw(25) << left << "Date/Time" << "| " << setw(10) << left << "S.Acct" << "| " << setw(10) << left << "D.Acct" << "| " << setw(8) << left << "Amount" << "| " << setw(10) << left << "S.Balance" << "| " << setw(8) << left << "D.Balance" << "| " << setw(10) << left << "User Name" << "|\n";
		cout << setw(8) << left << "" << clsString::Get_N_Chars('=', 97) << "\n";

		for (clsBankClient::stTransferLogRecord Record : vRecords)
		{
			_PrintRecoudLind(Record);
		}

}

};

