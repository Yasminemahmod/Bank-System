#pragma once
#include "clsScreen.h";
#include "clsCurrency.h";

class clsCurrenciesListScreenScreen : protected clsScreen
{
private:
	static void _ShowCurrenciesList(clsCurrency c) {
		cout << setw(5) << left << "" << "| " << setw(30) << left << c.Country() <<
			"| " << setw(10) << c.CurrencyCode() <<
			"| " << setw(40) << c.CurrencyName() <<
			"| " << setw(20) << c.Rate() << "\n";
	}


public:
	static void ShowCurrenciesListScreen() {
		vector<clsCurrency> curr = clsCurrency::GetCurrenciesList();
		string subTitle = "\t    (" + to_string(curr.size()) + ") Currency.";
		clsScreen::_DrawScreenHeader("Currencies List Screen", subTitle);

		cout << "\n\n\n" << setw(5) << left << "" << "_____________________________________________________________________________________________________________\n\n";
		cout << setw(5) << left << "" << "| " << setw(30) << left << "Country" <<
			"| " << setw(10) << "Code" <<
			"| " << setw(40) << "Name" <<
			"| " << setw(20) << "Rate/(1$)";
		cout << endl << setw(5) << left << "" << "_____________________________________________________________________________________________________________\n\n";


		if (curr.size() == 0) {
			cout << "\t\t\t\tNo Clients AvailableIn The System";
		}
		else {
			for (clsCurrency& c : curr) {
				_ShowCurrenciesList(c);
			}
		}


		cout << setw(5) << left << "" << "_____________________________________________________________________________________________________________\n\n";

	}
};

