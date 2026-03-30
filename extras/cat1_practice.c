// // f to c conversion

// #include <stdio.h>

// int celtofaren(int c){

//     int temp;

//     temp = 1.8*c + 32;

//     return temp;

// }


// int main(){

//     int f,c;

//     printf("enter value in C: ");
//     scanf("%f",&c);

//     f = celtofaren(c);

//     printf("C TO F conversion gave us F = %.2f",f);
    

//     return 0;


  
// }





// while finding gcd between two number A and B 
// gcd(A, B) = gcd(B % A, A)

// #include <stdio.h>

// int findgcd(int a, int b){
//     int temp;
//     if(a > b){
//         temp = a;
//         a = b;
//         b = temp;
//     }
//     while(b % a != 0){
//         temp = b % a;
//         b = a; 
//         a = temp;
//     }
//     return a;
// }

// int main(){
//     int a, b;
//     printf("enter values of a and b: ");
//     scanf("%d %d", &a, &b);
//     int x = findgcd(a, b);
//     printf("gcd is %d\n", x);
//     return 0;
// }

/*

#include <stdio.h>

int int_factorial(int n){

    int temp,j;
    temp = 1;

    for(j=1;j<=n;j++){
        temp=temp*j;
    }

    return temp;

}


int main(){

    int i,n=10;

    for(i=1;i<=n;i++){

        printf("%d! = %d\n",i,int_factorial(i));
    }


    return 0;
}

*/


/*
Write a C program that reads two integers `m` and `n`, computes the sum of combinations ( nCr ) for all odd values of `r` from 1 to `m`, and prints the result.
Use separate functions to compute `nCr` and factorial.
n>=m is assumption here
*/




/*
#include <stdio.h>

int factorial(int n){

    int j,temp=1;

    for(j=1;j<=n;j++){
        temp*=j;
    }

    return temp;

}


int nCr(int n,int r){

    return(factorial(n)/factorial(r)/factorial(n-r));


}





int main(){

    int n,m,i,sum=0;

    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i+=2){
        sum=sum+ nCr(n,i);
    }

    printf("the sum is %d",sum);


    return 0;
}
*/

/*
#include <stdio.h>

long int factorial(int n){

    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }

}

int main(){

    int n=10;

    long int x = factorial(n);
    printf("%d",x);



}
*/




// find max in arr

/*
#include <stdio.h>

int findmax(int arr1[],int n){

    if(n==1){
        return arr1[0];

    }
    
    int temp = findmax(arr1,n-1);
    if(arr1[n-1]>temp){
        temp = arr1[n-1];
        
    }
    else{
        return temp;

    }

    return temp;
}

int main(){

    int n=10;

    int arr1[10]={12,34,56,44,11,78,66,55,90,10};

    int x = findmax(arr1,n);

    printf("%d",x);

    return 0;
}
*/




// calc fib

/*
#include <stdio.h>

int fib(int n){

    if(n==0 || n==1){
        return 1;
    }
    
    
    return fib(n-1)+fib(n-2);
    
}

int main(){

    int n = 6;
    int x = fib(n);
    printf("%d",x);

    return 0;
}
*/


// find sum of squares of 2 numbers 






/*
#include <stdio.h>

int sumsquares(int n,int m){

    int middle;

    if(n==m){
        return n*n;
    }

    middle = (n+m)/2;
    
    return sumsquares(n,middle) + sumsquares(middle+1,m);

    
}

int main(){

    int n,m;
    scanf("%d %d",&n,&m);

    int x = sumsquares(n,m);

    printf("%d",x);


    return 0;
}
*/









// print reverse





/*
#include <stdio.h>

void printreverse(int m){

    if(m<10){
        printf("%d",m);
        return;     // if we comment this, infinite recursion
        

    }

    printf("%d",m%10);
    printreverse(m/10);

}

int main(){


    int m;
    scanf("%d",&m);
    printreverse(m);
    return 0;
}
*/



// print number of zeroes in a number


// #include <stdio.h>

// int printzeroes(int m){

//     if(m<10){
//         return 0;
//     }

//     if(m%10==0){
//         return (1+printzeroes(m/10));
//     }
//     else{
//         return (printzeroes(m/10));
//     }
// }




// int main(){

//     int m;
//     scanf("%d",&m);
//     int x = printzeroes(m);
//     printf("%d",x);
//     return 0;

