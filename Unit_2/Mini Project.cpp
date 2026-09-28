#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    string holderName;
    double balance;

public:
    Account(string number, string name, double amount)
        : accountNumber(number), holderName(name), balance(amount) {}

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    virtual double calculateInterest() const = 0;

    virtual void display() const {
        cout << "Account Number: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: Rs. " << balance << endl;
    }

    virtual ~Account() = default;
};

class SavingsAccount : public Account {
public:
    SavingsAccount(string number, string name, double amount)
        : Account(number, name, amount) {}

    double calculateInterest() const override {
        return balance * 0.04;
    }

    void display() const override {
        cout << "Savings Account | ";
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(string number, string name, double amount)
        : Account(number, name, amount) {}

    double calculateInterest() const override {
        return 0.0;
    }

    void display() const override {
        cout << "Current Account | ";
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

class FixedDepositAccount : public Account {
public:
    FixedDepositAccount(string number, string name, double amount)
        : Account(number, name, amount) {}

    double calculateInterest() const override {
        return balance * 0.07;
    }

    void display() const override {
        cout << "Fixed Deposit Account | ";
        Account::display();
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

int main() {
    SavingsAccount savings("SA101", "Rahul", 50000);
    CurrentAccount current("CA102", "Priya", 75000);
    FixedDepositAccount fixedDeposit("FD103", "Amit", 100000);

    cout << "=== Banking System ===" << endl;

    savings.deposit(5000);
    savings.withdraw(3000);

    current.deposit(10000);
    current.withdraw(5000);

    fixedDeposit.deposit(20000);

    cout << endl;

    savings.display();
    current.display();
    fixedDeposit.display();

    return 0;
}
