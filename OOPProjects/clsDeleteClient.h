#pragma once
#include "clsScreen.h";

class clsDeleteClient : protected clsScreen
{
public:
	static void ShowDeleteClientScreen() {

		if (!currUser.CheckAccessPermission(clsUser::pDeleteClient)) {
			clsScreen::_CheckAccessRights("   Delete Client Screen");
			return;
		}


		clsScreen::_DrawScreenHeader("   Delete Client Screen");
		
		string accNum = clsInputValidate::ReadString("\n\nPlease Enter Client Account Number: ");
		if (accNum == "q" || accNum == "Q") return;

		while (!clsBankClient::IsClientExist(accNum)) {
			accNum = clsInputValidate::ReadString("\nAccount is not found, choose another one: ");
			if (accNum == "q" || accNum == "Q") return;
		}

		clsBankClient client = clsBankClient::Find(accNum);
		clsScreen::_PrintClient(client);

		char del;
		cout << "\nDo You Want to delete this client? (y/n)? ";
		cin >> del;

		if (tolower(del) == 'y') {
			client.Delete();
			cout << "\nClient Deleted Successfully.\n";
			clsScreen::_PrintClient(client);
		}

	}
};

