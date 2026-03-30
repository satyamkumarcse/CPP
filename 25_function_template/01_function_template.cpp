//  a function template describes what a function looks like.  
// it can be used to generate as many overloaded functions as needed, each using different data types.


// int max(){}  Standard library functions can override yours
// Naming functions max, min, count is dangerous.



// quick revision




// Function Overloading (Quick Revision)
// Definition

// Function overloading means same function name, different parameter list.
// The compiler decides which function to call based on the arguments. This is called compile time polymorphism.


#include <iostream>
using namespace std;

int add(int a, int b){
    return a + b;
}

double add(double a, double b){
    return a + b;
}

int main(){
    cout << add(2, 3) << endl;      // calls int version
    cout << add(2.5, 3.5) << endl;  // calls double version
}



/*
shows error: 

int func(int a){
    return a;
}

double func(int a){   // ERROR
    return a;
}
    

// as parameter type is similar 

*/



/*Function overloading requires:

Same function name

Different number of parameters OR
Different parameter types OR
Different order of parameters

Not allowed:

*/







#include <iostream>
using namespace std;

int maxele(int x,int y){      

    return (x>y) ? x : y;

}

double maxele(double x,double y){      

    return (x>y) ? x : y;

}

char maxele(char x,char y){      

    return (x>y) ? x : y;

}

int main(){



    cout<<maxele(1,2)<<endl;
    cout<<maxele(1.1,2.1)<<endl;
    // output is 2 instead of 2.1
    // the decimal portion is ignored.
    cout<<maxele('1','2')<<endl;


return 0;
}

// creating 3 overloaded functions that do the same thing (returning max value) is lengthy
// let us create one function that can accept any datatype 
// this is basically what function template are