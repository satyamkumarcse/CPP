

#include <iostream>
#include <string>
using namespace std;


class teacher {


    //properties or attributes
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
    t1.name = "satyam";
    t1.subject = "C++";
    t1.dept = "cs";
    t1.salary = 250000;

    cout<<t1.name<<endl;    // shows error as data & methods present in class are bydefault private 
    return 0;
   

   
}

