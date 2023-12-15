#include<iostream>
#include<string>
#include<list>
#include "Estate.h"

using namespace std;
int main() {
	Estate estate;
	int mainMenu = 0;
	
	do
	{
		system("cls");
		cout << "Choice\n" << "1 - Create user\n2 - Login user\n3 - Exit\n";
		cout << "Your choice: ";
		cin >> mainMenu;
		switch (mainMenu)
		{
		case 1:
			estate.createUser();
			break;
		case 2: {
			if (estate.loginUser())
			{
				estate.mainMenu();
			}
			else {
				cout << "You entered an incorrect username or password\n";
				system("pause");
			}
		}break;
		case 3: {
			exit(0);
		}break;
		default:
			break;
		}
	} while (mainMenu!=0);

	return 0;
}