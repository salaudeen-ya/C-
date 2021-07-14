
#include "admin.cpp"

// Authentication
void passwordVerification();

int main(){

    // Fast I/O, same speed as scanf/printf for competitive programming
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    landingPage();
    system("color 9F");
    passwordVerification();
      
    return 0;
}


// Authentication implementation

void passwordVerification(){
    system ("cls");
    string password;
    cout << "\n\n\n\t\t\t\t\t";
    cout << "\n\n\n\t\tEnter Password: ";
    
    cin >> password;
    
    if (password == "password") { mainMenu(); }
    else {
            do{
                cout << "\n\n\n\t\t"
                << "Wrong password!, Try again or type 'quit'/'exit' to close the program.";
                cout << "\n\n\n\t\tEnter Password: ";
                cin >> password;
                for (auto &c : password){ c = toupper(c);}
                if (password == "QUIT" || password == "EXIT"){ close(); } 
            } while (password != "password");
            mainMenu();
    }
}



