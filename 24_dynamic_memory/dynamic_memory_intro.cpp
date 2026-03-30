/*
So far in C++, you have mostly written code like this:

int x = 10;
int arr[5];

or

void func() {
    int a = 5;
}


the memory is allocated automatically, its not in our control. 
at compile time, memory size is decided. 
eg- int x=10;   x takes 4 bytes.
the memory is stored in stack.
when the main function or scope ends, memory is automatically released and destroyed by stack.


this is called as automatic (static-sized) memory allocation.

we cant decide when the memory is freed.
you did not change memory size at runtime.
you did not manage memory manually.


*/

/*
if i am using automatic memory :
i cant code:

int n;
cin >> n;
cout<<x;
int arr[n];   // ❌ not standard C++ (it works in my compiler, but wont be accepted universally)

short lifetime: 

int returnmax() {
    int x = 10;
    return &x;   // ❌ invalid after function or scope ends
}

after the function (its scope) ends, stack memory is destroyed.


Stack Size Limit :
Stack is small
Large arrays can cause stack overflow.



*/

/*

What Is Dynamic Memory (The New Concept)

Dynamic memory means:

Memory that is allocated at runtime, whose size and lifetime are controlled by the programmer. the lifetime is there until deleted.

This memory comes from the heap, not the stack.


Earlier (Stack)
int a = 10;

Dynamic (Heap)
int *a = new int(10);

Heap memory remains alive after function ends.
stack memory is destroyed after a function ends.

*/

/*
. Where Dynamic Memory Is NOT Required 
You do NOT need dynamic memory when:

Case 1: Fixed, Small Variables
int x;
float y;
char c;

Case 2: Small Fixed Arrays
int arr[10];

Case 3: Simple Programs

Loops
Conditionals
Basic functions
Pattern printing
Small logic programs

*/

// in dynamic memory, "new" keyword allocates memory in the heap instead of stack and returns a memory address. after our work is done, we can use "delete" keyword to delete the dynamically assignd memory.