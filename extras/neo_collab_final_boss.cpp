
// normally matrix 

  for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }


// transpose of a matrix code : n=rows,m=columns


for (int j = 0; j < m; j++)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", matrix[i][j]);
    }
    printf("\n");
}



#include <stdio.h>

// Structure definition
struct Student
{
    char name[50];
    int m1, m2, m3;
};

// Function 1: total marks of ALL students
int getTotal(struct Student arr[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += arr[i].m1 + arr[i].m2 + arr[i].m3;
    }

    return total;
}

// Function 2: takes pointer to structure and updates marks (+5 bonus)
void addBonus(struct Student *s)
{
    s->m1 += 5;
    s->m2 += 5;
    s->m3 += 5;
}

// Function 3: returns structure containing topper
struct Student getTopper(struct Student arr[], int n)
{
    struct Student top = arr[0];
    int maxTotal = arr[0].m1 + arr[0].m2 + arr[0].m3;

    for (int i = 1; i < n; i++)
    {
        int currTotal = arr[i].m1 + arr[i].m2 + arr[i].m3;

        if (currTotal > maxTotal)
        {
            maxTotal = currTotal;
            top = arr[i];
        }
    }

    return top;
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student arr[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter name and 3 marks for student %d:\n", i + 1);
        scanf("%s %d %d %d", arr[i].name, &arr[i].m1, &arr[i].m2, &arr[i].m3);
    }

    // Apply bonus
    for (int i = 0; i < n; i++)
    {
        addBonus(&arr[i]);
    }

    // Display totals after bonus (per student)
    printf("\nTotal marks after bonus:\n");
    for (int i = 0; i < n; i++)
    {
        int total = arr[i].m1 + arr[i].m2 + arr[i].m3;
        printf("%s: %d\n", arr[i].name, total);
    }

    // Total of all students
    int classTotal = getTotal(arr, n);
    printf("\nTotal marks of entire class: %d\n", classTotal);

    // Find topper
    struct Student topper = getTopper(arr, n);

    int topperTotal = topper.m1 + topper.m2 + topper.m3;

    printf("\nTopper: %s\n", topper.name);
    printf("Total Marks: %d\n", topperTotal);

    return 0;
}








#include <stdio.h>

// Structure definition
struct Student
{
    char name[50];
    int m1, m2, m3;
};

// Function 1: takes structure (pass by value) and returns total marks
int getTotal(struct Student s)
{
    return s.m1 + s.m2 + s.m3;
}

// Function 2: takes pointer to structure and updates marks (+5 bonus)
void addBonus(struct Student *s)
{
    s->m1 += 5;
    s->m2 += 5;
    s->m3 += 5;
}

// Function 3: returns structure containing topper
struct Student getTopper(struct Student arr[], int n)
{
    struct Student top = arr[0];
    int maxTotal = getTotal(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int currTotal = getTotal(arr[i]);

        if (currTotal > maxTotal)
        {
            maxTotal = currTotal;
            top = arr[i];
        }
    }

    return top;
}

int main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student arr[n];

    // Input
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter name and 3 marks for student %d:\n", i + 1);
        scanf("%s %d %d %d", arr[i].name, &arr[i].m1, &arr[i].m2, &arr[i].m3);
    }

    // Apply bonus using pointer function
    for (int i = 0; i < n; i++)
    {
        addBonus(&arr[i]);
    }

    // Display totals after bonus
    printf("\nTotal marks after bonus:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s: %d\n", arr[i].name, getTotal(arr[i]));
    }

    // Find topper
    struct Student topper = getTopper(arr, n);

    printf("\nTopper: %s\n", topper.name);
    printf("Total Marks: %d\n", getTotal(topper));

    return 0;
}






#include <iostream>
using namespace std;

// Base class
class Person
{
protected:
    string name;
    int id;

public:
    Person(string n, int i)
    {
        name = n;
        id = i;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }
};

// Derived class 1
class Employee : virtual public Person
{
protected:
    double salary;

public:
    Employee(string n, int i, double s) : Person(n, i)
    {
        salary = s;
    }

    void displayEmployee()
    {
        cout << "Salary: " << salary << endl;
    }
};

// Derived class 2
class Consultant : virtual public Person
{
protected:
    double hourlyRate;
    int hoursWorked;

public:
    Consultant(string n, int i, double rate, int hours) : Person(n, i)
    {
        hourlyRate = rate;
        hoursWorked = hours;
    }

    void displayConsultant()
    {
        cout << "Hourly Rate: " << hourlyRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
    }
};

// Final derived class (diamond)
class Manager : public Employee, public Consultant
{
public:
    Manager(string n, int i, double s, double rate, int hours)
        : Person(n, i),      // must initialize virtual base here
          Employee(n, i, s),
          Consultant(n, i, rate, hours)
    {
    }

    void displayManager()
    {
        displayPerson();      // no ambiguity due to virtual inheritance
        displayEmployee();
        displayConsultant();

        double total = salary + (hourlyRate * hoursWorked);

        cout << "Total Income: " << total << endl;
    }
};

int main()
{
    Manager m("Alice", 101, 50000, 200, 20);

    cout << "\nManager Details:\n";
    m.displayManager();

    return 0;
}





// #practice

#include<bits/stdc++.h>


#include <iostream>
using namespace std;

class Complex{
    public:
    int real,imag;

    Complex(int r,int i){
        real = r;
        imag = i;

    }

    Complex operator+(Complex c){
        return Complex(real + c.real,imag+c.imag);
    }

    void display(){
        cout<<real<<"+"<<imag<<"i"<<endl;
    }

}

int main(){

    Complex obj1(2,3);
    Complex obj2(6,3);
    Complex obj3 = obj1 + obj2;
    obj3.display();




    return 0;
}


