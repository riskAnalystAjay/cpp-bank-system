#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    Account(int accNo, string accName, double initialBalance)
    {
        accountNumber = accNo;
        name = accName;
        balance = initialBalance;
    }

    int getAccountNumber() { return accountNumber; }
    string getName() { return name; }
    double getBalance() { return balance; }

    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited " << amount << ". New Balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds!" << endl;
        } else
        {
            balance -= amount;
            cout << "Withdrew " << amount << ". New Balance: " << balance << endl;
        }
    }

    void display() {
        cout << "Account No: " << accountNumber 
             << " | Name: " << name 
             << " | Balance: " << balance << endl;
    }
};

class Bank {
private:
    vector<Account> accounts;

public:
    void createAccount() {
        int accNo;
        string name;
        double initialBalance;
        cout << "Enter Account Number: ";
        cin >> accNo;
        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Initial Balance: ";
        cin >> initialBalance;

        accounts.push_back(Account(accNo, name, initialBalance));
        cout << "Account Created Successfully!" << endl;
    }

    Account* findAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                return &acc;
            }
        }
        return nullptr;
    }

    void depositMoney() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (acc != nullptr) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            acc->deposit(amount);
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void withdrawMoney() {
        int accNo;
        double amount;
        cout << "Enter Account Number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (acc != nullptr) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            acc->withdraw(amount);
        } else 
        {
            cout << "Account not found!" << endl;
        }
        
    }

    void checkBalance() {
        int accNo;
        cout << "Enter Account Number: ";
        cin >> accNo;
        Account* acc = findAccount(accNo);
        if (acc != nullptr) {
            cout << "Account Balance: " << acc->getBalance() << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    void displayAllAccounts() {
        cout << "\n--- All Accounts ---\n";
        for (auto &acc : accounts) {
            acc.display();
        }
    }
};

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Display All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: bank.createAccount(); break;
            case 2: bank.depositMoney(); break;
            case 3: bank.withdrawMoney(); break;
            case 4: bank.checkBalance(); break;
            case 5: bank.displayAllAccounts(); break;
            case 6: cout << "Exiting program..." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);

    return 0;
}