// }






/*

#include <stdio.h>

void increment(int *x);

int main(){

    int x = 45;

    printf("%d\n",x);
    int *px = &x;
    increment(px);    // pass by refrence
    printf("%d",x);

    return 0;
}

void increment(int *px){

    (*px)++;   // derefrences the pointer and then increment the value stored in it.
    // px++;  //increments the address itself
    

}



#include <stdio.h>

float average(int *p, int n){
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += *(p+i);
    return (float)sum/n;
}

int maximum(int *p, int n){
    int max = *p;
    for(int i=1;i<n;i++){
        if(*(p+i) > max)
            max = *(p+i);
    }
    return max;
}

int main(){
    int hr[6] = {72,75,70,68,80,78};
    int n = 6;

    printf("Average HR: %.2f\n", average(hr,n));
    printf("Max HR: %d\n", maximum(hr,n));

    int num;
    num=1;
    repeat:
    printf("%d",num); 
    num++;
    if(num<=10){
        goto repeat;
    }



    return 0;
}




*/


// call by value - concept (no change in the output after swap function use)

/*
#include <stdio.h>

void swap(int x,int y){

    int temp = y;
    y = x;
    x = temp;


    
}

int main(){
     int x = 45;
     int y = 12;

     printf("before swap x and y were %d %d ",x,y);
     printf("\n");

     swap(x,y);

      printf("after swap x and y were %d %d ",x,y);

    return 0;
}
*/







/*

#include <stdio.h>

void swap(int *x,int *y){

    int temp = *y;
    *y = *x;
    *x = temp;


    
}

int main(){
     int x = 45;
     int y = 12;

     printf("before swap x and y were %d %d ",x,y);
     printf("\n");

     int *ptrx = &x;
     int *ptry = &y;

    //  swap(&x,&y);    // any of it works
     swap(ptrx,ptry);

      printf("after swap x and y were %d %d ",x,y);

    return 0;
}


*/


// array of pointers : an array which has all the elements as pointers.


// #include <stdio.h>


// int main(){

//     int a = 10;
//     int b = 20;
//     int c = 30;
//     // int *ptrc = &c;


//     // int *arr1[3]  = {&a,&b,&c};
//     int* arr1[3]  = {&a,&b,&c};

//     for(int i=0;i<3;i++){

//         printf("the element present in array is %d and its memory address is %p\n",*arr1[i],arr1[i]);
        
//     }
// }


// AUTOMATIC 


/*
#include <stdio.h>

int main(){

    int a;
    char b;
    int c;

    printf("values are %d %c %c",a,b,c);  // -> garbage value is printed
}
*/






// STATIC

// #include <stdio.h>

// void visit() {
//     static int count = 0;  // static variable ( 1 2 3 )   WITH NORMAL ( 1 1 1 )
//     count++;
//     printf("Function called %d times\n", count);
// }

// int main() {
//     visit();
//     visit();
//     visit();
//     return 0;
// }



// REGISTER 


/*
#include <stdio.h>

int main(){

    register int a;

    printf("%d",a);


    return 0;
}
*/


// the program below shows error


// #include <stdio.h>


// int main(){

//     extern int a;
//     printf("%d",a);



//     return 0;
// }




// this will not show error, prints 4



// #include <stdio.h>
 
// int a = 4;

// int main(){

//     extern int a;
//     printf("%d",a);



//     return 0;
// }



// this prints 0






// #include <stdio.h>
 
// int a;

// int main(){

//     extern int a;
//     printf("%d",a);

//     return 0;

// }




// error is thrown



// #include <stdio.h>
 
// int a;

// int main(){

//     extern int a=4;          (we cant use extern and initializer at same time)
//     printf("%d",a);

//     return 0;

// }





// throws error



// #include <stdio.h>
 
// int a = 4;

// int main(){

//     extern int a;
//     printf("%d",a);
// int a = 55;      // throws error, redefinition



//     return 0;
// }






// special operators:  


// #include <stdio.h>
// int main() {
//     int A = 8;
//     int *p = &A;
//     printf("%lu\n", sizeof(A));
//     printf("%p\n", &A);
//     printf("%d\n", *p);
// }



// code recursive function that processes a number and udates a variable in the calling function, using call by refrence


// #include <stdio.h>

