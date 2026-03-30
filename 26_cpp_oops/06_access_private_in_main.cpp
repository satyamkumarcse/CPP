/*

if after setting salary as private attribute, if i want to access it outside the class in main: we can make special member functions and set those functions as public. {called as getter and setter}

*/

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

    teacher t1;   // declaration of object
    t1.name = "satyam";
    t1.subject = "C++";
    t1.dept = "cs";
    // t1.salary = 250000;   // shows error

    t1.setsalary(250000);
    cout<<t1.getsalary();   
    //using setter and getter we can fetch values/make changes



    // cout<<t1.salary<<endl;    // will show error as salary attribute is private

   

    return 0;
   

   
}






//setters
void setsalary(int s){

    salary = s;

}


//getters
int getsalary(){

    return salary

}