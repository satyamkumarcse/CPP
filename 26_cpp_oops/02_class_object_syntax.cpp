// c++

// declaring a class 

#include <iostream>
#include <string>
using namespace std;


class teacher {

    //properties or attributes or data member
    string name;
    string dept;
    string subject;
    double  salary;


    //methods or member functions (as these functions become a member of class "teacher")
    void changedept(string newdept){
        dept = newdept;
    }

};

// objects are made inside the int main(){}; function

int main(){

    teacher t1;   // declaration of object
    teacher t2;
    teacher t3;
    teacher t4;

    // all these 4 individual objects that have been made all attributes/properties mentioned in the class
    // we can now make changes/update these information
}