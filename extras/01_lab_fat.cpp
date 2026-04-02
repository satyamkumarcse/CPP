
// stack - push,pop,display,search


#include <iostream> 
using namespace std;

void push(int value,int *stack,int max,int &top){

    if(top==max-1){

        cout<<"stack is full, cant push new elements!!"<<endl;
        return;

    }
    else{

        top++;

        stack[top] = value;

    }
}



int pop(int *stack,int &top){

    if(top==-1){

        cout<<"stack is empty, cant pop elements!!!\n"<<endl;
        return -1;

    }
    else{

        int x = stack[top];
        top--;
        return x;

    }


}


void display(int *stack,int top){

    int temp = top;

    if(temp==-1){

        cout<<"cant display stack is empty!\n"<<endl;
        return;

    }
    else{

        while(temp!=-1){

            cout<<stack[temp]<<" ";

            temp--;

        }
        cout<<endl;
    }

}

void search(int search,int *stack,int top){

    int temp = top;

    while(temp!=-1){

        if(stack[temp]==search){

            cout<<"element " <<search<<" was found"<<endl;
            return;


        }
        temp--;

        
    }

    

    cout<<"element was not found\n"<<endl;
}



int main(){

    int top = -1;
    int max = 100;

    int *stack = new int[max]; 

    if(!stack){

        cout<<"memory allocation failed\n"<<endl;
        return -1;
    }

    

    push(12,stack,max,top);
    push(24,stack,max,top);
    push(36,stack,max,top);
    push(48,stack,max,top);
    push(48,stack,max,top);

    cout<<"elements present in stack: ";
    display(stack,top);

    cout<<"element popped is: ";
    cout<<pop(stack,top)<<endl;
    cout<<"after poping ";
    display(stack,top);

    

    // cout<<"element present in stack are: ";
    // display(stack,top);

    

    search(12,stack,top);

    delete []stack;

    return 0;
}



// Q1


// stack - push, pop, display, search + remove largest

#include <iostream> 
using namespace std;

/*
Question 2: Write the program for STACK ADT with following questions.

(i) Insert 10, 15, 8, 13, 5, 40, 12, 75, 50 elements into the stack.
    Perform POP() the elements 75 and 50 from STACK A.
    After POP() from STACK display the remaining elements.

(ii) Write the code for Find and Remove the largest Element in a stack.
*/

void push(int value, int *stack, int max, int &top) {

    if (top == max - 1) {
        cout << "stack is full, cant push new elements!!" << endl;
        return;
    } else {
        top++;
        stack[top] = value;
    }
}

int pop(int *stack, int &top) {

    if (top == -1) {
        cout << "stack is empty, cant pop elements!!!\n" << endl;
        return -1;
    } else {
        int x = stack[top];
        top--;
        return x;
    }
}

void display(int *stack, int top) {

    int temp = top;

    if (temp == -1) {
        cout << "cant display stack is empty!\n" << endl;
        return;
    } else {
        while (temp != -1) {
            cout << stack[temp] << " ";
            temp--;
        }
        cout << endl;
    }
}

void search(int key, int *stack, int top) {

    int temp = top;

    while (temp != -1) {
        if (stack[temp] == key) {
            cout << "element " << key << " was found" << endl;
            return;
        }
        temp--;
    }

    cout << "element was not found\n" << endl;
}

// --------- Required Part (ii) ---------
void removeLargest(int *stack, int &top) {  // STRICT STACK principle is not followed here, only the largest ele is removed. (dont write in exam)

    if (top == -1) {
        cout << "stack is empty!\n";
        return;
    }

    int tempStack[100];
    int tempTop = -1;

    int maxVal = stack[top];

    // find max
    while (top != -1) {
        int val = pop(stack, top);

        if (val > maxVal) {
            maxVal = val;
        }

        tempTop++;
        tempStack[tempTop] = val;
    }

    // rebuild without one max element
    bool removed = false;

    while (tempTop != -1) {
        int val = tempStack[tempTop];
        tempTop--;

        if (val == maxVal && !removed) {
            removed = true;
            continue;
        }

        push(val, stack, 100, top);
    }

    cout << "largest element removed: " << maxVal << endl;
}


