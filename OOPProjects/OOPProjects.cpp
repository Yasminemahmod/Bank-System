#include <iostream>
#include "clsLogin.h";



using namespace std;

int main() {

	while (!IsLocked) {
		clsLogin::ShowLoginScreen();
	}

	//system("pause>0");
	return 0;
}