// void updator(int *ptrx){

//     if(*ptrx==50){
//         return ;
//     }

//     *ptrx +=1;

//     return updator(ptrx);

// }

// int main(){

//     int x = 45;
//     int *ptrx = &x;

//     updator(ptrx);

//     printf("%d",x);



//     return 0;
// }




// gcd using recursion



/*
#include <stdio.h>

int gcd(int a,int b);

int main(){

    int a,b;


    printf("enter 2 number for gcd calculation: ");
    scanf("%d %d",&a,&b);

    int x = gcd(a,b);

    printf("%d",x);


    return 0;
}


int gcd(int a,int b){



    if(a==0){
        return b;
    }

    return gcd(b%a,a);


}
    */


// ACCESSING ELEMENTS OF 2D MATRIX, PRintING EACH 1D ARRAY 


// #include <stdio.h>

// int main(){

//     int arr1[3][3]={{1,2,3},{4,5,6},{7,8,9}};

//     for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++){
//         printf(" array %d element is ",i+1);
//         for(int j=0;j<sizeof(arr1[0])/sizeof(arr1[0][1]);j++){

//             printf("%d ",arr1[i][j]);

            
//         }
//         printf("\n");
//     }


//     return 0;
// }


// 



// #include<stdio.h>

// int main(){

//     int arr[]={12,23,45};

//     int *ptr = arr;

//     printf("%d",(ptr+1));


//     return 0;
// }







// we can create a 2d array with N number of rows and 2 columns. each sub array (1d) array present in 2d array will store price - quantity
// the choice of taking a 2d is appropriate as we can easily store price , quantity pairs.



// #include <stdio.h>

// int totalbill(int arr1[][2],int items);


// int main(){

//     int items;

//     printf("enter the number of items you want to calculate price of: ");
//     scanf("%d",&items);

//     int arr1[items][2];

//     for(int i=0;i<items;i++){
//         printf("enter the item no: %d quantity:\n",i+1);
//         scanf("%d",&arr1[i][0]);

//         printf("enter the item no: %d price: ",i+1);
//         scanf("%d",&arr1[i][1]);
//     }

//     int x = totalbill(arr1,items);

//     printf("total price is: %d",x);




//     return 0;
// }


// int totalbill(int arr1[][2],int items){

//     int sum = 0;

//     for(int i=0;i<items;i++){
//         sum+=arr1[i][0]*arr1[i][1];
        
//     }

//     return sum;
// }





/*

int add(int x , int  y){

    return x+y;    // this is function in C, i want to store address of this function

}

int (*ptr)(int x,int y)     // function pointer declartion 



address can be stored by this syntax
    if(choice == 1)
        fp = add;   // store address of add
    else
        fp = sub;   // store address of sub


fp(x, y);
This calls whichever function address is stored inside fp.



*/



/*A function also has an address in memory.

So you can store the address of a function in a pointer.

That pointer is called a function pointer.*/




// #include <stdio.h>

// int add(int a, int b) {
//     return a + b;
// }

// int sub(int a, int b) {
//     return a - b;
// }

// int main() {

//     int x, y;
//     int choice;

//     // function pointer
//     int (*fp)(int, int);    // declares a function pointer 

//     printf("Enter two numbers: ");
//     scanf("%f %f", &x, &y);

//     printf("1. Addition\n2. Subtraction\nEnter choice: ");
//     scanf("%d", &choice);

//     if(choice == 1)
//         fp = add;   // store address of add
//     else
//         fp = sub;   // store address of sub

//     printf("Result = %f", fp(x, y));  // call through pointer

//     return 0;
// }







// #include <stdio.h>

// int add(int a, int b);
// int sub(int a, int b);



// int main(){

//     int choice,a,b;

//     printf("choose the operation to peform:\n");
//     printf("1 : addition\n");
//     printf("2 : subtraction\n");

//     scanf("%d",&choice);

//     printf("enter two numbers: ");
//     scanf("%d %d",&a,&b);

//     int(*fp)(int a,int b);

//     if(choice ==1){

//         fp = add;

//     }
//     else{

//         fp = sub;

//     }

//     printf("%d", fp(a,b));      // the address of whichever function is stored in function pointer, that will be called.

//     return 0;

// }


// int add(int a, int b){
//     return a+b;
// }

// int sub(int a, int b){
//     return a-b;
// }








