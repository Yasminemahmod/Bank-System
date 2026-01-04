#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h";
#include "clsUser.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";
#include "Global.h";

using namespace std;

class clsScreen
{
private:
	static short _ReadMenuOption(short len) {
		short _choice;
		cout << setw(37) << left << "";
		string msg = "Choose what do you want to do? [1 to " + to_string(len) + "]? ";
		_choice = clsInputValidate::ReadNumberBetween<short>(1, len, msg);

		return _choice;
	}

protected:
	//static short _choice;
	
	static void _DrawScreenHeader(string title, string subtitle = "") {
		cout << "\t\t\t\t\t_________________________________________\n\n";
		cout << setw(37) << left << "" << "\t\t" << title;

		if (subtitle != "") {
			cout << "\n\t\t\t\t\t" << subtitle;
		}
		cout << "\n\t\t\t\t\t_________________________________________";

		_LoggedUserAndDate();
	}

	static short _DrawMenu(string menuName, string menuArr[], short len) {
		short _choice;
		cout << "\n\n" << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\t  " << menuName << "\n";
		cout << setw(37) << left << "" << "==============================================\n";

		for (short i = 0; i < len; i++) {
			cout << setw(37) << left << "" << "\t[" << i + 1 << "] " << menuArr[i] << ".\n";
		}

		cout << setw(37) << left << "" << "==============================================\n";
		_choice = _ReadMenuOption(len);

		return _choice;
	}

	static void _PrintClient(clsBankClient client) {
		cout << "\nClient Card: ";
		cout << "\n____________________________\n";
		cout << "FirstName   : " << client.FirstName;
		cout << "\nLastName    : " << client.LastName;
		cout << "\nFullName    : " << client.FullName();
		cout << "\nEmail       : " << client.Email;
		cout << "\nPhone       : " << client.Phone;
		cout << "\nAcc. Number : " << client.AccountNumber();
		cout << "\nPassword    : " << client.PinCode;
		cout << "\nBalance     : " << client.AccountBalance;
		cout << "\n____________________________\n";
	}

	static void _PrintUser(clsUser user) {
		cout << "\nUser Card: ";
		cout << "\n____________________________\n";
		cout << "FirstName  : " << user.FirstName;
		cout << "\nLastName   : " << user.LastName;
		cout << "\nFullName   : " << user.FullName();
		cout << "\nEmail      : " << user.Email;
		cout << "\nPhone      : " << user.Phone;
		cout << "\nUsername   : " << user.UserName;
		cout << "\nPassword   : " << user.Password;
		cout << "\nPermission : " << user.Permission;
		cout << "\n____________________________\n";
	}

	static void _PrintCurrency(clsCurrency curr) {
		cout << "\nCurrency Card: ";
		cout << "\n____________________________\n";
		cout << "Country   : " << curr.Country();
		cout << "\nCode      : " << curr.CurrencyCode();
		cout << "\nName      : " << curr.CurrencyName();
		cout << "\nRate/(1$) : " << curr.Rate();
		cout << "\n____________________________\n";
	}

	static void _CheckAccessRights(string screenTitle) {
			
		clsScreen::_DrawScreenHeader(screenTitle);

		cout << "\n\n\nAccess Denied! Contact Your Admin.\n";
	}

	static void _LoggedUserAndDate() {
		cout << "\n\n\t\t\t\t\tUser: " << currUser.UserName;
		cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate());
	}
};

