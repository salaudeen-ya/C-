#include "admin.h"

// ***********************************
// |*           Main Menu           *|
// ***********************************

void mainMenu(){
    system("cls");
    cout << "\n\n\t\t\t Login As:";
    cout << "\n\n\t\t 1. Admin";
    cout << "\n\n\t\t 2. Student";
    cout << "\n\n\t\t 3. Exit";
    cout << "\n\n\t\tEnter your number choice: ";

    int choice;
    cin >> choice;
    switch (choice) {
        case 1: 
            adminVerification();
            break;
        case 2:    
            system("cls");
            cout << "| Logged In as Student |";
            studentRecord();
            break;
        case 3:
            close();
            break;
        default:
            cout << "\n\n\t\t Invalid Input!";
    }
    system("pause");  
}

// ***********************************
// |*         Admin Panel           *|
// ***********************************
void admin(){
    system("cls");
    cout << "\n\n\t\t\t | Logged In as Admin | \n";
    cout << "\n\n\t\t 1. Add Students' Detail";
    cout << "\n\n\t\t 2. Delete Students' Details";
    cout << "\n\n\t\t 3. Update Record";
    cout << "\n\n\t\t 4. View Table";
    cout << "\n\n\t\t 5. Main Menu";
    cout << "\n\n\t\t 6. Exit";

    int choice;
    cout << "\n\n\t\tEnter your choice: ";
    do {
        cin >> choice;
        {
            switch (choice){
                case 1: addData();
                    break;
                case 2: deleteData();
                    break;
                case 3: // updateData();
                    cout << "This option is not available";
                    break;
                case 4: viewData();
                    break;
                case 5: mainMenu();
                    break;
                case 6:
                    close();
                    break;
                default:
                    system("cls");
                    cout << "\n\n\t\t\t | Logged In as Admin | \n";
                    cout << "\n\n\t\t 1. Add Students' Detail";
                    cout << "\n\n\t\t 2. Delete Students' Details";
                    cout << "\n\n\t\t 3. Update Record";
                    cout << "\n\n\t\t 4. View Table";
                    cout << "\n\n\t\t 5. Main Menu";
                    cout << "\n\n\t\t 6. Exit";

                    cout << "\n\n\t\t Invalid Input!";
                    cout << "\n\n\t\t Enter your choice: ";

            }
        }
    } while (choice != '6');
}

// ***********************************
// |*      Admin Functions          *|
// ***********************************

void adminVerification(){
    system ("cls");
    string password;
    cout << "\n\n\n";
    cout << "\n\n\n\t\tEnter Password: ";

    cin >> password;
    
    if (password == "password") { admin(); }
    else {
            do{
                cout << "\n\n\n\t\t"
                << "Wrong password!, Try again or type 'Menu' to navigate to Main Menu.";
                cout << "\n\n\n\t\tEnter Password: ";
                cin >> password;
                for (auto &c : password){ c = toupper(c);}
                if (password == "MENU"){ mainMenu(); } 
            } while (password != "password");
            admin();
    }
}

void addData(){
    system("cls");
    fstream file("data.csv", ios::out | ios::app);  // output and append to the end of the file
    if (!file){ cout << "\nFailed to open data.csv or file not found!"; }
    else { cout << "\n| Enter Student's Data |\n\n"; }
    
    string matricNum, fname, lname, school, branch, attendance;
    string physics, chemistry, maths;
    string others;

    cout << "\nMatriculation number: ";
    cin >> matricNum;
    file << matricNum << ", ";
  
    cout << "\nFirst Name: ";
    cin >> fname;
    file << fname << ", ";
   
    cout << "\nLast Name: ";
    cin >> lname;
    file << lname << ", ";
   
    cout << "\nSchool: ";
    cin >> school;
    file << school << ", ";

    cout << "\nBranch: ";
    cin >> branch;
    file << branch << ", ";

    cout << "\nAttendance: "; 
    cin >> attendance;
    file << attendance << ", ";
    
    cout << "\nPhysics score: ";
    cin >> physics;
    file << physics << ", ";

    cout << "\nChemistry score: ";
    cin >> chemistry;
    file << chemistry << ", ";

    cout << "\nMaths score: ";
    cin >> maths;
    file << maths << "\n";
    
    file.close();

    cout << "\nAdd more Record? (Y / N): ";
    cin >> others;
    if (others == "y" || others == "Y" || others == "yes" || others == "Yes"){
        addData();
    } else if (others == "n" || others == "N" || others == "no" || others == "No"){
        admin();
    } else {
        cout << "\nEnter a valid option";
        admin();   ////////////?????????
    }
}

