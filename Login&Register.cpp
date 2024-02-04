#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

class Login
{
private:
    string username;
    string password;
    string fourDigitsPIN;

public:
    bool userLogin()
    {
        cout << " X=======================================X" << endl;
        cout << "\n\n" ;
        cout << " X=======================================X" << endl;
        cout << " |               1. LOGIN                |" << endl;
        cout << " X=======================================X" << endl;
        cout << "       Enter the username: ";
        cin >> username;
        cout << "       Enter the password: ";
        cin >> password;
        cout << "       Enter the 4-digit PIN: "; // Prompt for the PIN
        cin >> fourDigitsPIN;
        cout << " X=======================================X" << endl;

        bool userFound = false;
        string fileUsername, filePassword, filePin;
        ifstream fin("users.dat", ios::in);

        if (!fin.is_open())
        {
            cerr << " |           CANNOT OPEN FILE            |" << endl; 
            cout << " X=======================================X" << endl;
            return false;
        }

        while (fin >> fileUsername >> filePassword >> filePin)
        {
            if (fileUsername == username && filePassword == password && filePin == fourDigitsPIN)
            {
                cout << "   WELCOME TO BANK MANAGEMENT" 
                     << " " << username << endl;
                userFound = true;
                 break;
            }
        }

        fin.close();

        if (!userFound)
        {
            cout << " |             USER NOT FOUND            | " << endl; 
            cout << " X=======================================X " << endl;
            
        }

        return userFound;
    }

    void userRegister()
    {   
        cout << " X=======================================X " << endl;
        cout << "\n\n" ;
        cout << " X=======================================X " << endl;
        cout << " |             2. REGISTER               | " << endl;
        cout << " X=======================================X " << endl;
        cout << "       Enter the username: ";
        cin >> username;
        cout << "       Enter the password: ";
        cin >> password;
        cout << "       Enter the 4-digit PIN: "; 
        cin >> fourDigitsPIN;
        cout << " X=======================================X" << endl;
        if (username.length() <= 7 || password.length() <= 7 || fourDigitsPIN.length() != 4)
        {   
            cout << " |  4-digit PIN MUST BE 4 CHARACTERS OR  | " << endl; 
            cout << " | USERNAME AND PASSWORD MUST BE AT LEAST| " << endl; 
            cout << " | 7 CHARACTERS LONG. PLEASE TRY AGAIN.. | " << endl; 
            cout << " X=======================================X\n\n " << endl;
            return;
        }

        ofstream fout("users.dat", ios::out | ios::app);

        if (!fout.is_open())
        {
            cerr << " |           CANNOT OPEN FILE            | " << endl; 
            cout << " X=======================================X " << endl;
            return;
        }

        fout << username << " " << password << " " << fourDigitsPIN << endl;
        fout.close();

        cout << " |            USER HAS CREATED           | " << endl; //USER CREATED
        cout << " X=======================================X " << endl << endl;
    }
};
