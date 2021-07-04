#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iterator>

using namespace std;

double const minimum_bal = 500.0;
class InsufficientFunds{};

class Account {
    private:
        double bal_;
        long actNum_;
        string firstName_;
        string lastName_;
        static long nextActNum_;
    public:
        // Constructors
        Account() {};
        Account(string firstName, string lastName, double bal);
        
        // Accesors 
        double bal();
        long actNum();
        string firstName();
        string lastName();
        
        void deposit(double amount);
        void withdraw(double amount);
        static void lastActNum(long actNum);
        static long lastActNum();

        // Operator overloading
        friend ofstream &operator << (ofstream &ofs, Account &acccount);
        friend ifstream &operator >> (ifstream &ifs, Account &account);
        friend ostream &operator << (ostream &os, Account &account);
};

class Bank{
    private:
        map<long, Account> accounts;
    public:
        //Constructors
        Bank();
        // Methods
        Account openAct(string firstName, string lastName, double bal);
        Account balanceEnquiry(long actNum);
        Account deposit(long actNum, double amount);
        Account withdraw(long actNum, double amount);
        void closeAccount(long actNum);
        void showAllAccounts();
        ~Bank();  
};
