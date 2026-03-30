// using oops concepts in code makes the code more efficient
// all programs can be written without oops, but with oops the code becomes more structure/efficient and close to real life scenarios 


// all libraries in c++ like vector,string,stack which are part of STL exist because of oops
// oops concepts were used to implement them internally 


// class - car (basic functions/blueprint of car)
// object - particular car model (all car models have features or blueprint stated in class) {instance of class}

// class student 
// object age,subject,name 

// object : teacher 
// methods are the functions which are written inside a class
// methods : name,department,subject,salary 




/*
basic idea 





class collage : 

    object teacher: 
        teacher(name,department,subject,salary)   // attributes

            void change department()        // methods
            int calculate salary_tax()


t1 = teacher(dept,tax)   //making of objects
t2 = teacher(dept)
...and so on


        */







/*
without oops: if we want to change department or store name of multiple teacher, we have to write code manully for all teachers. with help of oops we can reuse this block of code
*/

#include <iostream>
#include <string>
using namespace std;


// CLASS
class teacher {

    // DATA MEMBERS (also called properties / attributes / member variables)
    string name;      // attribute / property / data member
    string dept;      // attribute / property / data member
    string subject;   // attribute / property / data member
    double salary;    // attribute / property / data member


    // MEMBER FUNCTION (also called method)
    void changedept(string newdept){   // newdept is PARAMETER
        
        dept = newdept;  // dept and newdept are DATA used here
        
    }

};


int main(){

    // OBJECTS (instances of class 'teacher')
    teacher t1;
    teacher t2;

}
```

## 1. Data

Data is the actual value stored in memory.

Example:

```cpp
t1.name = "Satyam";
t1.salary = 250000;
```

Here:

"Satyam" and 250000 are data.

Data = value

---

## 2. Properties / Attributes / Data Members (same thing)

These are variables inside a class.

Example:

```cpp
string name;
double salary;
```

These describe the object.

Teacher has properties:

* name
* dept
* subject
* salary

All four mean the same thing:

* properties
* attributes
* data members
* member variables

These are synonyms.

---

## 3. Object

Object is the real world instance of class.

Example:

```cpp
teacher t1;
```

t1 is an object.

Memory example:

```text
t1:
name
dept
subject
salary
```

Each object has its own copy.

---

## 4. Member Function (Method)

Function inside class.

Example:

```cpp
void changedept(string newdept)
```

This function belongs to teacher class.

So it is called:

* member function
* method

Same meaning.

---

## 5. Parameter

Parameter is the input variable inside function definition.

Example:

```cpp
void changedept(string newdept)
```

newdept is parameter.

It receives value when function is called:

```cpp
t1.changedept("CS");
```

"CS" goes into newdept.

---

## 6. Argument (related to parameter)

Argument is the actual value passed.

Example:

```cpp
t1.changedept("CS");
```

"CS" is argument.

newdept is parameter.

---

# Complete mapping table (very important)

| Term                               | Meaning                    | Example           |
| ---------------------------------- | -------------------------- | ----------------- |
| Class                              | blueprint for an object    | class teacher     |
| Object                             | instance of class          | teacher t1        |
| Data                               | actual value               | "Satyam", 250000  |
| Attribute / Property / Data member | variable inside class      | string name       |
| Member function / Method           | function inside class      | void changedept() |
| Parameter                          | input variable in function | string newdept    |
| Argument                           | value passed to function   | "CS"              |

---

# Real world analogy (Teacher example)

Class = teacher blueprint

Object:

```cpp
teacher t1;
```

Attributes:

```cpp
name
dept
salary
```

Data:

```cpp
t1.name = "Satyam";
```

Member function:

```cpp
t1.changedept("IT");
```

Parameter:

```cpp
string newdept
```

Argument:

```cpp
"IT"
```

---

# Memory visualization

```text
teacher t1:

+----------------+
| name    Satyam |
| dept    CS     |
| subject C++    |
| salary  250000 |
+----------------+
```

Each object has separate memory.

---

# Interview level one line summary

Class contains:

* attributes (data members)
* member functions

Object contains:

* actual data values

Functions use:

* parameters (input variables)

---

If you want, I can also explain **difference between class, object, pointer to object, and this pointer**, which is critical before linked list.
