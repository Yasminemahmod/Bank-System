#pragma once
#include "clsScreen.h";

class clsTransfer : protected clsScreen
{
private:

	static void _PrintClientInfo(clsBankClient client) {
		cout << "\nClient Card: ";
		cout << "\n____________________________\n";
		cout << "\nFullName    : " << client.FullName();
		cout << "\nAcc. Number : " << client.AccountNumber();
		cout << "\nBalance     : " << client.AccountBalance;
		cout << "\n____________________________\n";
	}

	static clsBankClient _ReadClientInfo(string msg) {
		string accNum = clsInputValidate::ReadString(msg);

		while (!clsBankClient::IsClientExist(accNum)) {
			accNum = clsInputValidate::ReadString("\nAccount is not found, choose another one: ");
		}

		clsBankClient client = clsBankClient::Find(accNum);
		_PrintClientInfo(client);

		return client;
	}

public:
	static void ShowTransferScreen() {
		clsScreen::_DrawScreenHeader("    Transfer screen");

		clsBankClient sender = _ReadClientInfo("\n\n\nPlease Enter account number to transfer from: ");
		clsBankClient receiver = _ReadClientInfo("\nPlease Enter account number to transfer to: ");

		float transAmt = clsInputValidate::ReadNumber<float>("\nEnter Transfer Amount? ");
		while (transAmt > sender.AccountBalance) {
			transAmt = clsInputValidate::ReadNumber<float>("\nAmount exceeds the available balance, Enter Another Amount? ");
		 }

		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char answer = 'n';
		cin >> answer;

		if (tolower(answer) == 'y') {
			if (sender.AccountNumber() == receiver.AccountNumber()) {
				cout << "\nSorry, You can't transfer to the same account.\n";
				return;
			}
			if (sender.TransferTo(transAmt, receiver)) {
				cout << "T\nTransfer Done Successfully.\n";
			}
			else {
				cout << "T\nTransfer Failed.\n";
			}

			_PrintClientInfo(sender);
			_PrintClientInfo(receiver);
		}
	}
};

