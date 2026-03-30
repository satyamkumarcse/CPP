#include <iostream>
using namespace std;

template<typename T, typename U>  // now we can recieve upto 2 different datatypes 


// T mmax(T x,U y){    
auto mmax(T x,U y){

    return (x>y) ? x:y;

}


int main(){

    cout<<mmax(1,2.1);   // still we are getting 2, as return type was 'T' (line 7), change return type to auto, the compiler will deduce what the return type should be

    return 0;

}