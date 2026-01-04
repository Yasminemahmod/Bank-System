#pragma once
#include "clsScreen.h";

class clsDepositScreen : protected clsScreen
{
private:

	static void _AddAmountToClient(clsBankClient& client) {
		float depAmt = clsInputValidate::ReadNumber<float>("\nPlease Enter Deposit Amount? ", "\nInvalid Number, Please Enter Deposit Amount? ");
		cout << "\nAre you sure you want to perform this transaction? ";
		char answer = 'n';
		cin >> answer;
		if (tolower(answer) == 'y') {
			client.Deposit(depAmt);
			cout << "\nAmount Deposit Successfully."; 
			cout << "\n\nNew Balance is: " << client.AccountBalance;
		}
		else {
			cout << "\nOperation Was Cancelled.\n";
		}
	}

public:

	static void ShowDepositScreen() {
		clsScreen::_DrawScreenHeader("\tDeposit Screen");
		

		string accNum = clsInputValidate::ReadString("\n\nPlease Enter Account Number? ");
		if (accNum == "q" || accNum == "Q") return;

		while (!clsBankClient::IsClientExist(accNum)) {
			cout << "\nClient with [" << accNum << "] does not exist.\n";
			accNum = clsInputValidate::ReadString("\nPlease Enter Account Number? ");
			if (accNum == "q" || accNum == "Q") return;
		}

		clsBankClient client = clsBankClient::Find(accNum);
		clsScreen::_PrintClient(client);


		_AddAmountToClient(client);
		
	}

};

