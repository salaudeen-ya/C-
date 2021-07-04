#include "banking.h"

// Account class implementation

long Account::nextActNum_ = 0;
Account::Account(string firstName, string lastName, double bal){
    firstName_ = firstName;
    lastName_ = lastName;
    bal_ = bal;
    nextActNum_++;
    actNum_ = nextActNum_;
}
        
// accesors 
double Account::bal() { return bal_; }
long Account::actNum() { return actNum_; }
string Account::firstName() { return firstName_; }
string Account::lastName() { return lastName_; }
        
// manipulators 
void Account::deposit(double amount){ bal_ += amount; }
void Account::withdraw(double amount){ 
    if (bal_ - amount < minimum_bal) {
        throw InsufficientFunds();
    } 
    bal_-=amount;
}
void Account::lastActNum(long actNum){ nextActNum_ = actNum; }
long Account::lastActNum(){ return nextActNum_; }

ofstream &operator << (ofstream &ofs, Account &account){
    ofs <<account.actNum_ << endl;
    ofs << account.firstName_ << endl;
    ofs << account.lastName_ << endl;
    ofs << account.bal_ << endl;
    return ofs;
}
ifstream &operator >> (ifstream &ifs, Account &account){
    ifs >> account.actNum_;
    ifs >> account.firstName_;
    ifs >> account.lastName_;
    ifs >> account.bal_;
    return ifs;
}
ostream &operator << (ostream &os, Account &account){
    os << "First Name: " << account.firstName() << endl;
    os << "Last Name: " << account.lastName() << endl;
    os << "Account Number: " << account.actNum() << endl;
    os << "Balance: " << account.bal() << endl;
    return os;
}

// Bank class implementation

Bank::Bank(){
    Account account;
    ifstream infile;
    infile.open("Bank.data");
    if(!infile){
        //cout << "Error in opening, file not found!\n";
        return;
    } 
    while(!infile.eof()){
        infile >> account;
        pair<long, Account> entry;
        entry = make_pair(account.actNum(), account);
        accounts.insert(entry);
        
        // == accounts.insert(pair<long, Account>(account.actNum(), account));
    }
    Account::lastActNum(account.actNum());
    infile.close();
}

Account Bank::openAct(string firstName, string lastName, double bal){
    ofstream outfile;
    Account account(firstName, lastName, bal);
    accounts.insert(pair<long, Account>(account.actNum(), account));
    
    outfile.open("Bank.data", ios::trunc);

    map<long, Account>::iterator itr;
    for(itr = accounts.begin(); itr != accounts.end(); itr++){
        outfile << itr->second;
    }
    outfile.close();
    return account;
}

Account Bank::balanceEnquiry(long actNum){
    map<long, Account>::iterator itr;
    itr = accounts.find(actNum);
    return itr->second;
}
Account Bank::deposit(long actNum, double amount){
    map<long, Account>::iterator itr;
    itr = accounts.find(actNum);
    itr->second.deposit(amount);
    return itr->second;
}
Account Bank::withdraw(long actNum, double amount){
    map<long, Account>::iterator itr;
    itr = accounts.find(actNum);
    itr->second.withdraw(amount);
    return itr->second;
}
void Bank::closeAccount(long actNum){
    map<long, Account>::iterator itr;
    itr = accounts.find(actNum);
    cout << "Account deleted.\n";
    accounts.erase(actNum);
}
void Bank::showAllAccounts(){
    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++){
        cout << "Account " << itr->first << endl << itr->second << endl;
    }
}
Bank::~Bank(){
    ofstream outfile;
    outfile.open("Bank.data", ios::trunc);

    map<long, Account>::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++){
        outfile << itr->second;
    }
    outfile.close();
}  