
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// ================= Base Class =================
class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal = 0.0)
        : accountNumber(accNo), accountHolderName(name), balance(bal) {}

    virtual ~BankAccount() {}

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited " << amount << " successfully.\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn " << amount << " successfully.\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    double getBalance() const { return balance; }

    virtual void displayAccountInfo() const {
        cout << "Account Number: " << accountNumber
             << "\nHolder Name: " << accountHolderName
             << "\nBalance: " << balance << "\n";
    }

    virtual void calculateInterest() {} // polymorphic function
};

// ================= Derived Class: Savings =================
class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * interestRate / 100;
        cout << "Interest earned: " << interest << "\n";
    }
};

// ================= Derived Class: Checking =================
class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn " << amount << " successfully (Overdraft considered).\n";
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }

    void calculateInterest() override {
        cout << "No interest on Checking Account.\n";
    }
};

// ================= Derived Class: Fixed Deposit =================
class FixedDepositAccount : public BankAccount {
    int term; // in months
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal), term(t), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * interestRate * term / (12 * 100);
        cout << "Fixed Deposit Interest for " << term << " months: " << interest << "\n";
    }
};

// ================= Main Banking System =================
int main() {
    vector<shared_ptr<BankAccount>> accounts;
    int choice;

    do {
        cout << "\n===== Banking System Menu =====\n";
        cout << "1. Create Savings Account\n";
        cout << "2. Create Checking Account\n";
        cout << "3. Create Fixed Deposit Account\n";
        cout << "4. Deposit Money\n";
        cout << "5. Withdraw Money\n";
        cout << "6. Display All Accounts\n";
        cout << "7. Calculate Interest\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        if (choice == 1) {
            int accNo; string name; double bal, rate;
            cout << "Enter Account No: "; cin >> accNo;
            cin.ignore();
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Balance: "; cin >> bal;
            cout << "Enter Interest Rate: "; cin >> rate;
            accounts.push_back(make_shared<SavingsAccount>(accNo, name, bal, rate));
        }
        else if (choice == 2) {
            int accNo; string name; double bal, limit;
            cout << "Enter Account No: "; cin >> accNo;
            cin.ignore();
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Balance: "; cin >> bal;
            cout << "Enter Overdraft Limit: "; cin >> limit;
            accounts.push_back(make_shared<CheckingAccount>(accNo, name, bal, limit));
        }
        else if (choice == 3) {
            int accNo, term; string name; double bal, rate;
            cout << "Enter Account No: "; cin >> accNo;
            cin.ignore();
            cout << "Enter Name: "; getline(cin, name);
            cout << "Enter Balance: "; cin >> bal;
            cout << "Enter Term (months): "; cin >> term;
            cout << "Enter Interest Rate: "; cin >> rate;
            accounts.push_back(make_shared<FixedDepositAccount>(accNo, name, bal, term, rate));
        }
        else if (choice == 4) {
            int idx; double amt;
            cout << "Enter Account Index and Amount: ";
            cin >> idx >> amt;
            if (idx >= 0 && idx < (int)accounts.size()) accounts[idx]->deposit(amt);
            else cout << "Invalid Account Index!\n";
        }
        else if (choice == 5) {
            int idx; double amt;
            cout << "Enter Account Index and Amount: ";
            cin >> idx >> amt;
            if (idx >= 0 && idx < (int)accounts.size()) accounts[idx]->withdraw(amt);
            else cout << "Invalid Account Index!\n";
        }
        else if (choice == 6) {
            for (int i = 0; i < (int)accounts.size(); i++) {
                cout << "\n--- Account " << i << " ---\n";
                accounts[i]->displayAccountInfo();
            }
        }
        else if (choice == 7) {
            int idx;
            cout << "Enter Account Index: ";
            cin >> idx;
            if (idx >= 0 && idx < (int)accounts.size()) accounts[idx]->calculateInterest();
            else cout << "Invalid Account Index!\n";
        }

    } while (choice != 8);

    cout << "Exiting Banking System...\n";
    return 0;
}

