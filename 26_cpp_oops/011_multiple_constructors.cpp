/*

a class can have multiple constructors, given that the parametres are different for each of them

in case there are multiple constructors,following the above rule, the compiler will figure out and call the constructor by looking at how many parametres were passed.

this phenomenon, of occurence of multiple constructor, is called as constructor overloading

constructor overloading is an example of polymorphism

*/
#include <iostream>
#include <string>
using namespace std;


class teacher {
private: 
       double  salary; 

public:

//non parametrised
teacher(){
    dept = "cse core";
}


teacher(string n,string d,string s,double sal){   // parameterised constructor
    name = n;
    dept = d;
    subject = s;  // the constructor will be called
    salary = sal;
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

    void getinfo(){
        cout<<"name: "<<name<<endl;
        cout<<"subject: "<<subject<<endl;
    }


};




class student{
public:
    string name;
    int rollno;
    int age;

};

 

int main(){

    teacher t1("satyam","cs","c++",230000); 
    t1.getinfo();


    cout<<t1.dept<<endl; 

    return 0;
    
}

