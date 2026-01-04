#pragma once
#include "clsScreen.h";
#include "clsUtil.h";

class clsTotalBalancesScreen : protected clsScreen
{

private:
	static void _PrintClientRecordBalanceLine(clsBankClient c) {
		cout << setw(15) << left << "" << "\t\t| " << setw(15) << left << c.AccountNumber() <<
			"| " << setw(40) << c.FullName() <<
			"| " << c.AccountBalance << "\n";
	}

public:
	static void ShowTotalBalancesScreen() {
		float totalBal = clsBankClient::GetTotalBalances();
		vector<clsBankClient> clients = clsBankClient::GetClientsList();
		string subTitle = "  (" + to_string(clients.size()) + ") Client(s)";

		clsScreen::_DrawScreenHeader("Balances List Screen", subTitle);
		


		cout << "\n" << setw(15) << left << "" << "_____________________________________________________________________________________\n\n";
		cout << setw(15) << left << "" << "\t\t| " << setw(15) << left << "Account Number" <<
			"| " << setw(40) << "Client Name" <<
			"| " << "Balance\n";
		cout << setw(15) << left << "" << "_____________________________________________________________________________________\n\n";

		if (clients.size() == 0) {
			cout << "\t\t\t\tNo Clients AvailableIn The System";
		}
		else {
			for (clsBankClient& cl : clients) {
				_PrintClientRecordBalanceLine(cl);
			}
		}

		cout << setw(15) << left << "" << "_____________________________________________________________________________________\n\n";

		//cout << setw(40) << left << "" << "\t\t" << title;
		cout << "\n\t\t\t\t\t\tTotal Balances = " << totalBal;

		cout << "\n\t\t\t\t( " << clsUtil::ConvertNumberToString(totalBal) << " )\n";
	}
};


