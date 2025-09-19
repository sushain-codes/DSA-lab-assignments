#include<iostream>
using namespace std;
void reverseArray(int array[], int n){
    int st = 0;
    int end = n - 1;
    while(st<end){
        swap(array[st], array[end]);
        st++, end--;
    }
}
int main(){
    int arr[100];
    int size;
    cout<<"enter size: "<<endl;
    cin>>size;
    cout<<endl;
    cout<<"start typing the values of an array: "<<endl;
    for(int i = 0; i<size;i++){
        cin>>arr[i];
    }
      for(int i = 0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"reverse array is: "<<endl;
    reverseArray(arr, size);
       for(int i = 0; i<size;i++){
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}