//  in cpp, heap is a region of memory used for dynamic memory allocation. ie- allocating or deallocating memory during runtime ie- when program is running .

//                        { dynamic memory }

// dynamic memory is the memory that is allocated after the program is already compiled or running.

// for allocating dynamic memory, we use "new" keyword. its an operator. 
// its allows us to allocate memory in the heap rather than the stack and returns a memory address.

// its useful when we dont know how much memory we need.
// it makes the programs more flexible, especilly when accepting user input. 
//cause generally we dont have any idea what the user will type & how much emory it will occupy.
// instead of allocating memory initially, we can do it during the program run using dynamic memory.




// let us start with a basic integer variable
// we will allocate memory in heap rather than the stack by using the new keyword.
// let us create a pointer. 

#include <iostream> 
using namespace std;

int main(){

    // int *pnum = nullptr; 
    // pnum = new int; 

    // or directly write

    int *pnum = new int(21);




    // in order to allocate memory in heap rather than stack. we will take the pointer and set this equal to, use the "new" operator then a datatype.
    // variable = "new" + "datatype" ;

    // the new operator will return an address, and we are storing that address within pnum. as pnum is a pointer.

    // later on in a program, whenever you would like to store value, we can use the derefrence operator. 

    // *pnum = 21;

    cout<<"memory address is: "<<pnum<<endl;
    cout<<"value stored inside it is: "<<*pnum<<endl;

    // our pointer is storing this address : 0x1197eb0. and at this address in the heap, that address contains this value : 21.

    // its a good practice, whenever you use the new operator, you should use the delete operator. when you are no longer using that memory space.

    delete pnum;           // we are freeing up the memory at this address.

    // if we dont do this, it may cause a memory leak. so its best to avoid that.

    return 0;
}

//  delete x;
//  delete x;

//  if delete is written 2 times, it can lead to undefined behavior. as the memory in the heep is freed up in the first deletion only.