#pragma once
#include "clsScreen.h";

class clsUpdateClient : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& client) {
		client.FirstName = clsInputValidate::ReadString("\nEnter FirstName: ");
		client.LastName = clsInputValidate::ReadString("\nEnter LastName: ");
		client.Email = clsInputValidate::ReadString("\nEnter Email: ");
		client.Phone = clsInputValidate::ReadString("\nEnter Phone: ");
		client.PinCode = clsInputValidate::ReadString("\nEnter PinCode: ");
		client.AccountBalance = clsInputValidate::ReadNumber<float>("\nEnter Account Balance: ");
	}

public:
	static void ShowUpdateClientScreen() {

		if (!currUser.CheckAccessPermission(clsUser::pUpdateClient)) {
			clsScreen::_CheckAccessRights("  Update Client Screen");
			return;
		}



		clsScreen::_DrawScreenHeader("  Update Client Screen");
		

		string accNum = clsInputValidate::ReadString("\n\nPlease Enter Client Account Number: ");
		if (accNum == "q" || accNum == "Q") return;

		while (!clsBankClient::IsClientExist(accNum)) {
			accNum = clsInputValidate::ReadString("\nAccount is not found, choose another one: ");
			if (accNum == "q" || accNum == "Q") return;
		}

		clsBankClient client = clsBankClient::Find(accNum);
		clsScreen::_PrintClient(client);

		char update = 'n';
		cout << "\nAre you sure you want to update this client? (y/n)? ";
		cin >> update;

		if (tolower(update) == 'y') {

			_ReadClientInfo(client);

			clsBankClient::enSaveResults saveRes = client.Save();

			switch (saveRes)
			{
			case clsBankClient::svSucceeded:
				cout << "\nAccount Updated Successfully :-)\n";
				clsScreen::_PrintClient(client);
				break;
			case clsBankClient::svFailedEmptyObject:
				cout << "\nError Account was not Updated Successfully because it's empty\n";
				break;
			default:
				break;
			}
		}

	}
};

