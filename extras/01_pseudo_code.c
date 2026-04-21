// binary search tree - inserting ele



struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* insert(struct node* root, int element) {

    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = element;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        return newnode;
    }

    struct node* currentnode = root;
    struct node* parentnode = NULL;

    while (currentnode != NULL) {
        

        if (element < currentnode->data) {
            parentnode = currentnode;
            currentnode = currentnode->left;
        } else {
            parentnode = currentnode;
            currentnode = currentnode->right;
        }
    }

    if (element < parentnode->data) {
        parentnode->left = newnode;
    } else {
        parentnode->right = newnode;
    }

    return root;
}


// binary search tree or binary tree - deleting ele 

struct node {
    int data;
    struct node *left;
    struct node *right;
};



struct node* deleteNode(struct node* root, int key) {

    if (root == NULL)
        return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {

        // Case 1 & 2: 0 or 1 child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: 2 children
        struct node* temp = root->right;   // finding inorder successor

        while (temp->left != NULL) {
            temp = temp->left;
        }

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


// searching

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* search(struct node* root, int key)
{
    struct node* current = root;

    while (current != NULL)
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

    return NULL;
}


 
// insertion in avl (recursion is used) 

struct node* insert(struct node* node,int ele){


    if(node==NULL){return newnode(ele);}

    if(ele<node->data){
        node->left = insert(node->left,ele);

    }
    else if(ele>node->data){
        node->right = insert(node->right,ele)
    }
    else{
        return node;
    }

    node->height = max(height(node->left),height(node->right)) + 1;

    int bf = balancefactor(node);

    //rr 

    if(bf>1 && ele<node->left->data){

        return rightrotate(node);

    }

    //ll

    if(bf<-1 && ele>node->right->data){

        return leftrotate(node);

    }

    //lr 

    if(bf>1 && ele>node->left->data){

        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    //rl

    if(bf<-1 && ele<node->right->data){

        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;

    
}






// heap sort algorithm : array implementation

Algorithm HeapSort(a, n)
// sort array in ascending order 
{
    // ===== BUILD MAX HEAP =====
    for (i = n / 2; i >= 1; i--)   // start from last non-leaf node and go upwards
    {
        item = a[i];               // store current root value
        j = 2 * i;                 // initialize left child index 

        while (j <= n)             // continue while child exists
        {
            // choose larger child between left and right
            if ((j < n) && (a[j] < a[j + 1]))
            {
                j = j + 1;         // move to right child if it is larger
            }

            // check if heap property is satisfied
            if (item >= a[j])
            {
                break;             // stop if parent is already larger
            }

            // move larger child up to parent position
            a[j / 2] = a[j];

            // move down to next level in heap
            j = 2 * j;
        }

        // place original item in its correct position
        a[j / 2] = item;
    }

    // ===== HEAP SORT =====
    for (i = n; i >= 2; i--)       // repeat for all elements except first
    {
        // swap maximum element (root) with last element 
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;               // now max element is fixed at position i

        // ===== ADJUST =====
        item = a[1];               // take new root element 
        j = 2;                     // start with left child of root

        while (j <= (i - 1))       // work only on reduced heap
        {
            // choose larger child
            if ((j < (i - 1)) && (a[j] < a[j + 1]))
            {
                j = j + 1;         // move to right child if larger
            }

            // check if heap property is satisfied
            if (item >= a[j])
            {
                break;             // stop if correct position found
            }

            // move larger child up
            a[j / 2] = a[j];

            // move down further in heap
            j = 2 * j;
        }

        // place root element in its correct position
        a[j / 2] = item;
    }
}



// algorithm to find kth smallest ele 

Algorithm Inorder(node)
{
    if node == NULL then
        return

    Inorder(node->left)

    print node->data

    Inorder(node->right)
}

Algorithm KthSmallest(root, k)
{
    count = 0

    function inorder(node)
    {
        if node == NULL then
            return

        inorder(node->left)

        count = count + 1

        if count == k then
        {
            print node->data
            return
        }

        inorder(node->right)
    }

    inorder(root)
}





// deleting maximum ele from the heap 

Algorithm DelMax(a, n, x)
// delete maximum element from heap and store in x
// n is updated

{
    if (n == 0)
    {
        print "heap is empty"
        return false 
    }

    x = a[1]              // maximum element (root)

    a[1] = a[n]           // move last element to root 
    n = n - 1             // reduce heap size

    item = a[1]
    j = 2                 // left child

    while (j <= n)
    {
        // select larger child
        if (j < n && a[j] < a[j + 1])
        {
            j = j + 1
        }

        // correct position found
        if (item >= a[j])
        {
            break
        }

        a[j / 2] = a[j]   // move child up
        j = 2 * j         // move down
    }

    a[j / 2] = item       // place item correctly

    return true
}


// BACKTRACKING 



// steps in backtracking

// 1) make a decision : 
// 2) check for constrainsts :
// 3) if decision is feasable : continue with the option and make further decision from that point 
// 4) if not feasable : backtrack to previous decision point and take another option 
// repeat steps 1-4,until all options are explored or you get to a final solution

// ADVANTAGES OF BACKTRACKING  

// its a recursive algo,which considers and explores all the paths ,which makes it a reliable algo to find optimal solution 
// it does not require any problem specific knowledge ,it can be used on variety of problems
// its simple and easy to implement especially in all the recursive programming languages like c,c++,python






// n queens : place function  

bool place(int x[], int k, int i)
{
    for (int j = 1; j < k; j++)
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

// nqueens function

void nQueens(int x[], int k, int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (place(x, k, i))
        {
            x[k] = i;

            if (k == n)
                print(x);   // solution found
            else
                nQueens(x, k + 1, n);
        }
    }
}








for(int i=n/2;i>=1;i--){

    item=a[i];   //storing the current root value 
    j=2*i;

    while(j<=n){

        if(j<n && a[j]<a[j+1]){

            j++;
        }

        if(item>=a[j]){break;}
        
        a[j/2]=a[j];
        j=2*j;


    }

    a[j/2]=item;

}


for(int i=n;i>=2;i--){  

    int temp = a[i];
    a[i]=a[1];
    a[1]=temp;

    item=a[1];
    j=2;

    
    while(j<=i-1){

        if(j<i-1 && a[j]<a[j+1]){

            j++;
        }

        if(item>=a[j]){break;}
        
        a[j/2]=a[j];
        j=2*j;


    }

    a[j/2]=item;

}


// ordering matrix 


// When two matrices of size m*n and n*p when multiplied, they 
// generate a matrix of size m*p and the number of multiplications 
// performed is m*n*p


// You are given a chain of matrices.
// You can multiply them in different orders (parenthesization).
// Result matrix stays same, but cost (number of multiplications) changes.
// Goal

// Find the order of multiplication that gives minimum scalar multiplications.

// Key idea
// If matrices are:
// A1 (p0×p1), A2 (p1×p2), A3 (p2×p3) ...
// Cost of multiplying:
// (m×n) × (n×p) = m*n*p
// Why DP is used
// Many subproblems repeat
// We store minimum cost for multiplying subchains





// huffman coding 


Here is the **theory in simple, exam-ready form**:

---

# **Huffman Coding – Theory**

Huffman Coding is a **lossless data compression algorithm** used to reduce the size of data without losing any information.

---

## **Basic Idea**

* Characters that appear **more frequently** are assigned **shorter codes**
* Characters that appear **less frequently** are assigned **longer codes**

This reduces the overall number of bits required.

---

## **Greedy Approach**

Huffman coding uses a **greedy strategy**:

* At each step, combine the **two least frequent characters**
* Repeat until a single tree is formed

---

## **How it Works**

1. Start with all characters and their frequencies
2. Pick two characters with **minimum frequency**
3. Combine them into a new node (sum of frequencies)
4. Repeat until only one node remains (root)
5. Generate codes:

   * Left edge → `0`
   * Right edge → `1`

---

## **Prefix Property (Important)**

* Huffman codes are **prefix codes**
* This means:

  > No code is a prefix of another code

### **Why important?**

* Ensures **no ambiguity** during decoding
* Example:

  * If `A = 0`, then no other code can start with `0`

---

## **Key Features**

* Lossless compression
* Variable-length encoding
* Uses binary tree (Huffman tree)
* Efficient for data with uneven frequency distribution

---

## **One-line definition (exam)**

> Huffman coding is a greedy algorithm that assigns variable-length prefix codes to characters based on their frequencies to achieve lossless data compression.

---

## **Simple intuition**

> Frequent characters → short codes
> Rare characters → long codes

---

If you want, I can show a **step-by-step example with tree construction**, which is usually asked in exams.






// circular queue : queue follows FIFO priciple 

// enqueue   o(1)

void enqueue(int ele){

    if(front%max==(rear+1)%max){
        printf("queue is full");
        return;
    }

    if(front==-1){front=0;}

    rear=(rear+1)%max;
    queue[rear]=ele;

}


// dequeue    o(1)

int dequeue(){

    if(front==-1){
        printf("queue is empty");
        return -1;
    }

    int ele = queue[front];
    front=(front+1)%max;
    return ele;

}


// display    o(n)

void display(){

    if(front==-1){
        printf("no element to display");
    }

    int temp = front;

    while(temp<=rear){

        printf ("%d",Queue[temp]);
        temp=(temp+1)%max;
    
    }


}


// drawbacks on linear queue 

/*False Overflow (Major Issue)
In a linear queue, rear only moves forward
Even if front elements are removed, freed space is not reused*/



// stack 

// eg- undo operation : 

push(stack,max,top,value){

    if(top==max-1){
        printf("stack is full");
        return;
    }

    top+=1;
    stack[top]=value;
}

// redo operation : 

int pop(int stack[],top){

    if(top==-1){
        printf("stack is empty,cant pop");
    }

    int ele = stack[top];
    top-=1;
    return ele;

}


void display(int stack[],top){

    int temp = top;
    while(temp!=-1){
        printf("%d",stack[temp]);
        temp-=1;
    }
}


void search(int stack[],int max,int top,int target){

    if(top==-1){
        printf("stack is empty,cant search");
    }

    int temp = top;

    while(temp!=-1){
        if(stack[temp]==target){
            printf("target ele found");
            return;
        }
        temp-=1;
    }

    printf("ele not found");


}




countpairs(s1,s2,z){

    s3 = temp stack;
    int count=0;

    while s1 is not empty{

        x = pop(s1);

        while s2 is not empty{

            y = pop(s2);

            if(x+y<=z){
                count++;
            }
        }

        while s3 is not empty{

            push(s2,pop(s3))
        }
    }

    return count;
}




// inserting at end : circular linked list 


struct node* insert(struct node *head, char ch) {

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = ch;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return head;
    }

    struct node *temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;

    return head;
}


// displaying elements of circular linked list 


void display(struct node* head){

    if(head==NULL){
        return;
    }

    struct node* temp = head;


    do{

        printf("%d ",temp->data);
        temp=temp->next;

    }while(temp!=head);

    
}


bool ispalindrome(int arr[],int n){

    int i=0;
    int j=n-1;

    while(i<j){

        if(arr[i]!=arr[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;

}

void checkRotations(struct node *head) {

    if (head == NULL) {
        return;
    }

    int n = 0;
    struct node *temp = head;

    // count nodes
    do {
        n++;
        temp = temp->next;
    } while (temp != head);

    char arr[100];
    struct node *start = head;

    for (int i = 0; i < n; i++) {

        temp = start;

        // store characters for current rotation
        for (int j = 0; j < n; j++) {
            arr[j] = temp->data;
            temp = temp->next;
        }

        arr[n] = '\0';

        if (isPalindrome(arr, n)) {
            printf("%s is palindrome\n", arr);
        } else {
            printf("%s is not palindrome\n", arr);
        }

        start = start->next;
    }
}




for (int i = 1; i < n; i++) {    // o(n)
    for (int j = 1; j < n; j = j + i) {  // o(log n)
        // constant work
    }
}

// o(n log n)

// j increases by a value of i each time,number of iteration is n/i
// harmonic progression : t.c final = log(nlogn) 



for (int i = 1; i < n; i++) {    // o(n)
    for (int j = 1; j < n; j = j*2 ) {  // o(log n)
        // constant work
    }
}

// t.c total = o(nlogn)

/*Outer loop runs about n times
Inner loop doubles j each step:
1, 2, 4, 8, ..., up to n
iterations ≈ log₂(n)*/



for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k++) {
            // constant work
        }
    }
}


/*Total operations look like:

Inner body: n³
Inner loop control: n²(n + 1)
Middle loop control: n(n + 1)
Outer loop control: n + 1

So:

T(n) = n³ + n²(n + 1) + n(n + 1) + (n + 1)*/



// inserting at a particular position in circular linked list - all cases 
#include <stdio.h>
#include <stdlib.h>

 struct node{
    int data;
    struct node *next;
};


struct node* insert(node *head, int pos, int val) {

    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = val;

    // Case 1: Empty list
    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return head;
    }

    // Case 2: Insert at beginning (pos = 1)
    if (pos == 1) {
        node *temp = head;

        // go to last node
        while (temp->next != head) {
            temp = temp->next;
        }

        newnode->next = head;
        temp->next = newnode;

        return newnode; // new head
    }

    // Case 3: Insert at middle or end
    node *temp = head;
    int i = 1;

    // move to (pos-1)th node OR last node
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    return head;
}


// binary search using linked list 


// find middle between start and end
typedef struct node {
    int emp_id;
    struct node* next;
} node;

node* findmiddle(node* start, node* end) {
    node* slow = start;
    node* fast = start;

    while (fast != end && fast->next != end) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}


node* binarysearch(node* head, int key) {
    node* start = head;
    node* end = NULL;

    while (start != end) {
        node* middle = findmiddle(start, end);

        if (middle->emp_id == key) {
            return middle;
        }
        else if (middle->emp_id < key) {
            start = middle->next;
        }
        else {
            end = middle;
        }
    }

    return NULL;
}


// quick sort routine code

int partition(int arr[],int low,int high){

    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){

        if(i<=high && arr[i]<=pivot){
            i++;
        }

        if(j>=low && arr[j]>pivot){
            j--;
        }

        if(i<j){
            swap(arr[i],arr[j])
        }
    }

    swap(arr[j],arr[low]);

    return j;

}

void quicksort(int arr[],int low,int high){

    if(low<high){

        int p = partition(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);

    }
}



void bubblesort(int a[],int n){

    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-i-1;j++){

            if(arr[j]>arr[j+1]){

                swap(arr[j],arr[j+1]);

            }
        }
    }
}



