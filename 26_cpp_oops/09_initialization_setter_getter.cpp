// initialization in a constructor 


#include <iostream>
#include <string>
using namespace std;


class teacher {
private: 
       double  salary; 

public:
    teacher(){
        cout<<"hi im a constructor"<<endl;  //making of a constructor 
        dept = "cs";    // initialization
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

    teacher t1;  //the moment t1 object was made, department was initialized to "cs"
    teacher t2;
    t1.name = "satyam";
    t1.subject = "C++";
    // t1.dept = "cs"; //dont write here, we initialized a constructor, ie- all teachers are of cs dept only
    // t1.salary = 250000;
    t1.setsalary(250000);

    cout<<t1.dept<<endl;   // dept was not assigned in the main fucntion, but the constructor has automatially assigned dept as cs, so when we call it we get output as "cs". basically department was initialized in our constructor.

    cout<<t1.getsalary();   
   
   

    return 0;
   

   
}


// constructor is always declared as public,since the main fucntion gives a call to constructor when object is made
// as main function dont have access to private members
// thus constructor are always declared as public




/*when a class is made,as such not much space is occupied. but when an object is created of that class

eg-
teacher t1;     some memory is allocated

teachet t2;     some more memory allocated

memory allocation happens for objects, not class.

*/