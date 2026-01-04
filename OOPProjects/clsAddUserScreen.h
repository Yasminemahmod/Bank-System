#pragma once
#include "clsScreen.h";

class clsAddUserScreen : protected clsScreen
{
private:

	static int _ReadUserPermission() {
		string perArr[8] = { "Show Client List", "Add New Client", "Delete Client", "Update Client", "Find Client", "Transaction", "Manage Users", "Login Register"};
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

	static clsUser _ReadUserInfo(string userName) {
		clsUser user = clsUser::GetAddNewUserObject(userName);

		user.FirstName = clsInputValidate::ReadString("\nEnter First Name: ");
		user.LastName = clsInputValidate::ReadString("\nEnter Last Name: ");
		user.Email = clsInputValidate::ReadString("\nEnter Email: ");
		user.Phone = clsInputValidate::ReadString("\nEnter Phone: ");
		user.Password = clsInputValidate::ReadString("\nEnter Password: ");
		user.Permission = _ReadUserPermission();

		return user;
	}

public:
	static void ShowAddNewUserScreen() {
		clsScreen::_DrawScreenHeader("   Add New User Screen");
		

		string userName = clsInputValidate::ReadString("\n\n\nPlease Enter UserName: ");
		if (userName == "q" || userName == "Q") return;

		while (clsUser::IsUserExist(userName)) {
			userName = clsInputValidate::ReadString("\nUserName is already used, Choose another one: ");
			if (userName == "q" || userName == "Q") return;
		}

		clsUser newUser = _ReadUserInfo(userName);

		clsUser::enSaveResults saveResult = newUser.Save();
		switch(saveResult) {
			case clsUser::enSaveResults::svSucceeded:
				cout << "\nUser Added Successfully :-)\n";
				clsScreen::_PrintUser(newUser);
				break;
			case clsUser::enSaveResults::svFailedEmptyObject:
				cout << "\nError User Was not saved because it's Empty\n";
				break;
			case clsUser::enSaveResults::svFailedExist:
				cout << "\nError User Was not saved because it's Exist\n";
				break;
		}

		
	}

};

