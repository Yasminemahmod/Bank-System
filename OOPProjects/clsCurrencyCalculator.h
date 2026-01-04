#pragma once
#include "clsScreen.h";

class clsCurrencyCalculator : protected clsScreen
{
private:
	static void _PrintCurrency(string dir ,clsCurrency curr) {
		cout << "\n" << dir << ":";
		cout << "\n____________________________\n\n";
		cout << "Country   : " << curr.Country();
		cout << "\nCode      : " << curr.CurrencyCode();
		cout << "\nName      : " << curr.CurrencyName();
		cout << "\nRate/(1$) : " << curr.Rate();
		cout << "\n____________________________\n\n";
	}

	static clsCurrency _ReadCurrency(string msg) {
		string code = clsInputValidate::ReadString(msg);
		while (!clsCurrency::IsCurrencyExist(code)) {
			msg = "\nCurrency Not Found, " + msg;
			code = clsInputValidate::ReadString(msg);
		}
		return clsCurrency::Find(code);
	}

	static void _ConvertCurrency(clsCurrency curr1, clsCurrency curr2, float amount) {
		_PrintCurrency("Convert From", curr1);

		if (clsString::UpperString(curr2.CurrencyCode()) == "USD") {
			cout << "\n" << amount << " " << curr1.CurrencyCode() << " = ";
			cout << curr1.ConvertCurrToUSD(amount) << " USD\n";
		}
		else {
			_PrintCurrency("To", curr2);

			cout << "\n" << amount << " " << curr1.CurrencyCode() << " = ";
			cout << amount << " " << curr1.ConvertToOtherCurrency(curr2, amount) << "\n";
			
		}
	}

public:
	static void ShowCurrencyCalculatorScreen() {
		char anotherCalc = 'n';

		do {
			system("cls");
			clsScreen::_DrawScreenHeader("Currency Calculator Screen");

			clsCurrency curr1 = _ReadCurrency("\n\nPlease Enter Currency1 code: ");
			clsCurrency curr2 = _ReadCurrency("\n\nPlease Enter Currency2 code: ");

			float amount = clsInputValidate::ReadNumber<float>("\nEnter Amount to Exchange: ");

			_ConvertCurrency(curr1, curr2, amount);

			cout << "\nDo you want to perform another calculation? y/n? ";
			cin >> anotherCalc;

		} while (tolower(anotherCalc) == 'y');
	}
};

