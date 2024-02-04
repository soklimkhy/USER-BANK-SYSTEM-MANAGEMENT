#pragma once
#include <iostream>
#include "BadInputException.cpp"

using namespace std;

class DataInputValidation
{
private:
    bool validate_num(int num)
    {
        if (cin.fail() || num > 1000)
        {
            return false;
        }
        return true;
    }

    bool validate_doublenum(double num)
    {
        if (cin.fail() || num > 1000)
        {
            return false;
        }
        return true;
    }

    bool validate_name(string name)
    {
        if (name.length() > 10)
        {
            return false;
        }

        for (int i = 0; i < name.length(); i++)
        {
            if (!(name[i] >= 65 && name[i] <= 122))
            {
                return false;
            }
        } //100 000 988
        return true;
    }

public:
    int input_Accountnum()
    {
        int num;
        cout << "Enter account number: ";
        cin >> num;
        if (!validate_num(num))
        {
            throw BadInputException();
        }
        return num;
    }

    double input_balance()
    {
        double balance;
        while (true)
        {
            cout << "Enter balance: ";
            cin >> balance;
            if (!validate_doublenum(balance))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid Input" << endl;
            }
            else
            {
                return balance;
            }
        }
    }

    string input_name()
    {
        string name;
        while (true)
        {
            cout << "Enter name: ";
            cin >> name;
            if (!validate_name(name))
            {
                cout << "Error: Invalid/max letter reached" << endl;
            }
            else
            {
                return name;
            }
        }
    }
};