/*

Step 1: When you write
Complex c3 = c1 + c2;
Step 2: What C++ internally does
c1.operator+(c2);

then logic of addition runs : 
 Complex operator+(Complex c) {
        int r = real + c.real;
        int i = imag + c.imag;
        return Complex(r, i);
    }

flow:

c1 + c2
↓
c1.operator+(c2)  {addition logic runs}
↓
(2 + 3i) + (4 + 5i)
↓
(6 + 8i)



this was for object + object , can also  be dont for object*object,obect*value
Left side object calls function
Right side is passed as parameter {parameter from outside the class} , parameter can be another object,variable,constant,value
*/


// object*value example 




/*You are given:

* Initial velocity
* Acceleration
* Time

Task:

* Create an `Acceleration` class
* Overload the `*` operator to compute:
  `acceleration * time`
* Use the formula:
  `final velocity = initial velocity + (acceleration × time)`
* Print the final velocity rounded to one decimal place with `" m/s"`

In short: **use operator overloading to compute acceleration × time and then calculate final velocity.**
*/




#include <iostream>
#include <iomanip>
using namespace std;

class Acceleration {
private:
    float a;

public:
    Acceleration(float a) {
        this->a = a;
    }

    // Overload * operator (Acceleration * time)
    float operator*(float time) {
        return a * time;
    }
};

int main() {
    float u, acc, t;
    cin >> u >> acc >> t;

    Acceleration A(acc);

    float finalVelocity = u + (A * t);   // object*value

    cout << fixed << setprecision(1) << finalVelocity << " m/s";

    return 0;
}






#include <iostream>
using namespace std;

class Number {
public:
    int value;

    // Constructor
    Number(int v) {
        value = v;
    }

    // Operator overloading for +
    Number operator+(Number n) {
        // This runs ONLY when we use: object + object
        return Number(value + n.value);
    }

};

int main() {
    Number a(5), b(10);

    // CASE 1: OBJECT + OBJECT
    // a and b are objects, so overloaded operator+ is called
    Number c = a + b;   // internally: a.operator+(b)
    cout << "Using overloaded + (a + b): " << c.value << endl;

    // CASE 2: MEMBER + MEMBER
    // a.value and b.value are int (primitive type)
    // so normal built-in + is used, NOT overloaded operator
    int d = a.value + b.value;
    cout << "Using normal + (a.value + b.value): " << d << endl;

    // -----------------------------
    // SAME IDEA WITH ! OPERATOR
    // -----------------------------

    bool x = true;

    // This uses built-in NOT operator (primitive type)
    cout << "Built-in ! on bool: " << !x << endl;

    // If we had:
    // !object -> overloaded (if defined)
    // !object.value -> built-in (because it's bool)

    return 0;
}




#include <iostream>
using namespace std;

class Bool {
public:
    bool value;

    Bool(bool v) {
        value = v;
    }

    bool operator!() {
        return !value;
    }
};

int main() {
    Bool myTrue(true);
    Bool myFalse(false);

    cout << !(myTrue.value) << " " << !(myFalse.value);    // code does not use the overloaded operator !.
    Bool c = !myTrue;
    Bool d = !myFalse;
    cout<<c.value<<" "<<d.value;
    

    return 0;
}


output : 0 1



// #operator overloaded, but not called 


#include <iostream>
using namespace std;

class Complex {
public:
    int a;
    int b;

    Complex(int r, int i) {
        a = --r;
        b = --i;
    }

    // Overloaded operator (WILL NOT BE USED)
    Complex operator+() {
        cout << "Overloaded + called\n";
        return Complex(a, b);
    }
};

int main() {
    Complex obj(-3, 4);

    // Instead of: Complex c = +obj;  (this calls overload)
    // We directly access values → NO operator overloading

    cout << obj.a << " " << obj.b;

    return 0;
}



// operator overloaded is called 

// decrement happens two times {the constructor is called two times}


#include <iostream>
using namespace std;

class Complex {
public:
    int a;
    int b;

    Complex(int r, int i) {
        a = --r;
        b = --i;
    }

    Complex operator+() {
        return Complex(a, b);
    }
};

int main() {
    Complex a(-3, 4);
    Complex c = +a;
    cout << c.a << " " << c.b;
    return 0;
}





#include <iostream>
using namespace std;

class Number {
public:
    int x, y, z;

    Number(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }

    Number operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }
};

int main() {
    Number p(-99, 10, 29);
    Number q = ++p;

    cout << p.x << " " << p.y << " " << p.z << endl;
    cout << q.x << " " << q.y << " " << q.z;

    return 0;
}

// output : 
// -98 11 30 
// -98 11 30



#include <iostream>
using namespace std;

class Number {
public:
    int value;

    Number(int v) {
        value = v;
    }

    Number operator-() {
        return Number(--value);
    }

    Number operator+() {
        return Number(++value);
    }
};

int main() {
    Number m(-5);
    Number n = -m;
    Number p = +n;

    cout << m.value << " " << n.value << " " << p.value;
    return 0;
}

// output : -6 -5 -5 


// pre incrememt 

#include <iostream>
using namespace std;

class Num {
    int x;
public:
    Num(int x) {
        this->x = x;
    }

    Num operator++() {
        ++x;
        return *this;
    }

    void display() {
        cout << x << endl;
    }
};

int main() {
    Num n(5);
    ++n;
    n.display();
}

// post increment : has dummy parameter 

#include <iostream>
using namespace std;

class Num {
    int x;
public:
    Num(int x) {
        this->x = x;
    }

    Num operator++(int) {
        Num temp = *this;
        x++;
        return temp;
    }

    void display() {
        cout << x << endl;
    }
};

int main() {
    Num n(5);
    Num c = n++;
    c.display();  // 5
    n.display();  // 6
}





#include <iostream>
using namespace std;

class Base {
public:
    virtual int calc(int a, int b) {
        return a - b;
    }
};

class Derived : public Base {
public:
    // int calc(int a, int b) override {
    //     return a % b;
    // }
    int calc(int a, int b) {    
        return a % b;                                    // use any one 
    }


};

