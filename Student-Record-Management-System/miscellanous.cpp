
/**************************************************

    do {
        cin >> password;

        if (password != "password"){
            cout << "\n\n\n\t\t"
             << "Wrong password!, Try again or type 'quit'/'exit' to close the program.";
            cout << "\n\n\n\t\tEnter Password: ";
        }
    
                                        // *** Using STL algorithm with lambda 
                                        //     for_each(password.begin(), password.end(), [] (char &c){
                                        //         c = ::toupper(c);
                                        //     });
                                            
                                        //     // *** Using Stringstream
                                        //     // stringstream ss;
                                        //     // ss << password;
                                        //     // string pass = password.c_str();

        // Convert the quit/exit option to Upper case using range based for loop with STL algorithm
        for (auto &c : password){ c = toupper(c);}

        if (password == "QUIT" || password == "EXIT"){ close(); }

    mainMenu(); 

    } while (password != "password");

    //mainMenu(); 
   
}
 

*****************************************************/


/*
void updateData(){
    system("cls");
    cout << "Trying to update file\n";

    // File pointer
    fstream fin, fout;

    // Open an existing record
    fin.open("data.csv", ios::in);

    // Create a new file to store updated data
    fout.open("datanew.csv", ios::out);

    int matricNum, matricNum1, marks, count = 0;
    char sub;
    int index;
    string new_marks, line, word;
    vector<string> row;

    // Get the matric number from the user
    cout << "Enter the matric number of the record to be updated: ";
    cin >> matricNum;

    // Get the data to be updated
    cout << "Enter the first letter of the field to be updated (e.g, n for name) as follows"
         << "(N/G/B/A/P/C/M): ";
    cin >> sub;

    // Determine the index of the subject
    // name has index 7, Chemistry has 5 etc

    if (sub == 'n' || sub == 'N') index = 1;
    else if (sub == 'g' || sub == 'G') index = 2;
    else if (sub == 'b' || sub == 'B') index = 3;
    else if (sub == 'a' || sub == 'A') index = 4;
    else if (sub == 'p' || sub == 'P') index = 5;
    else if (sub == 'c' || sub == 'C') index = 6;
    else if (sub == 'm' || sub == 'M') index = 7;
    else{
        cout << "Invalid choice, try again.\n";
        updateData();
    }

    // Get the new marks
    cout << "Enter new detail: ";
    cin >> new_marks;

    // Traverse the file
    while(!fin.eof()){
        row.clear();
        getline(fin, line);
        stringstream ss(line);
        
        while (getline(ss, word, ',')) { row.push_back(word); }
        matricNum1 = stoi(row[0]);
        int row_size = row.size();
        if (matricNum1 == matricNum){
            count = 1;
            stringstream convert;

            // sending a number as a stream into output string
            convert << new_marks;

            // parsing the number into strings
            row[index] = convert.str();

            if (!fin.eof()){
                for (int i = 0; i < row_size -1; i++){
                    // write the updated data into a new file "reportcardnew.csv" using fout
                    fout << row[i] << ", ";
                }
                fout << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()){
                for (int i = 0; i < row_size -1 ; i++){
                    // writing other existing record into tht new file using fout
                    fout << row[i] << ", ";
                }

                // the last column data ends with a '\n'
                fout << row[row_size - 1] << "\n";
            }
        }
        if (fin.eof())
                break;
    }
     if (count == 0)
            cout << "Record not found\n";
        
        fin.close();
        fout.close();

        // removing the existing file
        remove("data.csv");

        // renaming the updated file with the initial file name
        rename("datanew.csv", "data.csv");
}

*/