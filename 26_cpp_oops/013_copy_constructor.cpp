/*copy constructor is a special constructor (default) used to copy properties of one object into another

if we dont make a copy constructor, c++ makes a default copy constructor for us*/




#include <iostream>
#include <string>
using namespace std;


class teacher {
private: 
       double  salary; 

public:


teacher(string name,string dept,string subject,double salary){   // parameterised constructor
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
   
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


int main(){

    teacher t1("satyam","cs","c++",230000); 
    // t1.getinfo();


    teacher t2(t1);   // default copy constructor was invoked {not made us by}, all info {data} of object1 was copied into object t2.
    t2.getinfo();


    // cout<<t1.dept<<endl; 

    return 0;
    
}


//if we want we can make a copy constructor by out self also, see in class setion