int main() {
    Base* ptr;
    Derived d;
    ptr = &d;

    int result = ptr->calc(10, 4) * d.calc(7, 8) - ptr->calc(5, 1);   //derived functions is called not base  // 2*7 - 0 = 14
    cout << result;

    return 0;
}




// virtual & base class pointer and derived object 



#include <iostream>
using namespace std;

class Base {
public:
    virtual void func() {
        cout << "Base ";
    }
};

class Derived : public Base {
public:
    void func() {
        cout << "Derived ";
        Base::func();
    }
};

int main() {
    Derived d;
    Base* b = &d;
    b->func();
    return 0;
}

// output  : derived base 








 
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void display() {
        cout << "Shape! ";
    }
};

class Square : public Shape {
    int s = 10, area;
public:
    Square(int side) {
        s += side;
    }

    void display() override {
        Shape::display();
        area = s * s;
        cout << area << " ";
    }
};

int main() {
    Square s(5);
    Shape* ptr = &s;

    ptr->display();
    s.display();

    return 0;
}

/*
Output:
Shape! 225 Shape! 225
*/



derived d;
base* ptr = &d;
ptr->show();

derived d;
base& ref = d;
ref.show();


// problem :if virtual keyword not used, derived destructor is not called,resource leak can happen 

#include <iostream>
using namespace std;

class Base {
public:
    ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived Destructor\n";
    }
};

int main() {
    Base* ptr = new Derived;
    delete ptr;
}


// solution : use virtual keyword 
// now first derived destructor is called and destroyed,then base destructor is called

#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Base Destructor\n";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived Destructor\n";
    }
};

int main() {
    Base* ptr = new Derived;
    delete ptr;
}



// example 


#include <iostream>
using namespace std;

class Media {
public:
    virtual void play() const = 0;
};

class Audio : public Media {
public:
    void play() const{
        cout << "Audio Playing..." << endl;
    }
};

class Video : public Media {
public:
    void play() const {
        cout << "Video Playing..." << endl;
    }
};

int main() {
    Audio a;
    Video v;

    Media* media1 = &a;
    Media* media2 = &v;

    media1->play();
    media2->play();

    return 0;
}

/*
Output:
Audio Playing...
Video Playing...
*/





#include <iostream>
using namespace std;

class Flight {
public:
    virtual void V() = 0;

    void fun() {
        cout << "Started ";
    }
};

class Fly : public Flight {
public:
    void V() override {
        cout << "Accelerating ";
    }

    void fun() {
        Flight::fun();
        cout << "Flying ";
    }
};

int main() {
    Fly f;
    f.fun();
    f.V();
    return 0;
}

/*
Output:
Started Flying Accelerating 
*/




/*You are given a train departure time (hours and minutes).

Task:

* Create a `Time` class to store this time.
* Overload the **pre-increment operator (`++`)** to increase time by **1 minute**.
* Handle proper rollover:

  * 59 minutes → next hour
  * 23:59 → 0:0
* Print:

  1. Original time
  2. Updated time after increment

In short: **simulate a clock that moves forward by one minute using operator overloading.**
*/

#include <iostream>
using namespace std;

class Time {
private:
    int h, m;

public:
    Time(int h, int m) {
        this->h = h;
        this->m = m;
    }

    // Pre-increment operator
    Time operator++() {
        m++;
        if (m == 60) {
            m = 0;
            h++;
            if (h == 24) {
                h = 0;
            }
        }
        return *this;
    }

    void display() {
        cout << h << "h " << m << "m" << endl;
    }
};

int main() {
    int h, m;
    cin >> h >> m;

    Time t(h, m);

    t.display();  // original time
    ++t;
    t.display();  // updated time

    return 0;
}






#include <iostream>
#include <iomanip>
using namespace std;

class Student {
private:
    int id;
    double weight;

public:
    Student(int id, double weight) {
        this->id = id;
        this->weight = weight;
    }

    // Friend function for ++ operator
    friend void operator++(Student &s);

    void displayStudent() {
        cout << id << " " << fixed << setprecision(2) << weight << endl;
    }
};

// Pre-increment using friend
void operator++(Student &s) {
    s.weight += 1.0;
}

int main() {
    Student s1(101, 65.5);

    cout << "Before increment: ";
    s1.displayStudent();

    ++s1;   // calling overloaded ++

    cout << "After increment: ";
    s1.displayStudent();

    return 0;
}





// virtual functions and overriding

#include <iostream>
#include <iomanip>
using namespace std;

class Popul {
public:
    int initial, finalp;

    virtual void calcRate(int i, int f) {     // it will be override,will have no significance 
        initial = i;
        finalp = f;
    }
};

class Birth : public Popul {
public:
    void calcRate(int i, int f){
        initial = i;
        finalp = f;

        double rate = (1000.0 * (finalp - initial)) / initial;
        cout << fixed << setprecision(2) << rate;
    }
};

int main() {
    int N, P;
    cin >> N >> P;

    Popul* ptr;
    Birth b;

    ptr = &b;
    ptr->calcRate(N, P);

    return 0;
}



/*You are given:

Student name
Roll number
Student type (U or G)
Two grades (depending on type)
Task
Create a base class Student with virtual functions:
inputGrades()
calculateGrade()
Create two derived classes:
UndergraduateStudent → uses midterm + final
GraduateStudent → uses research + presentation
Based on type (U or G), use the correct class
Compute average of the two grades
Print:
Name
Roll Number
Total Grade*/



#include <iostream>
using namespace std;

class Student {
public:
    string name, roll;

    void setDetails(string n, string r) {
        name = n;
        roll = r;
    }

    virtual void inputGrades() = 0;
    virtual void calculateGrade() = 0;

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << roll << endl;
    }
};

class UndergraduateStudent : public Student {
private:
    int mid, finalg;

public:
    void inputGrades() {
        cin >> mid >> finalg;
    }

