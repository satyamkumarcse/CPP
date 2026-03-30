


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
    


teacher(string name,string dept,string subject,double salary){   // parameterised constructor
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
   
}
    //copy constructor made by us 
    teacher(teacher &t1){    //pass by refrence
        cout<<"im custom made copy constructor"<<endl;
        this->name = t1.name;
        this->dept = t1.dept;
        this->subject = t1.subject;
        this->salary = t1.salary;
           
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


int main(){

    teacher t1("satyam","cs","c++",230000); 
    // t1.getinfo();


    teacher t2(t1);   //custom copy constructor was invoke


    cout<<t2.dept<<endl; 
    t2.getinfo();

    return 0;
    
}



/*whenever copies are made of an object, there are 2 types of copies that can be made 
1)shallow copy  2) deep copy

1) in general the default copy constructor or the constructor that was made by us, creates shallow copy

shallow copy - a shallow copy of an object copies all of the member values from one object to another 

we get issues with shallow copies during dynamic memory allocation, like during using new keyword. why lets see in next slide


*/

