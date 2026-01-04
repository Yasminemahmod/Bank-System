#pragma once
#include "clsScreen.h";

class clsAddNewClient : protected clsScreen
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
	static void ShowAddNewClientsScreen() {

		if (!currUser.CheckAccessPermission(clsUser::pAddNewClient)) {
			clsScreen::_CheckAccessRights("Add New Client Screen");
			return;
		}


		clsScreen::_DrawScreenHeader("Add New Client Screen");

		string accNum = clsInputValidate::ReadString("\n\nEnter Client Account Number: ");

		if (accNum == "q" || accNum == "Q") return;

		while (clsBankClient::IsClientExist(accNum)) {
			string accNum = clsInputValidate::ReadString("Account Number Is Already Exist, Enter Another Client Account Number: ");
			if (accNum == "q" || accNum == "Q") return;
		}

		clsBankClient client = clsBankClient::GetAddNewClientObject(accNum);

		_ReadClientInfo(client);

		clsBankClient::enSaveResults saveRes = client.Save();

		switch (saveRes)
		{
		case clsBankClient::svSucceeded:
			cout << "\nAccount Added Successfully :-)\n";
			break;
		case clsBankClient::svFailedEmptyObject:
			cout << "\nError Account was not Added Successfully because it's empty\n";
			break;
		default:
			break;
		}

		clsScreen::_PrintClient(client);
	}
};