    void calculateGrade() {
        int avg = (mid + finalg) / 2;
        cout << "Total Grade: " << avg;
    }
};

class GraduateStudent : public Student {
private:
    int research, presentation;

public:
    void inputGrades() {
        cin >> research >> presentation;
    }

    void calculateGrade() {
        int avg = (research + presentation) / 2;
        cout << "Total Grade: " << avg;
    }
};

int main() {
    string name, roll;
    char type;

    cin >> name >> roll >> type;

    UndergraduateStudent u;
    GraduateStudent g;

    Student* ptr;

    if (type == 'U') {
        ptr = &u;
    } else {
        ptr = &g;
    }

    ptr->setDetails(name, roll);
    ptr->inputGrades();
    ptr->displayDetails();
    ptr->calculateGrade();

    return 0;
}



// You are given hours and minutes.

// Task
// Create a base class Time to store time and display it
// Create two derived classes:
// TimeToSeconds → converts time to seconds
// TimeToMinutes → converts time to minutes
// Override display() in derived classes for conversion
// Use a base class pointer to call different display() functions (runtime polymorphism)
// Key concept
// Base class prints original time
// Derived classes override and print converted values
// Base pointer is reused to call all versions


#include <iostream>
using namespace std;

class Time {
public:
    int h, m;

    Time(int h, int m) {    
        this->h = h;
        this->m = m;
    }

    virtual void display() {
        cout << "Time: " << h << "h " << m << "m" << endl;
    }
};

class TimeToSeconds : public Time {
public:
    TimeToSeconds(int h, int m) : Time(h, m) {}     // base class dont have any default constructor,so the constructor has to be called manually

    void display() {
        int total = (h * 60 + m) * 60;
        cout << total << " seconds" << endl;
    }
};

class TimeToMinutes : public Time {
public:
    TimeToMinutes(int h, int m) : Time(h, m) {}

    void display() {
        int total = h * 60 + m;
        cout << total << " minutes" << endl;
    }
};


int main() {
    int h, m;
    cin >> h >> m;

    Time t(h, m);
    TimeToSeconds ts(h, m);
    TimeToMinutes tm(h, m);

    Time* ptr;

    ptr = &t;
    ptr->display();

    ptr = &ts;
    ptr->display();

    ptr = &tm;
    ptr->display();

    return 0;
}





// You are given:

// * VIP ticket: price, age, number of tickets
// * Standard ticket: price, age, number of tickets

// ### Task

// * Create a base class `Reservation` with a virtual function `calculate()`
// * Create two derived classes:

//   * `VIP` → apply VIP discount rules
//   * `Standard` → apply standard discount rules
// * Based on age, apply the correct discount percentage
// * Compute:

// ```text
// final price = price × (1 − discount) × number of tickets
// ```

// * Print total cost for VIP and Standard tickets (2 decimal places)

// ---

// ### One-line summary

// **Use runtime polymorphism to apply different age-based discounts and calculate total ticket prices for VIP and Standard reservations.**






#include <iostream>
#include <iomanip>
using namespace std;

class Reservation {
public:
    double price;
    int age, count;

    virtual double calculate() = 0;
};

class VIP : public Reservation {
public:
    double calculate() {
        double discount = 0;

        if (age >= 4 && age <= 12) discount = 0.21;
        else if (age <= 25) discount = 0.15;
        else discount = 0.10;

        double finalPrice = price * (1 - discount);
        return finalPrice * count;
    }
};

class Standard : public Reservation {
public:
    double calculate() {
        double discount = 0;

        if (age >= 4 && age <= 12) discount = 0.18;
        else if (age <= 25) discount = 0.14;
        else discount = 0.05;

        double finalPrice = price * (1 - discount);
        return finalPrice * count;
    }
};

int main() {
    VIP v;
    Standard s;

    cin >> v.price >> v.age >> v.count;
    cin >> s.price >> s.age >> s.count;

    Reservation* ptr;

    ptr = &v;
    cout << fixed << setprecision(2);
    cout << "VIP ticket price: Rs." << ptr->calculate() << endl;

    ptr = &s;
    cout << "Standard ticket price: Rs." << ptr->calculate();

    return 0;
}





// ### Summary

// Calculate total meal cost for a group using OOP and polymorphism.

// * Base class `MenuItem` with pure virtual `calculatePrice()`
// * Derived classes `Appetizer` and `MainCourse`
// * Each item price is multiplied by number of persons
// * Sum all items and print total cost

// ---
// A pure virtual function (calculatePrice()) is declared in base class
// It is overridden in both derived classes (Appetizer, MainCourse)
// This makes the base class abstract
// Each object uses its own overridden version
// Logic is applied per object and accumulated

// ```cpp
#include <iostream>
#include <iomanip>
using namespace std;

class MenuItem {
public:
    float price;

    MenuItem(float price) {
        this->price = price;
    }

    virtual float calculatePrice(int persons) = 0;
};

class Appetizer : public MenuItem {
public:
    Appetizer(float price) : MenuItem(price) {}

    float calculatePrice(int persons) {
        return price * persons;
    }
};

class MainCourse : public MenuItem {
public:
    MainCourse(float price) : MenuItem(price) {}

    float calculatePrice(int persons) {
        return price * persons;
    }
};

int main() {
    int numPersons, numAppetizers, numMainCourses;
    cin >> numPersons;
    cin >> numAppetizers >> numMainCourses;

    float totalCost = 0.0;

    for (int i = 0; i < numAppetizers; i++) {
        float price;
        cin >> price;
        Appetizer appetizer(price);
        totalCost += appetizer.calculatePrice(numPersons);
    }

    for (int i = 0; i < numMainCourses; i++) {
        float price;
        cin >> price;
        MainCourse mainCourse(price);
        totalCost += mainCourse.calculatePrice(numPersons);
    }

    cout << fixed << setprecision(2);
    cout << "Rs. " << totalCost;

    return 0;
}







// ### Summary

