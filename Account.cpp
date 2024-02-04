//***************************************************************
//                   HEADER FILE USED IN PROJECT
//****************************************************************

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()
//#include "AccountFeatures.cpp"

using namespace std;

//***************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************

class account
{

	char name[50];
	int deposit;
	char type;
	long AccNum; // Changed to long for 9-digit account number
public:
	void create_account();	   // function to get data from user
	void show_account() const; // function to show data on screen
	void rename();			   // function to add new data
	void depositC(int);		   // function to accept amount and add to balance amount
	void withdraw(int);		   // function to accept amount and subtract from balance amount
	void report() const;	   // function to show data in tabular format
	int retAccNum() const;	   // function to return account number
	int retdeposit() const;	   // function to return balance amount
	char rettype() const;	   // function to return type of account
	const char* getName() const {
        return name;
    }
};							   // class ends here

void account::create_account()
{
	// Generating a random 9-digit account number
	srand(time(0));
	AccNum = rand() % 900000000 + 100000000;
	cout << "\n\n\n"; 
	cout << " X=======================================X " << endl;
	cout << " |        1. CREATE NEW ACCOUNT          | " << endl;
    cout << " X=======================================X " << endl;
	cout << "     Enter account name : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << "     Enter Type of The account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "     Enter Balance: ";
	cin >> deposit;
	cout << " X=======================================X " << endl;
	cout << " |    Account Created Successfully..     | " << endl;
	cout << " X=======================================X " << endl <<endl << endl;
}

void account::show_account() const
{   
	cout << " X=======================================X " << endl;
	cout << " | Account Number : " << setw(3) << setfill('0') << AccNum / 1000000 << " "
		 << setw(3) << setfill('0') << (AccNum / 1000) % 1000 << " "
		 << setw(3) << setfill('0') << AccNum % 1000 <<endl; 
	cout << " | Account name : " << name << endl ;
	cout << " | Type of Account : " << type <<endl ;
	cout << " | Balance : " << deposit <<endl  ;
	cout << " X=======================================X " << endl;
}

void account::rename()
{   cout << " X=======================================X " << endl;
	cout << " | Account Number : " << AccNum <<endl;
	cout << " | Renew account name : ";
	cin.ignore();
	cin.getline(name, 50);
	cout << " | Renew type of account : ";
	cin >> type;
	type = toupper(type);
	cout << " | Renew balance : ";
	cin >> deposit;
}

void account::depositC(int x)
{
	deposit += x;
}

void account::withdraw(int x)
{
	deposit -= x;
}

void account::report() const
{
	
	cout << "| ";
	cout << setw(3) << setfill('0') << AccNum / 1000000 << " "
		 << setw(3) << setfill('0') << (AccNum / 1000) % 1000 << " "
		 << setw(3) << setfill('0') << AccNum % 1000;
	cout << "    | " << name << "\t| " << type << "\t| " << deposit << "\t   | " << endl;
}

int account::retAccNum() const
{
	return AccNum;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}