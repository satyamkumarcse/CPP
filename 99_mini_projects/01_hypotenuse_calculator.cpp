#include <iostream>
#include <cmath>

int main(){

    double a;
    double b;


    std::cout<<"enter side a: "<<std::endl;
    std::cin>>a;
    std::cout<<"enter side b: "<<std::endl;
    std::cin>>b;

    // double c = sqrt(pow(a,2) + pow(b,2));
    // (can also be written as;)
    a = pow(a,2);
    b = pow(b,2);
    double c = sqrt(a+b);

    std::cout<<c;


    return 0;

}