// * Base class `Transport` has a **pure virtual function `operate()`**
// * Derived classes `TransportA` and `TransportB` **override this function**
// * Based on input type (`P/p` or `F/f`), correct class is used
// * Time is calculated using formula and printed
// * **Concept used: Pure virtual function overridden (runtime polymorphism, but called via objects)**

// ---


#include <iostream>
#include <cmath>
using namespace std;

class Transport {
public:
    virtual void operate(int start, int dest) = 0;
};

class TransportA : public Transport {
public:
    void operate(int start, int dest) {
        int time = abs(start - dest) * 2;
        cout << "Time taken: " << time << " seconds" << endl;
    }
};

class TransportB : public Transport {
public:
    void operate(int start, int dest) {
        int time = abs(start - dest) * 3;
        cout << "Time taken: " << time << " seconds" << endl;
    }
};

int main() {
    int numTransports;
    cin >> numTransports;

    for (int i = 0; i < numTransports; i++) {
        char transportType;
        int start, dest;
        cin >> transportType >> start >> dest;

        if (transportType == 'P' || transportType == 'p') {
            TransportA transportA;
            transportA.operate(start, dest);
        } 
        else if (transportType == 'F' || transportType == 'f') {
            TransportB transportB;
            transportB.operate(start, dest);
        }
    }

    return 0;
}








// ### Summary

// * Base class must be **abstract (pure virtual function `game() = 0`)**
// * Derived class **overrides game()`**
// * Uppercase → +10, Lowercase → -5
// * Use base class pointer to call derived function
// * **Concept used: Pure virtual function overridden (runtime polymorphism)**

// ---



#include <iostream>
using namespace std;

class Base {
public:
    virtual void game() = 0;   // pure virtual → abstract class
};

class Derived : public Base {
public:
    void game() {
        char a, b, c, d;
        cin >> a >> b >> c >> d;

        int score = 0;
        char arr[4] = {a, b, c, d};

        for (int i = 0; i < 4; i++) {
            if (arr[i] >= 'A' && arr[i] <= 'Z') {
                score += 10;
            } else {
                score -= 5;
            }
        }

        cout << "Score : " << score;
    }
};

int main() {
    Base* ptr;
    Derived obj;

    ptr = &obj;
    ptr->game();

    return 0;
}






// ### Summary

// * Base class `ItemType` with **virtual function `calculateAmount()`**
// * Two derived classes:

//   * `wooden` → amount = items × cost
//   * `electronics` → amount = 80% of cost (20% discount)
// * Function is **overridden in both classes**
// * Based on choice, correct object is created and used
// * **Concept used: Virtual function overridden (runtime polymorphism)**

// ---




#include <iostream>
#include <iomanip>
using namespace std;

class ItemType {
public:
    virtual double calculateAmount() = 0;   // abstract class
};

class wooden : public ItemType {
private:
    int items;
    double cost;

public:
    wooden(int items, double cost) {
        this->items = items;
        this->cost = cost;
    }

    double calculateAmount() {
        return items * cost;
    }
};

class electronics : public ItemType {
private:
    double cost;

public:
    electronics(double cost) {
        this->cost = cost;
    }

    double calculateAmount() {
        return cost * 0.8;
    }
};

int main() {
    int choice;
    cin >> choice;

    ItemType* ptr;

    if (choice == 1) {
        int items;
        double cost;
        cin >> items >> cost;

        wooden w(items, cost);
        ptr = &w;
        cout << fixed << setprecision(2) << ptr->calculateAmount();
    }
    else if (choice == 2) {
        double cost;
        cin >> cost;

        electronics e(cost);
        ptr = &e;
        cout << fixed << setprecision(2) << ptr->calculateAmount();
    }

    return 0;
}



// diamond problem 

#include <iostream>
#include <iomanip>
using namespace std;

// Base class
class Vehicle {
protected:
    double mileage;
    double fuel;
};

// Derived class: Car
class Car : virtual public Vehicle {
public:
    void setCar(double m, double f) {
        mileage = m;
        fuel = f;
    }

    double calculateCarCost() {
        return 0.1 * mileage + 2.0 * fuel;
    }
};

// Derived class: Truck
class Truck : virtual public Vehicle {
public:
    void setTruck(double m, double f) {
        mileage = m;
        fuel = f;
    }

    double calculateTruckCost() {
        return 1.5 * (0.1 * mileage + 2.0 * fuel);
    }
};

// Derived class: Rental
class Rental : public Car, public Truck {
public:
    void printCosts() {
        cout << fixed << setprecision(2);
        cout << "Total Rental Cost for Car: " << calculateCarCost() << endl;
        cout << "Total Rental Cost for Truck: " << calculateTruckCost();
    }
};

int main() {
    Rental r;

    double cm, cf, tm, tf;
    cin >> cm >> cf >> tm >> tf;

    r.setCar(cm, cf);      // sets shared Vehicle data
    r.setTruck(tm, tf);    // overwrites same data

    r.printCosts();

    return 0;
}





#include <iostream>
using namespace std;

// Base class
class WeatherData {
protected:
    double data;
};

// Derived class: Temperature
class TemperatureData : virtual public WeatherData {
public:
    void setTemperature(double t) {
        data = t;
    }

    string getTemperatureStatus() {
        if (data > 30.0)
            return "Hot";
        else
            return "Cool";
    }
};

// Derived class: Humidity
class HumidityData : virtual public WeatherData {
public:
    void setHumidity(double h) {
        data = h;
    }

    string getHumidityStatus() {
        if (data > 60.0)
            return "Humid";
        else
            return "Dry";
    }
};

// Derived class: MonitoringStation
class MonitoringStation : public TemperatureData, public HumidityData {
public:
    void display(double t, double h) {
        setTemperature(t);                 // set temp
        string tempStatus = getTemperatureStatus();

        setHumidity(h);                   // overwrite data
        string humidityStatus = getHumidityStatus();

        cout << "Weather Condition: "
             << tempStatus << " and " << humidityStatus;
    }
};

