#include <iostream>
#include <Windows.h>

using namespace std;

void landingPage(){

    system("cls");
    system("color 9F");

    char a = 177, b = 219;
    cout << "\n\n\n\n\n\t\tStudent's Data Management System";
    cout << "\n\n\n\t\tLoading...\n" << endl;
    cout << "\t\t";

    for (int i = 0; i < 26; i++)
    cout << a;

    cout << "\r";
    cout << "\t\t";
    for (int i = 0; i < 26; i++){
        cout << b;
        Sleep(100);
    }

}