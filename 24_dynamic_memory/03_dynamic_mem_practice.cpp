
 #include <iostream>

 using namespace std;

 int main(){

    // int *array1 = nullptr;  OR USE
    // int* array1 = nullptr;    //both will work
    
    int size;
    cout<<"enter the size you want for the array : ";
    cin>>size;

    int *array1 = new int[size] ; 
    


    for(int i=0;i<size;i++){

        cout<<"enter the element : "<<"# "<<i+1<<endl;
        cin>>array1[i];
        // cin >> *(array1 + i);


        
    }
    cout<<"[ ";
    for(int j=0;j<size;j++){

        cout<<array1[j]<<" ";
        
    }
    cout<<"]";

    delete []array1;



    return 0;
 }