void insertionsort(int arr[],int n){

    for(int i=1;i<n;i++){
        int j=i;

        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }

    }
}



void selectionsort(int arr[],int n){

    for(int i=0;i<n-1;i++){

        min = i;

        for(int j=i+1;j<n;j++){

            if(arr[j]<arr[min]){
                min = j;
            }
        }
    
        int temp = arr[min];
        arr[i] = arr[min];
        arr[min] = temp;

    }

}


int getmax(int arr[],int n){

    int temp == -9999;
    for(int i=0;i<n;i++){
        if(arr[i]>temp){
            temp=arr[i];
        }
    }

    return temp;

}


void radixsort(int arr[],int n){

    int m = getmax(arr,n); //finds maximum to know the number of digit

    for(int exp=1;m/exp>0;exp*=10){  //countsort is applied to nth digit of the element 
        countsort(arr,n,exp);

    }
}


// iterative insertion into a BST 


typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* insert(node* root, int key) {

    node* newnode = malloc(sizeof(node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;

    if (root == NULL) {
        return newnode;
    }

    node* parent = NULL;
    node* curr = root;

    while (curr != NULL) {
        parent = curr;

        if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (key < parent->data) {
        parent->left = newnode;
    } else {
        parent->right = newnode;
    }

    return root;
}

// searching a node in bst

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


// deleting a node from bst 

node* deletenode(node* root,int key){

    if(root==NULL){return NULL;}


    if(key<root->data){
        root->left = deletenode(root->left,key);

    }
    else if(key>root->data){
        root->right = deletenode(root->right,key);
    }
    else{

        if(root->left==NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }

        if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }

        node* temp = root->right;

        while(temp->left!=NULL){
            temp=temp->left;
        }

        root->data = temp->data;

        root->right = deletenode(root->right,temp->data);

    }

    return root;

}


// towers of hanoi : each recursive call is stored in the stack, after base case is hit, the function starts to return back the calls. the order is maintained (LIFO)


// prefix : right to left scan 
// postfix : left to right scan 


// merge sort pseudo code 

function mergesort(array){

    if(length of array<=1){
        return array;
    }

    middle = (len of array)/2;

    left array = mergesort(0,middle);  // sort first half of array
    right array = mergesort(middle+1,end);  //sort second half of array

    return merge(left arr,right arr);  // conqueor 

}


// total cost is = number of level * cost per level   {if cost is const}
 

// in case of linear probing there is primary clustering, so we use quadratic probing as it spreads keys better.


// quadratic probing does not gurantee finding free slot for all the elements if table size is non prime 
// it suffers from secondary clustering, key can get same probe sequence 

// limitation of seprate chaining : occupies high memory space due to pointers and linked list 
// worst case time complexity can degrade to o(n), if many keys hash to the same index 


// polynomial addition : 

typedef struct node
{
    int coeff;
    int exp;
    struct node *next;
} node;

node* create_node(int C, int E)
{
    node* newnode = malloc(sizeof(struct node));

    newnode->coeff = C;
    newnode->exp = E;
    newnode->next = NULL;

    return newnode;

}

node* addpoly(node *poly1, node *poly2)
{
    node *result;
    node *ptr;

    node* result = malloc(sizeof(struct node));
    result->next = NULL;

    ptr = result;

    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exp > poly2->exp)
        {
            ptr->next = create_node(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        }
        else if (poly1->exp < poly2->exp)
        {
            ptr->next = create_node(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        }
        else
        {
            ptr->next = create_node(poly1->coeff + poly2->coeff,
                                    poly1->exp);

            poly1 = poly1->next;
            poly2 = poly2->next;
            
        }

        ptr = ptr->next;
    }

    while (poly1 != NULL)
    {
        ptr->next = create_node(poly1->coeff, poly1->exp);
        poly1 = poly1->next;
        ptr = ptr->next;
    }

    while (poly2 != NULL)
    {
        ptr->next = create_node(poly2->coeff, poly2->exp);
        poly2 = poly2->next;
        ptr = ptr->next;
    }

    return result->next;
}


function kruskal(E,n){

    sort all edges E in increasing order of weight;
    
    initialise parent[i] = -1 for all vertices //seperate sets 

    for each edge (u,v) in E{

        find root of u and v;

        if(root(u)!=root(v)){

            include edge(u,v) in MST;
            union the two sets;

        }

        stop when n-1 edges are selected;
    }

    return MST cost;
}



function dijkstra(cost, n, source){

    initialize dist[i] = cost[source][i]
    mark all vertices as unvisited

    repeat (n-1 times){

        choose vertex u with minimum dist and not visited

        mark u as visited

        for each vertex v not visited{
            if(dist[v] > dist[u] + cost[u][v]){
                update dist[v]
            }
        }
    }

    return shortest distances
}