// #include <stdio.h>

// int main(){

//     int highest = -10000;
//     int j=-1;

//     int arr1[7]={12000,45000,23000,10000,7000,8000,2000};

//     for(int i=0;i<6;i++){
      
//         if(arr1[i]>highest){
//               j = i;
//             highest = arr1[i];

            
            
//         }

//     }

//     printf("highest salary is %d and is at position %d",highest,j+1);





//     return 0;
// }





/*
### Entry Control Loop

In an entry control loop, the **condition is checked before** the loop body executes.

If the condition is false at the beginning, the loop will **not run even once**.

Examples:

* `for` loop
* `while` loop

---

### Exit Control Loop

In an exit control loop, the **condition is checked after** the loop body executes.

So the loop body will **run at least one time**, even if the condition is false.

Example:

* `do while` loop

*/



// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>

// int main(){

//     char s[20];
//     bool hasUpper = false;
//     bool hasDigit = false;
//     bool hasSpecial = false;

//     printf("Enter a password to be validated: ");
//     scanf("%s", s);

//     for(int i = 0; i < strlen(s); i++){

//         if(s[i] >= 'A' && s[i] <= 'Z'){
//             hasUpper = true;
//         }
//         else if(s[i] >= '0' && s[i] <= '9'){
//             hasDigit = true;
//         }
//         else if(s[i] == '@' || s[i] == '#' || s[i] == '$' || s[i] == '%'){
//             hasSpecial = true;
//         }
//     }

//     if(hasUpper && hasDigit && hasSpecial){
//         printf("Valid password");
//     }
//     else{
//         printf("Invalid password");
//     }

//     return 0;
// }






// #include <stdio.h>

// void byvalueswap(int x,int y);
// void byrefswap(int *x,int *y);


// int main(){

//     int x,y;

//     scanf("%d %d",&x,&y);

//     printf("values before swap were: %d %d\n",x,y);

//     byvalueswap(x,y);

//        printf("vales after swap are %d %d\n",x,y);

//     byrefswap(&x,&y);

//        printf("vales after swap are %d %d\n",x,y);


// }

// void byvalueswap(int x,int y){

//     int temp;

//     temp = x;
//     x = y;
//     y = temp;

 


// }

// void byrefswap(int *x,int *y){

//       int temp1;

//     temp1 = *x;
//     *x = *y;
//     *y = temp1;

 
// }



// when called by value, no swapping occurs, as copies are made of x and y when they are passed without refrence, and the operation of swap happens on the copies. in case of pass by refrence, we pass the pointer itself (the)



// #include <stdio.h>

// int main(){

//     int r1, c1, r2, c2;

//     printf("Enter order of matrix 1 (rows columns): ");
//     scanf("%d %d", &r1, &c1);

//     printf("Enter order of matrix 2 (rows columns): ");
//     scanf("%d %d", &r2, &c2);

//     if(c1 != r2){
//         printf("Matrix multiplication not possible.\n");
//         return 0;
//     }

//     int A[r1][c1], B[r2][c2], C[r1][c2];

//     printf("Enter elements of matrix 1:\n");
//     for(int i = 0; i < r1; i++)
//         for(int j = 0; j < c1; j++)
//             scanf("%d", &A[i][j]);

//     printf("Enter elements of matrix 2:\n");
//     for(int i = 0; i < r2; i++)
//         for(int j = 0; j < c2; j++)
//             scanf("%d", &B[i][j]);

//     // Initialize result matrix
//     for(int i = 0; i < r1; i++)
//         for(int j = 0; j < c2; j++)
//             C[i][j] = 0;

//     // Matrix multiplication logic
//     for(int i = 0; i < r1; i++){
//         for(int j = 0; j < c2; j++){
//             for(int k = 0; k < c1; k++){
//                 C[i][j] += A[i][k] * B[k][j];
//             }
//         }
//     }

//     printf("Resultant matrix:\n");
//     for(int i = 0; i < r1; i++){
//         for(int j = 0; j < c2; j++){
//             printf("%d ", C[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }




// matrix transpose logic 


// #include <stdio.h>

// int main() {
//     int r, c;

//     printf("Enter rows and columns: ");
//     scanf("%d %d", &r, &c);

//     int a[r][c], t[c][r];

//     printf("Enter matrix elements:\n");
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             scanf("%d", &a[i][j]);
//         }
//     }

