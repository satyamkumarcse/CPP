// ternary operator is represented by "?:"
/*
?: = replacement of if/else statements

we write a condition, then a question mark. if the
 condition is true, run expression1 code, other wise run expression2 code.

condition ? expression1 : expression2;

expression1 = executed if true 
expression2 = executed if false

1-true 
0-false




*/

#include <iostream>
using namespace std;


// int main(){

   

    // int grade =75;
    // int grade =39;

    // if (grade>40){
    //     cout<<"you passed";
    // }
    // else{

    //     cout<<"you failed!!";
    // }
    // the following block of code can also we written as;
    
    //  grade> 40 ? cout<<"you passed!!" : cout<<"you failed!!";




//     return 0;
// }



// int main(){
//      int x;
//     cout<<"enter a number: ";
//     cin>>x;
//     //  x%2==0 ? cout<<"the number is even" : cout<<"the number is odd"; (both will work)
//      x%2 ? cout<<"the number is odd" : cout<<"the number is even";   

//      return 0;
// }


int main(){

    bool hungry = true;
    // bool hungry = false;

    // hungry == true ? cout<<"you are hungry" : cout<<"you are full"; (in case of bool, many ways are correct)
    hungry ? cout<<"you are hungry" : cout<<"you are full";
    std::cout<<( hungry? "you are hungry" : "you are full");

    return 0;
}






