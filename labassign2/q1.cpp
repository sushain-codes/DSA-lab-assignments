#include<iostream>
using namespace std;
int binarySearch(int arr[], int size, int target){
    int st = 0;
    int end = size - 1;
    while(st<end){
        int mid = st+(end-st)/2;
        if(target == arr[mid]){
            return mid;
        }
        else if(target < arr[mid]){
            end = mid - 1;
        }
        else{
            st = mid+1;
        }
    }
}
int main(){
    int arr[100];
    int size, target;
    cout<<"enter size of array: "<<endl;
    cin>>size;
    //input array
    cout<<"enter array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    //target
    cout<<"enter target: "<<endl;
    cin>>target;
    int ans = binarySearch(arr, size, target);
    cout<<"index is: "<<ans<<endl;  
    return 0;
}