int main() {
    double t, h;
    cin >> t >> h;

    MonitoringStation m;
    m.display(t, h);

    return 0;
}







#include <iostream>
#include <string>
using namespace std;

// Function to find length
int length(const string& str1) {
    return str1.length();
}

// Function to count alphabets, digits, special characters
void count(const string& str1) {
    int alphabets = 0, digits = 0, special = 0;

    for (char c : str1) {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
            alphabets++;
        }
        else if (c >= '0' && c <= '9') {
            digits++;
        }
        else {
            special++;
        }
    }

    cout << "Alphabets: " << alphabets << endl;
    cout << "Numbers: " << digits << endl;
    cout << "Special characters: " << special << endl;
}

// Function to count occurrences
void occur(const string& str1) {
    bool visited[256] = {false};

    for (int i = 0; i < str1.length(); i++) {
        if (!visited[(int)str1[i]]) {
            int cnt = 0;

            for (int j = 0; j < str1.length(); j++) {
                if (str1[i] == str1[j]) {
                    cnt++;
                }
            }

            cout << "Occurrence of " << str1[i] << " is " << cnt << endl;
            visited[(int)str1[i]] = true;
        }
    }
}

int main() {
    string str;
    cin >> str;

    cout << "Length: " << length(str) << endl;

    count(str);

    occur(str);

    return 0;
}






// friend class function 


#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    Student(int m) {
        marks = m;
    }

    // Declare friend class
    friend class Result;
};

class Result {
public:
    void displayResult(Student s) {
        if (s.marks >= 50)
            cout << "Pass";
        else
            cout << "Fail";
    }
};

int main() {
    Student s(75);

    Result r;
    r.displayResult(s);

    return 0;
}



#include <iostream>
using namespace std;

class Student {
private:
    int marks;

public:
    Student(int m) {
        marks = m;
    }

    friend class Result;
};

class Result {
public:
    void modifyMarks(Student &s, int newMarks) {
        s.marks = newMarks;  // modifying private data
    }

    void display(Student s) {
        cout << "Marks: " << s.marks << endl;
    }
};

int main() {
    Student s(40);

    Result r;
    r.display(s);

    r.modifyMarks(s, 85);  // change marks

    r.display(s);

    return 0;
}



// struct , arrays , pointers



// complex numbers calculator
#include <math.h>

struct complex {
    float real;
    float imag;
};

struct complex add(struct complex n1, struct complex n2) {
    struct complex res;
    res.real = n1.real + n2.real;
    res.imag = n1.imag + n2.imag;
    return res;
}

struct complex subtract(struct complex n1, struct complex n2) {
    struct complex res;
    res.real = n1.real - n2.real;
    res.imag = n1.imag - n2.imag;
    return res;
}

struct complex multiply(struct complex n1, struct complex n2) {
    struct complex res;
    res.real = (n1.real * n2.real) - (n1.imag * n2.imag);
    res.imag = (n1.real * n2.imag) + (n1.imag * n2.real);
    return res;
}

float modulus(struct complex n) {
    return sqrt((n.real * n.real) + (n.imag * n.imag));
}

scanf("%[^\n]s")

scanf("%[^\n]s")






// supermarket management and report generation 

#include <stdio.h>

// Structure for store details
struct DEP_STORE {
    char store_name[50];
    char store_address[100];
    char phone_no[15];
};

// Structure for item details
struct STORE_ITEM {
    int item_number;
    char item_name[50];
    int available_qty;
    float item_price;
};

// Function to generate report
void generateReport(struct DEP_STORE store, struct STORE_ITEM items[], int n) {
    printf("Store Name: %s\n", store.store_name);
    printf("Store Address: %s\n", store.store_address);
    printf("Phone Number: %s\n\n", store.phone_no);

    printf("Item Number\tItem Name\tAvailable Quantity\tItem Price\n");

    float total = 0;

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n",
               items[i].item_number,
               items[i].item_name,
               items[i].available_qty,
               items[i].item_price);

        total += items[i].available_qty * items[i].item_price;
    }

    printf("\nTotal Item Value: Rs. %.2f", total);
}

int main() {
    struct DEP_STORE store;
    struct STORE_ITEM items[10];
    int n;

    // Input store details
    scanf(" %[^\n]", store.store_name);
    scanf(" %[^\n]", store.store_address);
    scanf(" %[^\n]", store.phone_no);

    // Input number of items
    scanf("%d", &n);

    // Input item details
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i].item_number);
        scanf(" %[^\n]", items[i].item_name);
        scanf("%d", &items[i].available_qty);
        scanf("%f", &items[i].item_price);
    }

    // Generate report
    generateReport(store, items, n);

    return 0;
}







/*
Problem Summary:
Create a structure DEP_STORE with attributes: store_name, store_address, and phone_no.
Create another structure STORE_ITEM with attributes: item_number, item_name,
available_qty, and item_price.

Read the store details and item details from input.
Display a formatted report showing store details along with item details including
item number, item name, available quantity, and item price.

Also calculate and display the total value of all items in the store using:
total = sum of (available_qty * item_price).
*/

#include <stdio.h>
#include <string.h>

struct DEP_STORE {
    char store_name[50];
    char store_address[100];
    char phone_no[15];
};

struct STORE_ITEM {
    int item_number;
    char item_name[50];
    int available_qty;
    float item_price;
};

void generateReport(struct DEP_STORE store, struct STORE_ITEM items[], int n) {

    printf("Store Name: %s\n", store.store_name);
    printf("Store Address: %s\n", store.store_address);
    printf("Phone Number: %s\n\n", store.phone_no);

    printf("Item Number\tItem Name\tAvailable Quantity\tItem Price\n");

    float total = 0;

    for(int i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%d\t\t%.2f\n",
               items[i].item_number,
               items[i].item_name,
               items[i].available_qty,
               items[i].item_price);

        total += items[i].available_qty * items[i].item_price;
    }

    printf("\nTotal Item Value: Rs. %.2f", total);
}

