/*
'this' is a special pointer in c++ that points to the current object
'this' is a keyword which is a pointer which points to the object which invokes the member function
*/

/*Core idea in one line

this is a pointer that points to the current object.
this->variable means access the variable of the current object.*/


// #include <iostream>
// using namespace std;

// class A{
//     private:
//     int a;
//     public:
//     //setter
//     void setdata(int a1){
//         a=a1;
//     }
//     //getter
//     int getdata(){
//         return a;
//     }


// };

// int main(){

//     A aa;
//     aa.setdata(4);
//     cout<<aa.getdata();

// }





//this code, written above works, but the one below wont work, a garbage value will be printed instead of 4,instead of showing error if a garbage value is created, it can create big problems in big performance heavy enterprise
// a unique is there which is "this"
/**this is a pointer */





// #include <iostream>
// using namespace std;

// class A{
//     private:
//     int a;
//     public:
//     //setter
//     void setdata(int a){
//         a=a;
//     }
//     //getter
//     int getdata(){
//         return a;
//     }


// };

// int main(){

//     A aa;
//     aa.setdata(4);
//     cout<<aa.getdata();

// }




//now there will be no problem





// #include <iostream>
// using namespace std;

// class A{
//     private:
//     int a;
//     public:
//     //setter
//     void setdata(int a){
//         this->a=a;
//     }
//     //getter
//     int getdata(){
//         return a;
//     }


// };

// int main(){

//     A aa;
//     aa.setdata(4);
//     cout<<aa.getdata();

// }





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
    

//non parametrised
teacher(){
    dept = "cse core";
}


teacher(string name,string dept,string subject,double salary){   // parameterised constructor
    this->name = name;
    this->dept = dept;
    this->subject = subject;
    this->salary = salary;
   
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
    t1.getinfo();


    cout<<t1.dept<<endl; 

    return 0;
    
}


/*so basically if a make an object which is of any class. that occupy will occupy some space in the memory. "this" will point to that memory

eg- if the address of the memory is 100, this will store 100.
this -> has memory address
*(this) -> is out object
*(this).prop -> property of an object
*/