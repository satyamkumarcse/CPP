
/*

constrcutor are of 3 types 
non parameterized constructor
eg- 
  teacher(){
        cout<<"hi im a constructor"<<endl;  //making of a constructor 
        dept = "cs";
    }

parameterised constructor


*/



#include <iostream>
#include <string>
using namespace std;


class teacher {
private: 
       double  salary; 

public:

     //properties or attributes
    string name;
    string dept;
    string subject;


    teacher(string n,string d,string s,double sal){   // parameterised constructor
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    }
  


   
    
 
   
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

    teacher t1("satyam","cs","c++",230000);  //a call automatically goes to the constuctor, when a object is made
    t1.getinfo();

    // t1.name = "satyam";    
    // t1.subject = "C++";
    

    cout<<t1.dept<<endl; 

    return 0;
    
}