int main() {

    struct DEP_STORE store;

    // Read store details
    scanf(" %[^\n]s", store.store_name);
    scanf(" %[^\n]s", store.store_address);
    scanf("%s", store.phone_no);

    int numItems;
    scanf("%d", &numItems);

    struct STORE_ITEM items[numItems];

    // Read item details
    for (int i = 0; i < numItems; i++) {
        scanf("%d", &items[i].item_number);
        scanf(" %[^\n]s", items[i].item_name);
        scanf("%d", &items[i].available_qty);
        scanf("%f", &items[i].item_price);
    }

    generateReport(store, items, numItems);

    return 0;
}





// optimal 

#include <stdio.h>
#include <string.h>

int main() {
    char c[20] = "satyam1";

    int n = strlen(c);

    for (int i = 0; i < n - 1; i += 2) {
        char temp = c[i];
        c[i] = c[i + 1];
        c[i + 1] = temp;
    }

    printf("%s", c);
}






/*
Problem Summary:
Define a structure Customer with attributes: name, accountNumber, and accountBalance.

Read details of n customers from input.

1. Display the names of customers whose account balance is less than Rs. 200.
2. For customers with account balance greater than Rs. 1000, add 3% interest
   to their balance and display the updated balance.

Use separate functions to:
- Print customers with low balance
- Update balance by adding interest
*/

#include <stdio.h>

struct Customer {
    char name[50];
    int accountNumber;
    float accountBalance;
};

void printLowBalanceCustomers(struct Customer customers[], int n) {
    printf("Customers with balance less than Rs.200: ");
    for (int i = 0; i < n; i++) {
        if (customers[i].accountBalance < 200) {
            printf("%s ", customers[i].name);
        }
    }
}

void addInterest(struct Customer *customer) {
    if (customer->accountBalance > 1000) {
        customer->accountBalance *= 1.03;
        printf(" Updated balance of %s: Rs. %.2f",
               customer->name, customer->accountBalance);
    }
}

int main() {

    int n;
    scanf("%d", &n);

    struct Customer customers[n];

    for (int i = 0; i < n; i++) {
        scanf("%s", customers[i].name);
        scanf("%d", &customers[i].accountNumber);
        scanf("%f", &customers[i].accountBalance);
    }

    printLowBalanceCustomers(customers, n);

    for (int i = 0; i < n; i++) {
        addInterest(&customers[i]);
    }

    return 0;
}






#include <stdio.h>

struct Marks {
    int c, ds, phy;
};

struct Student {
    char name[21];
    int age;
    struct Marks m;
    int total;
};

int main() {

    int n;
    scanf("%d", &n);

    struct Student s[n];

    // Input
    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d %d",
              s[i].name,
              &s[i].age,
              &s[i].m.c,
              &s[i].m.ds,
              &s[i].m.phy);

        s[i].total = s[i].m.c + s[i].m.ds + s[i].m.phy;
    }

    // Bubble Sort (ascending order of total)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].total > s[j + 1].total) {
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Output
    for (int i = 0; i < n; i++) {
        printf("%s %d %d ", s[i].name, s[i].age, s[i].total);
    }

    return 0;
}




// structure with pointers 


/*
Problem Summary:
Create a structure to store student details: roll number, name, age, and address.

Read details of n students.

Perform the following operations using structures and pointers:
1. Print names of students whose age is exactly 17.
2. Print names of students having even roll numbers.
3. Search for a given roll number and print that student's complete details.

Assumptions:
- At least one student is age 17
- At least one student has even roll number
- The searched roll number always exists
*/

#include <stdio.h>

struct Student {
    int roll;
    char name[26];
    int age;
    char address[26];
};

int main() {

    int n;
    scanf("%d", &n);

    struct Student s[n];

    // Input student details
    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %s",
              &s[i].roll,
              s[i].name,
              &s[i].age,
              s[i].address);
    }

    int searchRoll;
    scanf("%d", &searchRoll);

    struct Student *ptr = s;   // pointer to array

    // 1. Students with age 17
    for (int i = 0; i < n; i++) {
        if ((ptr + i)->age == 17) {
            printf("%s ", (ptr + i)->name);
        }
    }

    printf("\n");

    // 2. Students with even roll numbers
    for (int i = 0; i < n; i++) {
        if ((ptr + i)->roll % 2 == 0) {
            printf("%s ", (ptr + i)->name);
        }
    }

    printf("\n");

    // 3. Search by roll number
    for (int i = 0; i < n; i++) {
        if ((ptr + i)->roll == searchRoll) {
            printf("%d %s %d %s",
                   (ptr + i)->roll,
                   (ptr + i)->name,
                   (ptr + i)->age,
                   (ptr + i)->address);
            break;
        }
    }

    return 0;
}



// file handling 


With array (common exam pattern)
C

int arr[3] = {1, 2, 3};

for (int i = 0; i < 3; i++) {
    fprintf(fp, "%d ", arr[i]);
}
Writes:
1 2 3   <- in file


// reading,writing,EOF


#include <stdio.h>

// Write numbers to file
void writeToFile(FILE *series, int *numbers, int records) {
    for (int i = 0; i < records; i++) {
        fprintf(series, "%d ", numbers[i]);
    }
}

// Read numbers from file
int readFromFile(FILE *series, int *numbers) {
    int count = 0;
    while (fscanf(series, "%d", &numbers[count]) != EOF) {
        count++;
    }
    return count;
}