void removeLargest(int *stack, int &top) {

    if (top == -1) {
        cout << "Stack is empty!\n";
        return;
    }

    // Step 1: Find max (need to scan, so use temp variable index)
    int maxVal = stack[0];
    for (int i = 0; i <= top; i++) {
        if (stack[i] > maxVal) {
            maxVal = stack[i];
        }
    }

    // Step 2: Pop until max is found (strict removal)
    while (top != -1) {
        int val = pop(stack, top);

        if (val == maxVal) {
            // found max, stop here
            return;
        }
        // else: discard element permanently
    }
}



int main() {

    int max = 100;
    int stack[100];
    int top = -1;

    // (i) insert elements
    int arr[] = {10, 15, 8, 13, 5, 40, 12, 75, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        push(arr[i], stack, max, top);
    }

    cout << "Initial stack:\n";
    display(stack, top);

    // pop 50 and 75
    cout << "popped: " << pop(stack, top) << endl;
    cout << "popped: " << pop(stack, top) << endl;

    cout << "stack after popping:\n";
    display(stack, top);

    // (ii) remove largest
    removeLargest(stack, top);

    cout << "final stack:\n";
    display(stack, top);

    return 0;
}



// STACK USING DYNAMIC PROGRAMMING 
// MENU DRIVEN



#include <iostream>
#include <cstdlib>
using namespace std;

#define MAX_SIZE 5

int stack[MAX_SIZE];
int top=-1;


int isfull(){

    return top == MAX_SIZE -1;
}

int isempty(){

    return top == -1;
}

void push(int push_ele){

    if(isfull()){
        cout<<"stack is full you cant push the element : "<<push_ele<<endl;
    }
    else{
        top++;
        stack[top]=push_ele;
        cout<<"element "<<push_ele<<" has been pushed"<<endl;
    }
}

void pop(){

    if(isempty()){
        cout<<"the stack is empty cant pop elements"<<endl;
    }
    else{
        
        int x = stack[top];
        top--;

        cout<<"the element "<<x<<" has been popped from stack"<<endl;
    }

}

void display(){

    if(isempty()){
        cout<<"stack is empty, cant display"<<endl;

    }
    else{

        for(int i=top;i>=0;i--){

            cout<<stack[i]<<" ";
        }
        cout<<endl;
    }
}

void search(int search_ele){

    if(isempty()){
        cout<<"cant search in an empty stack"<<endl;
    }
    else{

        for(int i=top;i>=0;i--){
        if(stack[i]==search_ele){
            cout<<"the element "<<search_ele<<" is present in the stack"<<endl;
            return;
        }
        
    }
    cout<<"the element "<<search_ele<<" is not present in the stack"<<endl;
     

    }
    
}


int main(){

    int choice,push_ele,search_ele;

    while(true){

    cout<<"---------stack implementation program----------\n";
    cout<<"enter a choice:\n";
    cout<<"1 - Push\n";
    cout<<"2 - Pop\n";
    cout<<"3 - Display\n";
    cout<<"4 - Search\n";
    cout<<"5 - Exit\n";
    cin>>choice;


    
    switch(choice){
        
        case 1:
        cout<<"enter the element you want to push: ";
        cin>>push_ele;
        push(push_ele);
        break;

        case 2:
        pop();
        break;

        case 3:
         display();
         break;

         case 4:
         cout<<"enter an element you want to search: ";
         cin>>search_ele;
         search(search_ele);
         break;

         case 5:
         exit(0);
         break;

         default:
         cout<<"invalid input!!!\n";

    }


    }
    return 0;
}





// QUEUE - enqueue,dequeue,display,full/empty check 



#include <iostream>
using namespace std;

#define MAX 20

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int x) {

    if (isFull()) {
        cout << "Queue overflow" << endl;
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = x;
        cout << x << " inserted into queue" << endl;
    }
}

int dequeue() {

    if (isEmpty()) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    else {
        int val = queue[front];
        front++;
        cout << val << " removed from queue" << endl;
        return val;
    }
}

