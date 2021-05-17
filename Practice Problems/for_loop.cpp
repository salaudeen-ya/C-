#include <iostream>
using namespace std;

int main(){

// int a, b;
// cin >> a >> b;
// for (a; a < b+1; a++){
//     if (a%2 == 0) {
//         cout <<"even" << endl;}
//     else {cout << "odd" << endl;}

// }

int a = 2, b = 5;
cin >> a >> b;
for (a; a < b+1; a++){
    if (a%2 == 0) {
        if (a == 2){
            cout << "two" << endl;
            cout <<"even" << endl;
        }
        else {
            cout << "four" << endl;
            cout <<"even" << endl;
            }
        }      
    else {
        if (a == 3){
            cout << "three" << endl;
            cout <<"odd" << endl;
        }
        else {
            cout << "five" << endl;
            cout << "odd" << endl;
            }
        }
    }

    return 0;
}

