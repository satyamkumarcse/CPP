
// instead of writing functions multiple time in order to accept multiple datatype, we can write just function that will accept any datatype and peform a common operation on them like finding max,min.
// for creating a function template, take your function and replace its datatype with 'T'
// or 'thing' or like any name
// were here using T as a common naming convention.
// the compiler by default dont know what 'T' is, we will add a declaration of what 'T' is above the function template


#include <iostream>
using namespace std;
template<typename T>  // this function template will work with multiple data types

T maxele(T x,T y){      

    return (x>y) ? x: y;

}


int main(){

    cout<<maxele(1,2)<<endl;
    // cout<<maxele(1,2.1)<<endl;    // this throws error, with this function template,its only setup to recieve arguements of the same datatype
    // for receiving multiple datatype see next file 
 
return 0;
}

