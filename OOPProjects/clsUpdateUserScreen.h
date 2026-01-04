#pragma once
#include "clsScreen.h";

class clsUpdateUserScreen : protected clsScreen
{
private:
	static int _ReadUserPermission() {
		string perArr[8] = { "Show Client List", "Add New Client", "Delete Client", "Update Client", "Find Client", "Transaction", "Manage Users", "Login Register" };
		short len = sizeof(perArr) / sizeof(perArr[0]);
		char answer = 'n';
		int per = 0;

		cout << "\nPlease Enter Permission:\n";
		cout << "\nDo you want to give full access? y/n? ";
		cin >> answer;
		if (tolower(answer) == 'y') {
			return -1;
		}

		cout << "\nDo you want to give access to:\n";
		for (short i = 0; i < len; i++) {
			cout << "\n" << perArr[i] << "? y/n? ";
			cin >> answer;

			if (tolower(answer) == 'y') {
				per += pow(2, i);
			}
		}

		return per;

	}

	static void _ReadUserInfo(clsUser& user) {

		user.FirstName = clsInputValidate::ReadString("\nEnter First Name: ");
		user.LastName = clsInputValidate::ReadString("\nEnter Last Name: ");
		user.Email = clsInputValidate::ReadString("\nEnter Email: ");
		user.Phone = clsInputValidate::ReadString("\nEnter Phone: ");
		user.Password = clsInputValidate::ReadString("\nEnter Password: ");
		user.Permission = _ReadUserPermission();

	}


public:
	static void ShowUpdateUserScreen() {
		clsScreen::_DrawScreenHeader("    Update User Screen");
		

		string userName = clsInputValidate::ReadString("\n\nPlease Enter User Name: ");
		if (userName == "q" || userName == "Q") return;

		while (!clsUser::IsUserExist(userName)) {
		 userName = clsInputValidate::ReadString("\nUser is bot found, Choose another one: ");
			if (userName == "q" || userName == "Q") return;
		}

		clsUser user = clsUser::Find(userName);
		clsScreen::_PrintUser(user);

		char answer = 'n';
		cout << "\nAre you sure you want to update this user? y/n? ";
		cin >> answer;

		if (tolower(answer) == 'y') {
			cout << "\nUpdate User Info:";
			cout << "\n_______________________\n";
			_ReadUserInfo(user);
			clsUser::enSaveResults saveResult = user.Save();

			switch (saveResult) {
				case clsUser::enSaveResults::svSucceeded:
					cout << "\nUser Updated Successfully :-)\n";
					clsScreen::_PrintUser(user);
					break;
				case clsUser::enSaveResults::svFailedEmptyObject:
					cout << "\nError User Was not saved because it's Empty\n";
					break;
			}
		}
	}
};