void display() {

    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int main() {

    int choice, value;

    while (true) {

        cout << "\n----- Queue Menu -----\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter element to insert: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice" << endl;
        }
    }

    return 0;
}




// Q2 

 
/*

Write a Queue Program in C to implement the queue data structure 
and display the queue using array.

Use the following elements:
(10, 25, 20, 50, 45, 75, 60, 80, 95, 40) for Enqueue.

Dequeue the elements:
(45, 75, 60, 80, 95, 40) and display the data.

In addition, count the number of elements in a queue before Dequeue and after Dequeue.
*/

   #include <iostream>
using namespace std;

#define MAX 20

int queue[MAX];
int front = -1;
int rear = -1;



int isFull() {
    return rear == MAX - 1;
}

int isEmpty() {
    return front == -1 || front > rear;
}

void enqueue(int x) {

    if (isFull()) {
        cout << "Queue overflow" << endl;
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = x;
        cout << x << " inserted into queue" << endl;
    }
}

int dequeue() {

    if (isEmpty()) {
        cout << "Queue underflow" << endl;
        return -1;
    }
    else {
        int val = queue[front];
        front++;
        cout << val << " removed from queue" << endl;
        return val;
    }
}

void display() {

    if (isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

int countElements() {
    if (isEmpty()) {
        return 0;
    }
    return rear - front + 1;
}

int main() {

    // Enqueue given elements
    int arr[] = {10, 25, 20, 50, 45, 75, 60, 80, 95, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Enqueue elements:\n";
    for (int i = 0; i < n; i++) {
        enqueue(arr[i]);
    }

    cout << "\nQueue after enqueue:\n";
    display();

    cout << "Number of elements before dequeue: " << countElements() << endl;

    // Dequeue 6 elements (45, 75, 60, 80, 95, 40 will be removed in FIFO order)
    cout << "\nDequeuing elements:\n";
    for (int i = 0; i < 6; i++) {
        dequeue();
    }

    cout << "\nQueue after dequeue:\n";
    display();

    cout << "Number of elements after dequeue: " << countElements() << endl;

    return 0;
}



// single linked list 

#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

// Insert at end
void insertEnd(int element) {

    node* newnode = new node;
    newnode->data = element;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newnode;
}

// Search element
void search(int key) {

    node* ptr = head;

    while (ptr != NULL) {
        if (ptr->data == key) {
            cout << "Element " << key << " found\n";
            return;
        }
        ptr = ptr->next;
    }

    cout << "Element " << key << " not found\n";
}

// Display
void display() {

    node* ptr = head;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

int main() {

    int arr[] = {100, 20, 35, 30, 45, 40, 50, 80, 10, 90, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insertEnd(arr[i]);
    }

    cout << "Linked List:\n";
    display();

    search(90);
    search(200);

    return 0;
}

// deleting first occurence of an ele in a singly LL (all cases of deletion) 

void deleteNode(int element) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node *ptr = head;
    node *prev = NULL;

    // if head needs to be deleted
    if (head->data == element) {
        head = head->next;
        delete ptr;
        cout << "Deleted: " << element << endl;
        return;
    }

    // search for element
    while (ptr != NULL && ptr->data != element) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Element not found\n";
        return;
    }

    prev->next = ptr->next;
    delete ptr;

    cout << "Deleted: " << element << endl;
}


// insering at begening 
void insertFirst(int element) {

    node *newnode = new node;
    newnode->data = element;

    newnode->next = head;
    head = newnode;
}

// inserting at middle, after a particular pos (1 based index)

/*

      Meaning	               Loop condition
Insert at position pos	         count < pos - 1
Insert after position pos	     count < pos

*/
void insertMiddle(int element, int pos) {

    node *newnode = new node;
    newnode->data = element;
    newnode->next = NULL;

    // insert at beginning
    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    node *ptr = head;
    int count = 1;

    // move to (pos-1)th node
    while (ptr != NULL && count < pos ) {
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL) {
        cout << "Invalid position\n";
        delete newnode;
        return;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
}


// inserting after an element "key"
void insertAfterElement(int element, int key) {

    node *newnode = new node;
    newnode->data = element;
    newnode->next = NULL;

    if (head == NULL) {
        cout << "List is empty\n";
        delete newnode;
        return;
    }

    node *ptr = head;

    // search for the given element (key)
    while (ptr != NULL && ptr->data != key) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        cout << "Element " << key << " not found\n";
        delete newnode;
        return;
    }

    // insert after that element
    newnode->next = ptr->next;
    ptr->next = newnode;
}

// double linked list 


/*
SET 2

Question 2:
Create the Double linked list with elements:
80, 20, 55, 70, 45, 40, 90, 80, 10, 12, 75

Display it.

Delete the elements 90 & 80 and display the result.
*/
#include <iostream>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
};

node *head = NULL;


// insert at end
void insertEnd(int element) {

    node *newnode = new node;
    newnode->data = element;
    newnode->prev = NULL;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    node *ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newnode;
    newnode->prev = ptr;
}


// 
#include <iostream>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
};

