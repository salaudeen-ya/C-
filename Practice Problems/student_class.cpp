#include <iostream>
#include <sstream>
#include <string>
#include <limits>
using namespace std;

class Student{
private: 
    int age;
    string first_name;
    string last_name;
    int standard;
public:
    void set_age(int a){age = a;}
    void set_first_name(string fname){
        while (fname.length() < 50){
            first_name = fname;
        }
    }
    void set_last_name(string lname){
        while (lname.length() < 50){
            last_name = lname;
        }
    }
    void set_standard(int sd){standard = sd;}
    int get_age(){return age;}
    string get_first_name(){return first_name;}
    string get_last_name(){return last_name;}
    int get_standard(){return standard;}
    string to_string(){
        ostringstream oss{};
        oss << age << ", " << first_name << ", " << last_name << ", " << standard << endl;
        return oss.str(); 
    }
};
