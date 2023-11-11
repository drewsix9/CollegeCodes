#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount()
    {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cin.ignore();
        cout << "Enter account holder name: ";
        getline(cin, accountHolderName);
        cout << "Enter initial balance: ";
        cin >> balance;
    }

    void deposit()
    {
        double temp;
        cout << "Enter amount to deposit: ";
        cin >> temp;
        if (temp >= 100000)
        {
            cout << "\nYou have entered exceeding amount of maximum deposition\nPlease try again." << endl;
        }
        else
        {
            balance += temp;
            getBalance();
        }
    }

    void withdraw()
    {
        double temp;
        cout << "Enter amount to withdraw: ";
        cin >> temp;
        if (temp > balance || temp >= 10000)
        {
            cout << "\nYou have entered exceeding amount of your balance.\nNote: 10,000 is the maximum withdrawal amount.\nPlease try again." << endl;
        }
        else
        {
            balance -= temp;
            getBalance();
        }
    }

    void getBalance()
    {
        x` cout << "Balance: " << balance << endl;
    }

    void display()
    {
        cout << "\nAccount number: " << accountNumber << endl;
        cout << "Account holder name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account1;

    while (1)
    {
        int choice;
        cout << "\n[1] Withdraw Cash" << endl;
        cout << "[2] Deposit Cash" << endl;
        cout << "[3] Display" << endl;
        cout << "[4] Exit" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            account1.withdraw();
            break;
        case 2:
            account1.deposit();
            break;
        case 3:
            account1.display();
            break;
        case 4:
            return 0;

        default:
            cout << "\nError! Please try again\n";
            break;
        }
    }

    return 0;
}