/*here shallow copies fails
during dynamic memory allocation*/

#include <iostream>
#include <string>

using namespace std;

class student{
    public:
    string name;
    double *cgpaptr=NULL;    // all these were allocated memory in stack

    student(string name,double cgpa){

        this->name = name;
        /*we had a pointer cgpaptr which was a null pointer, we made it point to a special memory which can store double type data and allocated it memory in heap.*/
        cgpaptr = new double;   //memory alocated dynamically in heap
        *cgpaptr = cgpa;
        /*let, that cgpaptr was pointing at address 100, we then stored 9.1 cgpa at that address*/

    }


    // student (student &obj){
    //     this->name = obj.name;
    //     this->cgpa = obj.cgpa;
    // }


    student (student &s2){
        this->name = s2.name;    // any of them will work
        this->cgpaptr = s2.cgpaptr;
    }

    void getinfo(){

        cout<<"name: "<<name<<endl;
        cout<<"cgpa: "<<*(cgpaptr)<<endl;

    }


};

int main(){

    student s1("satyam",9.1);
    // s1.getinfo();
    student s2(s1);
    s2.getinfo();
}