#pragma once
#include "clsScreen.h";
#include "clsUser.h";
#include "clsCurrenciesListScreen.h";
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyScreen.h";
#include "clsCurrencyCalculator.h";

class clsCurrencyMainScreen : protected clsScreen
{
private:
	string _CurrMenuArr[5] = { "List Currencies", "Find Currency", "Update Rate", "Currency Calculator", "Main Menu" };
	short _len = sizeof(_CurrMenuArr) / sizeof(_CurrMenuArr[0]);
	enum enCurrMenuOpt { SHOWLIST = 1, FIND = 2, UPDATE = 3, CURRCALC = 4, MAINMENU = 5};


	static void _GoBackToCurrMenuScreen() {
		cout << "\n\nEnter any key to go back to main menu...";
		system("pause>0");
		ShowCurrencyMainScreen();
	}

	static void _ShowCurrenciesListScreen() {
		//cout << "Show Currencies List Screen\n";
		clsCurrenciesListScreenScreen::ShowCurrenciesListScreen();
	}

	static void _FindCurrencyScreen() {
		//cout << "Find Currency Screen\n";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _UpdateRateScreen() {
		//cout << "Update Rate Screen\n";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _CurrencyCalculatorScreen() {
		//cout << "Currency Calculator Screen\n";
		clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
	}



	static void _PerformMainMenuOption(enCurrMenuOpt op) {

		switch (op)
		{
		case enCurrMenuOpt::SHOWLIST:
			system("cls");
			_ShowCurrenciesListScreen();
			_GoBackToCurrMenuScreen();
			break;
		case enCurrMenuOpt::FIND:
			system("cls");
			_FindCurrencyScreen();
			_GoBackToCurrMenuScreen();
			break;
		case enCurrMenuOpt::UPDATE:
			system("cls");
			_UpdateRateScreen();
			_GoBackToCurrMenuScreen();
			break;
		case enCurrMenuOpt::CURRCALC:
			system("cls");
			_CurrencyCalculatorScreen();
			_GoBackToCurrMenuScreen();
			break;
		case enCurrMenuOpt::MAINMENU:
			// Return Back to Main Menu
			break;
		}
	}

public:
	static void ShowCurrencyMainScreen() {
		system("cls");

		if (!currUser.CheckAccessPermission(clsUser::enPermissions::pCurrExch)) {
			clsScreen::_DrawScreenHeader("Currency Exchange Main screen");
			cout << "\n\n" << setw(10) << left << "" << "Enter any key to go back to main menu...";
			system("pause>0");
			return;
		}

		clsScreen::_DrawScreenHeader("Currency Exchange Main screen");
		clsCurrencyMainScreen currScreen;
		short op = clsScreen::_DrawMenu("Currency Exchange menu", currScreen._CurrMenuArr, currScreen._len);

		_PerformMainMenuOption(enCurrMenuOpt(op));
	}
};

