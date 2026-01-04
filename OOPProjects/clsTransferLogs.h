#pragma once
#include "clsScreen.h";
#include "clsBankClient.h";

class clsTransferLogs : protected clsScreen
{
private:
	static void _PrintLogsRecordLine(clsBankClient::stTransLogRec log) {
		cout << setw(10) << left << "" << "| " << setw(25) << left << log.DateTime <<
			"| " << setw(8) << log.SenderUser <<
			"| " << setw(8) << log.ReceiverUser <<
			"| " << setw(10) << log.Amount <<
			"| " << setw(12) << log.SenderBal <<
			"| " << setw(12) << log.ReceiverBal <<
			"| " << setw(10) << log.UserName << endl;
	}

public:
	static void ShowTransferLogsScreen() {
		vector<clsBankClient::stTransLogRec> vLogs = clsBankClient::GetTransferLogs();
		string subTitle = "(" + to_string(vLogs.size()) + ") Record(S).";
		clsScreen::_DrawScreenHeader("  Transfer Log List Screen", subTitle);

		cout << "\n" << setw(10) << left << "" << "_______________________________________________________________________________________________________\n\n";
		cout << setw(10) << left << "" << "| " << setw(25) << left << "Date/Time" <<
			"| " << setw(8) << "s.Acct" <<
			"| " << setw(8) << "s.Acct" <<
			"| " << setw(10) << "Amount" <<
			"| " << setw(12) << "s.Balance" <<
			"| " << setw(12) << "r.Balance" <<
			"| " << setw(10) << "User";
		cout << "\n" << setw(10) << left << "" << "_______________________________________________________________________________________________________\n\n";

		if (vLogs.size() == 0) {
			cout << "\t\t\t\tNo Logs Records AvailableIn The System";
		}
		else {
			for (clsBankClient::stTransLogRec& log : vLogs) {
				_PrintLogsRecordLine(log);
			}
		}
		cout << setw(10) << left << "" << "_______________________________________________________________________________________________________\n";

	}
};

