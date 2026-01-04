#pragma once
#include "clsScreen.h";

class clsUpdateCurrencyScreen : protected clsScreen
{
private:
	static void _UpdateToNewRate(clsCurrency curr) {
		cout << "\n\nUpdate Currency Rate";
		cout << "\n_____________________________\n";
		float newRate = clsInputValidate::ReadNumber<float>("\nEnter New Rate: ");
		curr.UpdateRate(newRate);

		cout << "\nCurrency rate Updated Successfully :-)\n";
		clsScreen::_PrintCurrency(curr);
	}

public:
	static void ShowUpdateCurrencyScreen() {
		clsScreen::_DrawScreenHeader("Update currency Screen");
		
		string code = clsInputValidate::ReadString("\n\nPlease Enter Currency Code: ");
		if (clsString::LowerString(code) == "q") return;

		while (!clsCurrency::IsCurrencyExist(code)) {
			code = clsInputValidate::ReadString("\nCountry/Code Not Found, Enter Another Currency Country/Code To Search? ");
			if (clsString::LowerString(code) == "q") return;
		}

		clsCurrency curr = clsCurrency::Find(code);
		clsScreen::_PrintCurrency(curr);

		cout << "\n\nAre you sure you want to update the rate of this currency? y/n? ";
		char answer;
		cin >> answer;

		if (tolower(answer) == 'y') {
			_UpdateToNewRate(curr);

		}
	}
};