void viewData(){
    system("cls");
    
    fstream file("data.csv");

    if (!file) { cout << "Failed to open file or file not found\n\n"; }
    else{
        cout << "\n\t\t|Students Record|\n\n";
        cout << "\n-----------------------------------------------------------------------------"
             << "-------------------------------------------------------------------------------\n\n";
        cout << "MatricNum \t First Name \t\t Last Name \t\t School \t\t Branch \t\t Attendance \t Physics \t Chemistry \t Mathematics \n";

        string matricNum, fname, lname, school, branch, attendance, physics, chemistry, maths;

        while (!file.eof()){
            getline(file, matricNum, ',');
            getline(file, fname, ',');
            getline(file, lname, ',');
            getline(file, school, ',');
            getline(file, branch, ',');
            getline(file, attendance, ',');
            getline(file, physics, ',');
            getline(file, chemistry, ',');
            getline(file, maths, '\n');

            cout << matricNum << "\t" << fname << "\t\t" << lname << "\t\t" << school << "\t\t" << branch << "\t\t\t" << attendance 
                << "\t\t" << physics << "\t\t" << chemistry << "\t\t" << maths << "\n";
        }

         cout << "\n-----------------------------------------------------------------------------"
             << "-------------------------------------------------------------------------------\n\n";
        file.close();
    }
    
    system("pause");
    
    //  cout << "\n"
    //       << "\n 1. Add Record"
    //       << "\n 2. Delete Record"
    //       << "\n 3. Update Record"
    //       << "\n 5. Main Menu"
    //       << "\n 6. Exit"
    //       << "\n\nEnter choice: ";

    admin();
}

void deleteData(){
    system("cls");

    // Open file pointers
    fstream fin, fout;

    // Open the exsiting file
    fin.open("data.csv", ios::out);

    // Create a new file to store the non-deleted data
    fout.open("datanew.csv", ios::out);

    int matricNum, matric1, marks, count = 0;
    char sub;
    int index, new_marks;
    string line, word;
    vector<string> row;

    // Deleting the details corresponding to a matric number
    cout << "Enter the matric number of the record to be deleted: ";
    cin >> matricNum;

    // Check if this record exists.
    // If yes, move all other data to the new file.
    while (!fin.eof()){
        row.clear();
        getline(fin, line);     // stores each row from file fin into line
        stringstream ss(line);
        while (getline(ss, word, ',')){
            row.push_back(word);
        }
        int row_size = row.size();
        matric1 = stoi(row[0]);

        // Writing all records except the record to be deleted into the new file 'reportcardnew.csv'
        // using fout pointer.

        if (matric1 != matricNum){
            if (!fin.eof()){
                for (int i = 0; i < row_size - 1; i++){
                    fout << row[i] << ",";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else { count = 1; }
        if (fin.eof()) { break; }
    }
    if (count == 1) { cout << "Record deleted\n"; }
    else { cout << "Record not found\n"; }

    // Close the file pointers
    fin.close();
    fout.close();

    // Remove the initial file
    remove("data.csv");

    // Renaming the new file with the existing file name
    rename("datanew.csv", "data.csv");

    Sleep(2000); 
    admin();
}

void studentRecord(){
    system("cls");
    
    fstream file("data.csv");

    if (!file) { cout << "Failed to open file or file not found\n\n"; }
    else{
        cout << "\n\t\t|Students Record|\n\n";
        cout << "\n-----------------------------------------------------------------------------"
             << "-------------------------------------------------------------------------------\n\n";
        cout << "MatricNum \t First Name \t\t Last Name \t\t School \t\t Branch \t\t Attendance \t Physics \t Chemistry \t Mathematics \n";

        string matricNum, fname, lname, school, branch, attendance, physics, chemistry, maths;

        while (!file.eof()){
            getline(file, matricNum, ',');
            getline(file, fname, ',');
            getline(file, lname, ',');
            getline(file, school, ',');
            getline(file, branch, ',');
            getline(file, attendance, ',');
            getline(file, physics, ',');
            getline(file, chemistry, ',');
            getline(file, maths, '\n');

            cout << matricNum << "\t" << fname << "\t\t" << lname << "\t\t" << school << "\t\t" << branch << "\t\t\t" << attendance 
                << "\t\t" << physics << "\t\t" << chemistry << "\t\t" << maths << "\n";
        }

        cout << "\n-----------------------------------------------------------------------------"
             << "-------------------------------------------------------------------------------\n\n";
        file.close();
    }
    
    system("pause");
    mainMenu();
}

void close(){
    system("cls");
    cout << "\t\t\n\n\n\t\tClosing the program";
    for (int i = 0; i < 4; i++){
        Sleep(1000);
        cout << ".";
    }
    exit(0);
}