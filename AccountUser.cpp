#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include "Account.cpp"

using namespace std;

void write_account();			 // function to write record in binary file
void display_sp(int);			 // function to display account details given by user
void rename_account(int);		 // function to rename record of file
void delete_account(int);		 // function to delete record of file
void display_all();				 // function to display all account details
void deposit_withdraw(int, int); // function to desposit/withdraw amount for given account
void sort_account_numbers();

//***************************************************************
//    	function to write in file
//****************************************************************

void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
	outFile.close();
}

//***************************************************************
//    	function to read specific record from file
//****************************************************************

void display_sp(int n)
{
	account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << " X=======================================X " << endl ;
	cout << " |           BALANCE DETAILS             | " << endl ;

	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
	{
		if (ac.retAccNum() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\nAccount number does not exist" << endl;
	cout << "\nPress any key to return to the main menu...";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to rename record of file
//****************************************************************

void rename_account(int n)
{
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(account));
		if (ac.retAccNum() == n)
		{
			ac.show_account();
			cout << " X=======================================X " << endl;
			cout << " |    Enter The New Details of account   | " << endl;
			
			ac.rename();
			int pos = (-1) * static_cast<int>(sizeof(account));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *>(&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}

//***************************************************************
//    	function to delete record of file
//****************************************************************

void delete_account(int n)
{
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
	{
		if (ac.retAccNum() != n)
		{
			outFile.write(reinterpret_cast<char *>(&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\n\tRecord Deleted ..";
	cout << "\nPress any key to return to the main menu...";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to display all accounts deposit list
//****************************************************************

void display_all()
{
	account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "| ACCOUNT NUMBER | USERNAME     | Type  | Balance  |\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
	cout << "\nPress any key to return to the main menu...";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    	function to deposit and withdraw amounts
//****************************************************************

void deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char *>(&ac), sizeof(account));
		if (ac.retAccNum() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << " X=======================================X " << endl;
				cout << " |           2. DEPOSIT CASH             | " << endl;
				cout << " X=======================================X " << endl;
				cout << "      Enter The amount to deposit: ";
				cin >> amt;
				ac.depositC(amt);
			}
			if (option == 2)
			{
				cout << " X=======================================X " << endl;
				cout << " |           3. DEPOSIT CASH             |  " << endl;
				cout << " X=======================================X " << endl;
				cout << "      Enter The amount to withdraw: ";
				cin >> amt;
				int bal = ac.retdeposit() - amt;

				ac.withdraw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char *>(&ac), sizeof(account));
			cout << "\n\n\t Record Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n Record Not Found ";
}

void sort_account_numbers()
{
	account ac;
	account accounts[100]; // Assuming a maximum of 100 accounts, adjust as needed
	int count = 0;
	char sortOrder;

	ifstream inFile;
	inFile.open("account.dat", ios::binary);

	if (!inFile)
	{
		cout << "File could not be opened! Press any key to return...";
		cin.ignore();
		cin.get();
		return;
	}

	// Reading accounts from the file into an array
	while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
	{
		accounts[count++] = ac;
	}
	inFile.close();

	// Ask user for sorting order
	cout << "\n\n\n";
	cout << " X=======================================X " << endl;
	cout << " |         Choose sorting order          | " << endl;
	cout << " X=======================================X " << endl;
	cout << " |           1. Ascending                | " << endl;
	cout << " |           2. Descending               | " << endl;
	cout << " X=======================================X " << endl;
	cout << "          Enter your choice: ";
	cin >> sortOrder;

	// Sorting account numbers using Bubble Sort
	for (int i = 0; i < count - 1; i++)
	{
		for (int j = 0; j < count - i - 1; j++)
		{
			bool swapNeeded = false;
			if (sortOrder == '1' && accounts[j].retAccNum() > accounts[j + 1].retAccNum())
			{
				swapNeeded = true;
			}
			else if (sortOrder == '2' && accounts[j].retAccNum() < accounts[j + 1].retAccNum())
			{
				swapNeeded = true;
			}

			if (swapNeeded)
			{
				// Swap accounts
				account temp = accounts[j];
				accounts[j] = accounts[j + 1];
				accounts[j + 1] = temp;
			}
		}
	}

	// Displaying sorted account details
	cout << "====================================================\n";
	cout << "|              Sorted Account Details              |\n";
	cout << "====================================================\n";
	cout << "| ACCOUNT NUMBER | USERNAME     | Type  | Balance  |\n";
	cout << "====================================================\n";
	for (int i = 0; i < count; i++)
	{
		cout << "| " << setw(3) << setfill('0') << accounts[i].retAccNum() / 1000000 << " "
			 << setw(3) << setfill('0') << (accounts[i].retAccNum() / 1000) % 1000 << " "
			 << setw(3) << setfill('0') << accounts[i].retAccNum() % 1000
			 << "    | " << accounts[i].getName()
			 << "\t| " << accounts[i].rettype()
			 << "\t| " << accounts[i].retdeposit()
			 << "\t   | " << endl;
	}

	cout << "====================================================\n";
	cout << "    Press any key to return to the main menu...";
	cin.ignore();
	cin.get();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************