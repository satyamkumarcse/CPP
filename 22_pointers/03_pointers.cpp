// lets quickly go back to the analogy of free pizzas.
// lets create an array of strings(--8)
#include <iostream>
using namespace std;

int main(){

    string freepizzas[5] = {"pizza1","pizza2","pizza3","pizza4","pizza5"};
    // instead of carrying around five pizzas place to place, its a lot easier to go tell them where its located. 
    // ill give them an address by creating a pointer to this array

    // string *pFreePizzas = &freepizzas;

    // here a problem will arise, my array is itself an address (--23), so there is no need to use ampersand {addressof operator (&) }


    string *pFreePizzas = freepizzas;  // the pointer by default points at first element 





    // cout<<freepizzas;
    // output : 0x61fe80 

    // if we derefrence an array, it prints the first element
    cout<<pFreePizzas<<endl;
    cout<<*pFreePizzas<<"\n";   // gives first element of the array.
    cout<<*(pFreePizzas+1);   // gives second element of the array.




return 0;
}