node *head = NULL;
// 



void deleteNode(int element) {

    if (head == NULL) {
        cout << "List is empty\n";
        return;
    }

    node *ptr = head;

    // traverse to find element
    while (ptr != NULL && ptr->data != element) {
        ptr = ptr->next;
    }

    // element not found
    if (ptr == NULL) {
        cout << "Data not found\n";
        return;
    }

    // case 1: deleting head
    if (ptr == head) {
        head = ptr->next;

        if (head != NULL) {
            head->prev = NULL;
        }

        delete ptr;
        cout << "Deleted: " << element << endl;
        return;
    }

    // case 2: middle or last node
    node *pptr = ptr->prev;
    node *nptr = ptr->next;

    // link previous node to next node
    pptr->next = nptr;

    // if not last node
    if (nptr != NULL) {
        nptr->prev = pptr;
    }

    delete ptr;
    cout << "Deleted: " << element << endl;
}



// display
void display() {

    node *ptr = head;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

int main() {

    int arr[] = {80, 20, 55, 70, 45, 40, 90, 80, 10, 12, 75};
    int n = sizeof(arr) / sizeof(arr[0]);

    // create list
    for (int i = 0; i < n; i++) {
        insertEnd(arr[i]);
    }

    cout << "Doubly Linked List:\n";
    display();

    // delete 90 and 80
    deleteNode(90);
    deleteNode(80);

    cout << "After deletion:\n";
    display();

    return 0;
}




#include <iostream>
using namespace std;

struct node {
    int data;
    node *prev;
    node *next;
};

node *head = NULL;

void insert(int element, int pos) {

    node *newnode = new node;
    newnode->data = element;
    newnode->prev = NULL;
    newnode->next = NULL;

    // case 1: empty list
    if (head == NULL) {
        head = newnode;
        return;
    }

    node *ptr = head;

    // case 2: insert at beginning (if pos matches head)
    if (head->data == pos) {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
        return;
    }

    // case 3: traverse to find pos
    while (ptr->next != NULL && ptr->data != pos) {
        ptr = ptr->next;
    }

    // case 4: insert after found node
    if (ptr->data == pos) {

        newnode->next = ptr->next;
        newnode->prev = ptr;

        if (ptr->next != NULL) {
            ptr->next->prev = newnode;
        }

        ptr->next = newnode;
    }
    else {
        // case 5: element not found
        cout << "Position element not found\n";
        delete newnode;  // avoid memory leak
    }
}  


// sorting 



// selection sort 
#include <bits/stdc++.h>
using namespace std;

void selectionsort(int arr[], int x) {

    for (int i = 0; i < x - 1; i++) {   // GOES TO ONLY SECOND LAST ELE

        int min = i;

        for (int j = i + 1; j < x; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main() {

    int arr[] = {13, 46, 24, 52, 20, 9};

    int x = sizeof(arr) / sizeof(arr[0]);

    selectionsort(arr, x);

    for (int i = 0; i < x; i++) {
        cout << arr[i] << " ";
    }
}




// insertion sort 


#include <bits/stdc++.h>
using namespace std;

void insertionsort(int arr[], int x) {

    int i, j;

    for (i = 0; i <= x - 1; i++) {

        j = i;

        while (j > 0 && arr[j - 1] > arr[j]) {

            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;

            j--;
        }
    }
}

int main() {

    int arr[] = {34, 54, 23, 77, 12, 46, 89, 33};

    int x = sizeof(arr) / sizeof(arr[0]);

    insertionsort(arr, x);

    for (int i = 0; i < x; i++) {
        cout << arr[i] << " ";
    }
}





// quick sort 

#include <bits/stdc++.h>
using namespace std;

int fxnpvt(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {

        while (i <= high - 1 && arr[i] <= pivot) {
            i++;
        }

        while (j >= low + 1 && arr[j] > pivot) {
            j--;
        }

        if (i < j) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    int temp = arr[j];
    arr[j] = arr[low];
    arr[low] = temp;

    return j;
}

void qs(int arr[], int low, int high) {

    if (low < high) {

        int pivot = fxnpvt(arr, low, high);

        qs(arr, low, pivot - 1);
        qs(arr, pivot + 1, high);
    }
}

int main() {

    int arr[] = {4, 6, 2, 5, 7, 9, 1, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    int low = 0;
    int high = n - 1;

    qs(arr, low, high);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}




// tree traversal,binary search tree and binary search  


// tree traversal on binary tree
#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

// Function to create a new node
node* newnode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
}

// Preorder Traversal
void printPreorder(node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Inorder Traversal
void printInorder(node* root) {
    if (root == nullptr) {
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Postorder Traversal
void printPostorder(node* root) {
    if (root == nullptr) {
        return;
    }

    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {

 
      node* root = newnode(10);
    root->left = newnode(5);
    root->right = newnode(12);
    root->left->left=newnode(2);
    root->left->right=newnode(6);
    root->right->left = newnode(11);
    root->right->right = newnode(15);


    cout << "Preorder: ";
    printPreorder(root);

    cout << "\nInorder: ";
    printInorder(root);

    cout << "\nPostorder: ";
    printPostorder(root);

    return 0;
}






// operations on BST 
#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

// create node
node* newNode(int val) {
    node* n = new node();
    n->data = val;
    n->left = nullptr;
    n->right = nullptr;
    return n;
}


// INSERT 
// node* insert(node* root, int val) {
//     if (root == nullptr)
//         return newNode(val);

//     if (val < root->data)
//         root->left = insert(root->left, val);
//     else
//         root->right = insert(root->right, val);

//     return root;

// }



node* insertIterative(node* root, int element)
{
    node* newnode = newNode(element);

    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    
        node* currentnode = root;
        node* parentnode = root;

        while (currentnode != NULL)
        {
            if (newnode->data < currentnode->data)
            {
                parentnode = currentnode;
                currentnode = currentnode->left;
            }
            else
            {
                parentnode = currentnode;
                currentnode = currentnode->right;
            }
        }

        if (parentnode->data < newnode->data)
        {
            parentnode->right = newnode;
        }
        else
        {
            parentnode->left = newnode;
        }
    

    return root;
}

node* search(node* root, int key)
{
    node* current = root;

    while (current != nullptr)
    {
        if (key == current->data)
        {
            return current;
        }
        else if (key < current->data)
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }

    return nullptr;
}


// DELETE
node* deleteNode(node* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        // Case 1 & 2: 0 or 1 child
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: 2 children
        node* temp = root->right;                                                                                   

        while (temp->left != nullptr) {
            temp = temp->left;
        }

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);

    }

    return root;
}


// INORDER
void inorder(node* root) {

    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// PREORDER
void preorder(node* root) {

    if (root == nullptr) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// POSTORDER
void postorder(node* root) {

    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    node* root = nullptr;

    // insert values
    root = insertIterative(root, 50);
    root = insertIterative(root, 30);
    root = insertIterative(root, 70);
    root = insertIterative(root, 20);
    root = insertIterative(root, 40);
    root = insertIterative(root, 60);
    root = insertIterative(root, 80);


    int key = 40;

node* result = search(root, key);

if (result != nullptr)
{
    cout << "\nElement " << key << " found\n";
}
else
{
    cout << "\nElement " << key << " not found\n";
}



    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    // delete node
    root = deleteNode(root, 50);

    cout << "\n\nAfter deleting 50:\n";

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    return 0;
}








// general tree
// count total nodes or total nodes in left subtree 

// total nodes
int countNodes(node* root) {

    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// left subtree
void countLeftSubtree(node* root) {

    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }

    int count = countNodes(root->left);
    cout << "Elements in left subtree: " << count << endl;
}


// minimum ele in a tree 
void findMin(node* root) {

    if (root == NULL) {
        cout << "Tree is empty\n";
        return;
    }

    while (root->left != NULL) {
        root = root->left;
    }

    cout << "Minimum element: " << root->data << endl;
}




// binary search tree - question

/*
Question:

Construct a Binary Search Tree (BST) using iterative insertion 
for the given set of elements:
60, 25, 72, 15, 30, 68, 101, 13, 18, 47, 70, 34.

Then perform the following operations:

1. Display the two minimum elements from the BST.
2. Display the two maximum elements from the BST.
3. Find and display the parent node of a given element (e.g., 68).

Note:
- Use iterative approach for insertion (no recursion).
- Use appropriate traversal logic to determine minimum and maximum elements.
*/




// BST combined program (iterative insertion)
#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

node* newNode(int val) {
    node* temp = new node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// iterative insert (your logic)
node* insertIterative(node* root, int element)
{
    node* newnode = newNode(element);

    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    
    node* currentnode = root;
    node* parentnode = root;

    while (currentnode != NULL)
    {
        if (newnode->data < currentnode->data)
        {
            parentnode = currentnode;
            currentnode = currentnode->left;
        }
        else
        {
            parentnode = currentnode;
            currentnode = currentnode->right;
        }
    }

    if (parentnode->data < newnode->data)
    {
        parentnode->right = newnode;
    }
    else
    {
        parentnode->left = newnode;
    }

    return root;
}

// find 2 minimum elements
void findTwoMin(node* root) {

    if (root == NULL) return;

    node* ptr = root;

    while (ptr->left != NULL) {
        ptr = ptr->left;
    }

    int min1 = ptr->data;

    if (ptr->right != NULL) {
        ptr = ptr->right;
        while (ptr->left != NULL) {
            ptr = ptr->left;
        }
        cout << "Two minimum elements: " << min1 << " " << ptr->data << endl;
    }
}

// find 2 maximum elements
void findTwoMax(node* root) {

    if (root == NULL) return;

    node* ptr = root;

    while (ptr->right != NULL) {
        ptr = ptr->right;
    }

    int max1 = ptr->data;

    if (ptr->left != NULL) {
        ptr = ptr->left;
        while (ptr->right != NULL) {
            ptr = ptr->right;
        }
        cout << "Two maximum elements: " << max1 << " " << ptr->data << endl;
    }
}

// find parent of a node
void findParent(node* root, int key) {

    if (root == NULL || root->data == key) {
        cout << "No parent (root or not found)\n";
        return;
    }

    node* parent = NULL;
    node* ptr = root;

    while (ptr != NULL && ptr->data != key) {

        parent = ptr;

        if (key < ptr->data) {
            ptr = ptr->left;
        } else {
            ptr = ptr->right;
        }
    }

    if (ptr == NULL) {
        cout << "Element not found\n";
    } else {
        cout << "Parent of " << key << " is: " << parent->data << endl;
    }
}

int main() {

    int arr[] = {60, 25, 72, 15, 30, 68, 101, 13, 18, 47, 70, 34};
    int n = sizeof(arr) / sizeof(arr[0]);

    node* root = NULL;

    // iterative BST creation
    for (int i = 0; i < n; i++) {
        root = insertIterative(root, arr[i]);
    }

    findTwoMin(root);
    findTwoMax(root);
    findParent(root, 68);

    return 0;
}
