#include <iostream>
using namespace std;

int Missing(int arr[], int n) {
    int low = 0, high = n-2;   
    
    while (low <= high) {
        int mid = (low + high);
        
        if (arr[mid] == mid + 1) 
            low = mid + 1;  
        else 
            high = mid - 1;  
    }
    
    return low + 1; 
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; 
    int n = 6; 
    int ans = Missing(arr, n);
    cout << "Missing number: " << ans << endl;
    return 0;
}
