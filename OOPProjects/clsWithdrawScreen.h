#pragma once

#include "clsScreen.h";

class clsWithdrawScreen : protected clsScreen
{
private:

	static void _SubtractAmountToClient(clsBankClient& client) {
		float withdrawAmt = clsInputValidate::ReadNumber<float>("\nPlease Enter Withdraw Amount? ", "\nInvalid Number, Please Enter Withdraw Amount? ");

		cout << "\nAre you sure you want to perform this transaction? ";
		char answer = 'n';
		cin >> answer;
		if (tolower(answer) == 'y') {
			if (client.Withdraw(withdrawAmt)) {
				cout << "\nAmount Withdraw Successfully.";
				cout << "\n\nNew Balance is: " << client.AccountBalance;
			}
			else {
				cout << "\nCan not withdraw,Insufficient Balance!\n";
				cout << "\nAmount To Withdraw Is: " << withdrawAmt;
				cout << "\nYour Balance Is: " << client.AccountBalance;
			}
		}
		else {
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:
	static void ShowWithdrawScreen() {
		clsScreen::_DrawScreenHeader("\tWithdraw Screen");
		

		string accNum = clsInputValidate::ReadString("\n\nPlease Enter Account Number? ");
		if (accNum == "q" || accNum == "Q") return;

		while (!clsBankClient::IsClientExist(accNum)) {
			cout << "\nClient with [" << accNum << "] does not exist.\n";
			accNum = clsInputValidate::ReadString("\nPlease Enter Account Number? ");
			if (accNum == "q" || accNum == "Q") return;
		}

		clsBankClient client = clsBankClient::Find(accNum);
		clsScreen::_PrintClient(client);


		_SubtractAmountToClient(client);
	}
};


