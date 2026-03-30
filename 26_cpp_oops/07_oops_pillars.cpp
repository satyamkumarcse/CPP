/*
1 - encapsulation 
2 - abstraction 
3 - inheritance 
4 - polymorphism 

are called as 4 pillars of oops.


1) encapsulation 

encapsulation is wrapping up of data member/properties/attribute and member function in a single unit called as class

properties + member function = class

concept of encapsulation helps in data hiding process
basically any information that is sensitive can be declared as private, that info will not be able to accessed outisde the class
*/


class Bankaccount{

private : 
    double balance;  //data hiding 
    string password;

public: 

    string accountid;
    string username;
    
}

