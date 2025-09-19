#include<iostream>
using namespace std;
int linearTime(int arr[], int size){
    int diff = 1;
    int missN;
    for(int i=0;i<size-1;i++){
        if(diff != arr[i+1] - arr[i]){
             missN = arr[i] + diff;
        }
    }
    return missN;

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
    int ans = linearTime(arr, size);
    cout<<"missing number is: "<<endl;
    cout<<ans;
    return 0;
}