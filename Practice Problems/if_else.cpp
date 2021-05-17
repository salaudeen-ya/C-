#include <iostream>
using namespace std;

int main(){
    int x;
    cin >> x;

    if (x==5){cout << "five";}
    else if (x==8) {cout << "eight";}
    else {cout << "Greater than 9";}

    // inputting other values apart from 5 and 8 executes the else statement.

    return 0;
}