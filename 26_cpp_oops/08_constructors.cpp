// constructor 

// special member function(method) invoked automatically at time of object creation. used for initialization 


#include <iostream>
#include <string>
using namespace std;


class teacher {
private: 
       double  salary;  // generally salaries are private


public:
    teacher(){                              // use the name of class in public, for making a constructor
        cout<<"hi im a constructor"<<endl;  //making of a constructor 
    }


    //properties or attributes
    string name;
    string dept;
    string subject;
    
 
   
    void changedept(string newdept){
        dept = newdept;
    }

    //setter  - thier work is to set private values
    void setsalary(double s){
        salary = s;
    }

    //getter  - to get or fetch the private values
    double getsalary(){
        return salary;
    }


};


class student{
public:
    string name;
    int rollno;
    int age;

};

 


int main(){

    teacher t1;  //  automatically a call goes to the constuctor, when a object is made
    teacher t2;
    t1.name = "satyam";
    t1.subject = "C++";
    t1.dept = "cs";
    // t1.salary = 250000;
    t1.setsalary(250000);

    cout<<t1.name<<endl;
    cout<<t1.getsalary();   
   
   

    return 0;
   

   
}

/*
class itself dont occupy much space,but when objects are made from class, eg- obj1,obj2,obj3 
Each object gets its own separate copy of all data members

space is allocated for the data members 
if we want to initialize the data members with some values, we can use constructors 
if we dont create a constructor,compiler automatically makes it for us and calls it
*/



/*
properties of constructors 

name is same as the class

it does not have any return type 

constructor is only called once at object creation, cant be called later for that particular object

Memory for data members is allocated when the object is created. The constructor is then called to initialize that allocated memory.
*/


/*if we create a concstructor, then compiler dont make it, the constructor made by us gets a call when object is made*/


