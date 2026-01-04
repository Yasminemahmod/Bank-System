#pragma once
#include "clsScreen.h";

class clsFindClient : protected clsScreen
{
public:
	static void ShowFindClientScreen() {

		if (!currUser.CheckAccessPermission(clsUser::pFindClietn)) {
			clsScreen::_CheckAccessRights("  Find Client Screen");
			return;
		}


		clsScreen::_DrawScreenHeader("  Find Client Screen");
		

		string accNum = clsInputValidate::ReadString("\n\nPlease Enter Client Account Number: ");
		if (accNum == "q" || accNum == "Q") return;

		while (!clsBankClient::IsClientExist(accNum)) {
			accNum = clsInputValidate::ReadString("\nAccount is not found, choose another one: ");
			if (accNum == "q" || accNum == "Q") return;
		}

		clsBankClient client = clsBankClient::Find(accNum);
		cout << "\nClient Found :-)\n";
		clsScreen::_PrintClient(client);
	}
};

