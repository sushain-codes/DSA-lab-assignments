#include<iostream>
using namespace std;
void bubbleSort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    return;
}
int main(){
    int arr[100];
    int size;
    cout<<"enter size of array: "<<endl;
    cin>>size;
    cout<<"enter array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    bubbleSort(arr, size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}