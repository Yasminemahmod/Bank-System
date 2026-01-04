#pragma once
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsString.h";

class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _ShowResults(clsCurrency curr) {

		if (curr.IsEmpty()) {
			cout << "\nCurrency Was Not Found\n";
		}
		else {
			cout << "\nCurrency Found :-)\n";
			clsScreen::_PrintCurrency(curr);
		}
	}


public:
	static void ShowFindCurrencyScreen() {
		clsScreen::_DrawScreenHeader("  Find Currency Screen");
		
		string curr = clsInputValidate::ReadString("\n\nEnter Currency Country/Code To Search? ");
		if (clsString::LowerString(curr) == "q") return;

		while (!clsCurrency::IsCurrencyExist(curr)) {
			curr = clsInputValidate::ReadString("\nCountry/Code Not Found, Enter Another Currency Country/Code To Search? ");
			if (clsString::LowerString(curr) == "q") return;
		}

		clsCurrency currInfo = clsCurrency::Find(curr);
		_ShowResults(currInfo);

	}

};

