#pragma once
#include "clsScreen.h";


class clsClientListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient client) {
		cout << setw(10) << left << "" << "| " << setw(15) << left << client.AccountNumber() <<
			"| " << setw(20) << client.FullName() <<
			"| " << setw(15) << client.Phone <<
			"| " << setw(25) << client.Email <<
			"| " << setw(9) << client.PinCode <<
			"| " << client.AccountBalance << endl;
	}

public:
	static void ShowClientsList() {

		if (!currUser.CheckAccessPermission(clsUser::pListClients)) {
			clsScreen::_CheckAccessRights("   Client List Screen");
			return;
		}


		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string subTitle = "\t   (" + to_string(vClients.size()) + ") Client(s)";
		clsScreen::_DrawScreenHeader("   Client List Screen", subTitle);
		

		cout << "\n" << setw(10) << left << "" << "_______________________________________________________________________________________________________\n\n";
		cout << setw(10) << left << "" << "| " << setw(15) << left << "Account Number" <<
			"| " << setw(20) << "Client Name" <<
			"| " << setw(15) << "Phone" <<
			"| " << setw(25) << "Email" <<
			"| " << setw(9) << "Pin Code" <<
			"| " << "Balance\n";
		cout << setw(10) << left << ""  << "_______________________________________________________________________________________________________\n\n";

		if (vClients.size() == 0) {
			cout << "\t\t\t\tNo Clients AvailableIn The System";
		}
		else {
			for (clsBankClient& cl : vClients) {
				_PrintClientRecordLine(cl);
			}
		}

		cout << setw(10) << left << "" << "_______________________________________________________________________________________________________\n";
	}
};

