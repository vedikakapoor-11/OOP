#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    double balance;
    string accountNumber;

protected:
    // Protected function can be accessed by child classes
    void showAccountType()
    {
        cout << "Account Type: Bank Account" << endl;
    }

public:
    // Constructor
    BankAccount(string accNo, double bal)
    {
        accountNumber = accNo;
        balance = bal;
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Deposited: Rs. " << amount << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Withdraw money
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Withdrawn: Rs. " << amount << endl;
        }
        else
        {
            cout << "Invalid withdrawal / Insufficient balance!" << endl;
        }
    }

    // Display account details
    void display()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: Rs. " << balance << endl;
    }
};


// Child class to demonstrate protected access
class SavingsAccount : public BankAccount
{
public:
    SavingsAccount(string accNo, double bal)
        : BankAccount(accNo, bal)
    {
    }

    void displayType()
    {
        showAccountType();   // Protected member can be accessed here
    }
};


int main()
{
    // Creating object using constructor
    SavingsAccount account("12345", 10000);

    cout << "----- Account Details -----" << endl;
    account.display();

    cout << "\n----- Transactions -----" << endl;

    account.deposit(5000);

    account.withdraw(2000);

    // Trying to withdraw more than balance
    account.withdraw(20000);

    cout << "\n----- Final Details -----" << endl;
    account.display();

    cout << "\n----- Protected Access -----" << endl;
    account.displayType();

    return 0;
}