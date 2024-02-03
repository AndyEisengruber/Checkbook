

#include <iostream>
using namespace std;

class Check {
public:
    //our getters
    int getCheckNum() const { return CheckNum; }
    string getCheckMemo() const { return CheckMemo; }
    float getCheckAmount() const { return CheckAmount; }
    //our setters
    void setCheckMemo(const string memo) {CheckMemo = memo; }
    void setCheckAmount(float amount) {CheckAmount = amount; }

    //static member function to get teh total number of checks
    static int getAllChecks() { return number;}
    // Default constructor
    Check() : CheckNum(++number), CheckMemo(""), CheckAmount(0) {}
    Check(string memo, float amount) : CheckNum(++number), CheckMemo(memo), CheckAmount(amount) {
        cout << "Creating Check: " << CheckNum << " Memo: " << CheckMemo << " Amount: " << CheckAmount << endl;
    }




private:
    int CheckNum;
    string CheckMemo;
    float CheckAmount;
    static int number; //static member to keep track of the number of checks
};

int Check::number = 0;

class CheckBook {
public:
    //our default constructor
    CheckBook() : balance(0), lastDeposit(0), numOfChecks(0) {}
    //constructor with initial balance
    CheckBook(float intialBalance) : balance(intialBalance), lastDeposit(0), numOfChecks(0) {}

    //deposite money function
    void deposit(float amount) {
        balance += amount;
        lastDeposit = amount;
    }

    //our display function
    void displayChecks() const {
        for (int i = numOfChecks - 1; i >= 0; --i) {
            cout << "Check: " << i << " "
                << " Amount: $" << checks[i].getCheckAmount()
                << " Memo: " << checks[i].getCheckMemo() << endl;
        }
    }

    //Function to write checks
    bool writeCheck(float amount) {
        if (amount <= balance && numOfChecks < checkLimit && Check::getAllChecks() < 10) {
            //ask for details
            cout << "Please enter the details for the check: " << endl;
            string memo;
            cout << "Memo: ";
            cin >> memo;

            checks[numOfChecks].setCheckMemo(memo);
            checks[numOfChecks].setCheckAmount(amount);
            balance -= amount;;
            numOfChecks++;
            Check::number++;
            numOfChecks++;
            return true;
        }
        else {
            return false;
        }
    }

    static int getAllChecks() {
        return Check::getAllChecks();
    }

private:
    float balance;
    static const int N = 5;
    float lastDeposit;
    int numOfChecks;
    static int checkLimit;
    Check checks[N];
};

int CheckBook::checkLimit = 5;



int main()
{
    CheckBook cb1(1000), cb2(500);
    for (int i = 0; i < 10; i++)
    {
        cb1.writeCheck(150);
        cb2.writeCheck(130);
    }
    cout << "cb1 check details" << endl;
    cb1.displayChecks();
    cout << "cb2 check details" << endl;
    cb2.displayChecks();
    cout << cb1.getAllChecks() << endl;
    cout << cb2.getAllChecks() << endl;


    return 0;
}


