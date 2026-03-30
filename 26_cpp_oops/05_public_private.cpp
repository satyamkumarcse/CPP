

#include <iostream>
#include <string>
using namespace std;


class teacher {
private: 

       double  salary;  // generally salaries are private

public:
    //properties or attributes
    string name;
    string dept;
    string subject;
    
 
   
    void changedept(string newdept){
        dept = newdept;
    }

};


class student{
public:
    string name;
    int rollno;
    int age;

};



int main(){

    teacher t1;   // declaration of object
    t1.name = "satyam";
    t1.subject = "C++";
    t1.dept = "cs";
    // t1.salary = 250000;    // shows error

    cout<<t1.name<<endl;   
    // cout<<t1.salary<<endl;   // will show error as salary attribute is private
    return 0;
   

   
}

/*When a variable is private, you cannot access or modify it directly from outside the class. To allow controlled access, you create public member functions called getter and setter.*/