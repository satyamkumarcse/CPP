// assinging or accessing the properties of object


/*

teacher t1;
t1.name = "satyam";
cout<<t1.name;
t1.changedept();

*/



#include <iostream>
#include <string>
using namespace std;


class teacher {
// private: // even if not written here, by default private
public: //{no error is shown now}

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

    cout<<t1.name<<endl;   //error will be shown , it will show that name is a private member of "teacher";
    // access modifiers concept comes to place
    return 0;
   

}


/*

access modifiers
private,public and protected 

1) private - data & methods are accessible inside the class only.
bydefault all attributes and member functions are private {the reason why error was shown}
they can be accessed/changed or modified inside the class only, not outside it

2) public : data and methods are accessible to everyone 

3) protected : data and methods accessible inside class and to its derived class 

eg- if i make a class, and some more classes which are derived from that class. the derived classes cant access the data and methods of the main class {as they are private}

protected: can be written to access them


*/
