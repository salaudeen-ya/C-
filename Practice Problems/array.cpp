#include <iostream>
using namespace std;

int main(){

    int n, arr[n];

    cout << "Enter the number of integers " << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Reversed array" << endl;
    for (int i = n; i > 0; i--){
        cout << arr[i];
    }

    return 0;
}