// Bubble sort
void sortNumbers(int *numbers, int records) {
    for (int i = 0; i < records - 1; i++) {
        for (int j = 0; j < records - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

// Calculate median
double calculateMedian(int *numbers, int records) {
    if (records % 2 == 1) {
        return numbers[records / 2];
    } else {
        return (numbers[records / 2 - 1] + numbers[records / 2]) / 2.0;
    }
}

int main() {
    FILE *series;
    int numbers[10];
    int records;

    scanf("%d", &records);

    for (int i = 0; i < records; i++) {
        scanf("%d", &numbers[i]);
    }

    // Write to file
    series = fopen("data.txt", "w");
    if (series == NULL) {
        printf("Error opening file for writing");
        return 1;
    }
    writeToFile(series, numbers, records);
    fclose(series);

    // Read from file
    series = fopen("data.txt", "r");
    if (series == NULL) {
        printf("Error opening file for reading");
        return 1;
    }
    records = readFromFile(series, numbers);
    fclose(series);

    // Sort numbers
    sortNumbers(numbers, records);

    // Calculate and print median
    double median = calculateMedian(numbers, records);
    printf("%.2f", median);

    return 0;
}




#include <stdio.h>
#include <string.h>

/*
Problem Summary:
Read a string and store it in "input.txt".
Then read the string from the file, replace every unique character
(character appearing only once) with the next character in the alphabet
(z should become a), and write the modified string to "output.txt".
*/

// Write to input file
void writeToFile(FILE *fp, char *s) {
    fprintf(fp, "%s", s);
}

// Read from input file
void readFromFile(FILE *fp, char *s) {
    fscanf(fp, "%s", s);
}

// Process string (replace unique characters)
void updateString(char *s) {
    int freq[256] = {0};
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        freq[(int)s[i]]++;
    }

    for (int i = 0; i < len; i++) {
        if (freq[(int)s[i]] == 1) {
            if (s[i] == 'z')
                s[i] = 'a';
            else
                s[i] = s[i] + 1;
        }
    }
}

// Write to output file
void writeOutput(FILE *fp, char *s) {
    fprintf(fp, "%s", s);
}

int main() {
    FILE *fp;
    char s[101];

    // Input
    scanf("%s", s);

    // Write to input.txt
    fp = fopen("input.txt", "w");
    if (fp == NULL) return 1;
    writeToFile(fp, s);
    fclose(fp);

    // Read from input.txt
    fp = fopen("input.txt", "r");
    if (fp == NULL) return 1;
    readFromFile(fp, s);
    fclose(fp);

    // Process string
    updateString(s);

    // Write to output.txt
    fp = fopen("output.txt", "w");
    if (fp == NULL) return 1;
    writeOutput(fp, s);
    fclose(fp);

    return 0;
}



#include <stdio.h>

/*
Problem Summary:
Read n negative integers representing daily stock changes.
Store them in a file named "negative.txt".
Then read the values back from the file, calculate their total sum,
and print the absolute value of the sum.
*/

int main() {
    int n, num;
    FILE *file;
    int sum = 0;

    scanf("%d", &n);

    file = fopen("negative.txt", "w");

    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        fprintf(file, "%d ", num);
    }

    fclose(file);

    file = fopen("negative.txt", "r");

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &num);
        sum += num;
    }

    fclose(file);

    if (sum < 0)
        sum = -sum;

    printf("%d", sum);

    return 0;
}




// static data member . member functions 


/*
Problem Summary:
Create a class Rectangle with:
- A static data member 'count' to track total number of rectangle objects created
- A static member function getCount() to return the count
- Non-static functions:
    setDimensions(int l, int w) to set length and width
    getArea() to calculate area (length * width)

For n rectangles:
- Read length and width
- Store dimensions using objects
- Print total number of rectangles created
- Print area of each rectangle in order
*/


#include <iostream>
using namespace std;

class Rectangle {
private:
    int length, width;
    static int count;

public:
    // Constructor increments count
    Rectangle() {
        count++;
    }

    // Set dimensions
    void setDimensions(int l, int w) {
        length = l;
        width = w;
    }

    // Calculate area
    int getArea() {
        return length * width;
    }

    // Static function to get count
    static int getCount() {
        return count;
    }
};

// Initialize static member
int Rectangle::count = 0;

int main() {
    int n;
    cin >> n;

    Rectangle rect[10];

    // Input and set dimensions
    for (int i = 0; i < n; i++) {
        int l, w;
        cin >> l >> w;
        rect[i].setDimensions(l, w);
    }

    // Output total count
    cout << "Total number of rectangles: " << Rectangle::getCount() << endl;

    // Output areas
    for (int i = 0; i < n; i++) {
        cout << "Area of rectangle " << i + 1 << ": " << rect[i].getArea() << endl;
    }

    return 0;
}


// finding sum of elements of an array,pointer to an array 

#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int arr[10];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *ptr = arr;
    int sum = 0;

    for(int i = 0; i < n; i++)
    {
        sum = sum + *(ptr + i);
    }

    printf("%d", sum);

    return 0;
}







// strings

/*When to use <ctype.h>
Use it when your program involves:

1. Checking character type
Function	Purpose
isalpha(c)	checks if alphabet
isdigit(c)	checks if digit
isalnum(c)	alphabet or digit
islower(c)	lowercase letter
isupper(c)	uppercase letter
isspace(c)	space, tab, newline*/




// calculating total vowels,consonants,sp,digits 

#include <stdio.h>
#include <ctype.h>

int main() {
    char s[151];
    int v = 0, c = 0, d = 0, sp = 0;
    scanf("%s", s);
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            char t = tolower(s[i]);
            (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u') ? v++ : c++;
        } else if (isdigit(s[i])) d++;
        else sp++;
    }
    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nSpecial Characters: %d", v, c, d, sp);
    return 0;
}


// array of string is given, we have to find a word in the list of multiple words (matrix [i][j])

int main() {
    int n;

    scanf("%d", &n);

    char arr[10][101];

    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }

    char key[101];  

    scanf("%s", key);

    for (int i = 0; i < n; i++) {

        if (strcmp(arr[i], key) == 0) {
            printf("Found in row: %d", i + 1);
            return 0;
        }

    }

    printf("Not found");

    return 0;
}