//     // Transpose
//     for(int i = 0; i < r; i++){
//         for(int j = 0; j < c; j++){
//             t[j][i] = a[i][j];
//         }
//     }

//     printf("\nTranspose matrix:\n");
//     for(int i = 0; i < c; i++){
//         for(int j = 0; j < r; j++){
//             printf("%d ", t[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }



























// // #include <stdio.h>

// // int addition(int a, int b){
// //     return a + b;
// // }

// // int subtract(int a, int b){
// //     return a - b;
// // }

// int multiply(int a, int b){
//     return a * b;
// }

// int divide(int a, int b){
//     return a / b;
// }

// int main(){

//     int a, b;
//     int choice;

//     int (*fp)(int a, int b);

//     printf("Enter an operation you want to perform:\n");
//     printf("1 - addition\n");
//     printf("2 - subtraction\n");
//     printf("3 - multiplication\n");
//     printf("4 - division\n");
//     printf("5 - exit\n");

//     scanf("%d", &choice);

//     if(choice == 5)
//         return 0;

//     printf("Enter 2 numbers: ");
//     scanf("%f %f", &a, &b);

//     switch(choice){

//         case 1: fp = addition; break;
//         case 2: fp = subtract; break;
//         case 3: fp = multiply; break;
//         case 4: fp = divide; break;
//         default: return 0;
//     }

//     printf("Result = %f", fp(a, b));

//     return 0;
// }





// #include <stdio.h>

// int reversenum(int *num){

//     int rev=0;
//     int digit;
//     while(*num>0){
//         digit = *num%10;
//         rev = rev*10 + digit;
//         *num/=10;

//     }

//     *num = rev;


// }





// int main(){
//     int num;

//     printf("enter a number you want to reverse: ");
//     scanf("%d",&num);

//     printf("%d\n",num);

//     reversenum(&num);

//         printf("%d",num);


//     return 0;
// }




// #include <stdio.h>
// #include <string.h>

// int main(){

//     char s[30];
//     printf("enter a string literal: ");
//     scanf("%[^\n]", s);

//     printf("the length of input string is %lu\n",strlen(s));
//     int flag=1;

    

//     for(int i=0;i<strlen(s)/2;i++){
//         if(s[i]!=s[strlen(s)-i-1]){
//             flag = 0;
//             break;
        
//     }


  
  

//     }


//       if(flag==1){
//         printf("palindrome");
//     }
//     else{
//         printf("not a palindrome");
//     }




//     return 0;
// }



// #include <stdio.h>

// int main() {
//     int a[5] = {10, 20, 30, 40, 50};
//     int *p = a;

//     printf("*(p + 2) = %d\n", *(p + 2));
//     printf("*(p) + 2 = %d\n", *(p) + 2);
//     printf("*p++ = %d\n", *p++);
//     printf("*p - 2 = %d\n", *p - 2);

//     return 0;
// }

// #include <stdio.h>

// int main(){
//     int calls = 0;
//     int bill = 0;

//     printf("enter number of calls: ");
//     scanf("%d", &calls);
    
//     if(calls <= 200){
//         bill = 0.80 * calls;
//     }
//     else if(calls <= 500){
//         bill = 0.80 * 200 + 0.50 * (calls - 200);
//     }
//     else{
//         bill = 0.80 * 200 + 0.50 * 300 + 0.30 * (calls - 500);
//     }

//     if(bill < 150){
//         bill = 150;
//     }

//     if(bill > 1000){
//         bill = bill + bill / 10;
//     }

//     printf("total bill is: %.2f\n", bill); 

//     return 0;
// }

// #include <stdio.h>
// #include <string.h>
// #include <ctype.h>

// int main() {

//     char s[100];
//     int a=0, e=0, i=0, o=0, u=0;

//     printf("Enter a string: ");
//     scanf(" %[^\n]", s);

//     for(int k = 0; k < strlen(s); k++) {
//         char ch = tolower(s[k]);

//         if(ch == 'a') a++;
//         else if(ch == 'e') e++;
//         else if(ch == 'i') i++;
//         else if(ch == 'o') o++;
//         else if(ch == 'u') u++;
//     }

//     printf("a:%d e:%d i:%d o:%d u:%d\n", a, e, i, o, u);

//     return 0;
// }
