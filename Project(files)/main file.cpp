#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void menu()
{
	cout << "===================== M E N U ===================== \n";
	cout << "* creat a file[1]." << endl;
	cout << "* Open  a file[2]." << endl;
	cout << "* Duplicate a file to another location[3]." << endl;
	cout << "* Reverse a file and save it in another file[4]." << endl;
	cout << "=================================================== \n";
}

int main()
{
	int n, counter = 1, i, j;
	const int max = 100;
	char a[max], ra[max], buff = 'n';
	string name, name2, address, address2, text;
	ofstream Myfile;
	ifstream Myfilein;

	//................. Do while loop for repetation of main function.
	do {
		menu();
		cout << "Enter the number that you choice: ";
		cin >> n;

		switch (n)
		{
			//{........ Case one for creating a file.......}
		case 1:

			do {
				cout << "\nEnter the address of your File: ";
				cin >> address;
				cout << "Enter the name of your File: ";
				cin.ignore();
				getline(cin, name);

				Myfile.open(address + name, ios::out);

				if (!Myfile) {
					system("cls");
					cout << "The file could not be opened.......try again" << endl;
				}
			} while (!Myfile);

			cout << "\n Enter a line or enter(0) to finish." << endl;
			while (text != "0") {
				getline(cin, text);
				if (text != "0") {
					Myfile << text << endl;
				}

			}
			Myfile.close();
			system("cls");
			cout << "Your file was created" << endl;
			break;
			//{........ Second case .......}
		case 2:
			if (counter != 1) {
				cout << "Do you want to use from the last address that you entered? (y/n): ";
				cin >> buff;
			}
			if (buff == 'N' || buff == 'n') {
				do {
					cout << "\nEnter the address of your File: ";
					cin >> address;
					cout << "Enter the name of your File: ";
					cin.ignore();
					getline(cin, name);
					Myfilein.open(address + name, ios::in);

					if (!Myfilein) {
						system("cls");
						cout << "The file could not be opened......... try again" << endl;
					}
				} while (!Myfilein);
			}
			Myfilein.close();
			system("cls");
			Myfilein.open(address + name, ios::in);

			cout << "================ M E N U ============== \n";
			cout << "* Print your file in screen[1]." << endl;
			cout << "* Add more text in your file[2]." << endl;
			cout << "======================================= \n";
			cout << "Enter the number of option that you chose: ";
			cin >> n;
			//.................Switch case in case 2
			switch (n) {
			case 1:
				cout << "This is your file text: \n" << endl;
				cout << "\n *|-----------------------|*" << endl;
				while (Myfilein) {

					buff = Myfilein.get();
					cout << buff;
				}
				cout << "\n *|-----------------------|*" << endl;
				break;
			case 2:
				Myfile.open(address + name, ios::app);

				cout << "Enter a line or enter(0) to finish." << endl;
				while (text != "0") {
					getline(cin, text);
					if (text != "0") {
						Myfile << text << endl;;
					}

				}
				break;
			}
			cout << endl;
			Myfilein.close();
			break;
			//.................case 3 from Menu
		case 3:
			if (counter != 1) {
				cout << "\nDo you want to use from the last address that you entered? (Y/N): ";
				cin >> buff;
			}
			if (buff == 'N' || buff == 'n') {
				do {
					cout << "\nEnter the address of your File: ";
					cin >> address;
					cout << "Enter the name of your File: ";
					cin.ignore();
					getline(cin, name);
					Myfilein.open(address + name, ios::in);

					if (!Myfilein) {
						system("cls");
						cout << "File isn't open...... try again" << endl;
					}
				} while (!Myfilein);
			}
			else Myfilein.open(address + name, ios::in);
			while (Myfilein) {

				buff = Myfilein.get();
				if (buff != 'ÿ')
					text += buff;
			}
			Myfilein.close();

			do {
				cout << "\nEnter the address that you want to Rewrite: ";
				cin >> address2;
				cout << "Enter the name of your File that you want to Rewrite: ";
				cin.ignore();
				getline(cin, name2);
				Myfile.open(address2 + name2, ios::app);

				if (!Myfile) {
					system("cls");
					cout << "File isn't open...... try again" << endl;
				}
			} while (!Myfile);
			Myfile << text;

			//......................................Ask from user to want to add more text or not.
			cout << "\nDo you want to Add more text in your file (Y/N)" << endl;
			cin >> buff;

			if (buff == 'Y' || buff == 'y') {
				cout << "Enter a line or enter(0) to finish." << endl;

				while (text != "0") {
					getline(cin, text);
					if (text != "0") {
						Myfile << text << endl;
					}

				}
			}
			Myfile.close();
			cout << "Your file was Rewritten" << endl;
			break;
		case 4:
			do {
				cout << "\nEnter the address of your File: ";
				cin >> address;
				cout << "Enter the name of your File: ";
				cin.ignore();
				getline(cin, name);

				Myfilein.open(address + name, ios::in);

				if (!Myfilein) {
					system("cls");
					cout << "The file could not be opened.......try again" << endl;
				}
			} while (!Myfilein);
			Myfile.close();
			
			for (i = 0; Myfilein; i++) {

				buff = Myfilein.get();
				a[i] = buff;
			}
			i--;
			for (j = 0; i >= 0; j++, i--) {
				ra[j] = a[i];
			}
			ra[j] = '\0';
			do {
				cout << "\nEnter the address that you want to Rewrite: ";
				cin >> address2;
				cout << "Enter the name of your File that you want to Rewrite: ";
				cin.ignore();
				getline(cin, name2);
				Myfile.open(address2 + name2, ios::app);

				if (!Myfile) {
					system("cls");
					cout << "File isn't open...... try again" << endl;
				}
			} while (!Myfile);

			for (i = 0; ra[i]; i++) {
				if (ra[i] != 'ÿ') {
					Myfile << ra[i];
				}
			}
			Myfile.close();
			system("cls");
			cout << "Your file Reversed." << endl;
		}
		cout << "\n *|-----------------------------------------------------------------------|*" << endl;
		cout << "Do you want to continue from the first? (Y/N): ";
		cin >> buff;
		if (buff == 'Y' || buff == 'y') {
			system("cls");
		}
		counter = 0;
	} while (buff == 'Y' || buff == 'y');

	return 0;
}


