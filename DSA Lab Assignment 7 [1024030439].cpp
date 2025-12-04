// #include <iostream>
// #include <climits>
// using namespace std;

// // BUBBLE SORT
// void bubbleSort(int arr[], int n) {
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<n-1-i;j++){
//             if(arr[j] > arr[j+1]){
//                 swap(arr[j], arr[j+1]);
//             }
//         }
//     }
// }

// // INSERTION SORT
// void insertionSort(int arr[], int n) {
//     for(int i=1;i<n;i++){
//         int j = i;
//         while(j>=1 && arr[j] < arr[j-1]){
//             swap(arr[j], arr[j-1]);
//             j--;
//         }
//     }
// }

// // SELECTION SORT
// void selectionSort(int arr[], int n) {
//     for(int i=0;i<n-1;i++){
//         int minVal = INT_MAX;
//         int minIdx = -1;

//         for(int j=i;j<n;j++){
//             if(arr[j] < minVal){
//                 minVal = arr[j];
//                 minIdx = j;
//             }
//         }
//         swap(arr[i], arr[minIdx]);
//     }
// }

// // MERGE SORT
// void mergeArr(int arr[], int left, int mid, int right) {
//     int n1 = mid-left+1;
//     int n2 = right-mid;

//     int a[n1], b[n2];
//     for(int i=0;i<n1;i++) a[i] = arr[left + i];
//     for(int i=0;i<n2;i++) b[i] = arr[mid+1 + i];

//     int i=0, j=0, k=left;

//     while(i<n1 && j<n2){
//         if(a[i] <= b[j]) arr[k++] = a[i++];
//         else arr[k++] = b[j++];
//     }

//     while(i<n1) arr[k++] = a[i++];
//     while(j<n2) arr[k++] = b[j++];
// }

// void mergeSort(int arr[], int left, int right) {
//     if(left < right){
//         int mid = (left+right)/2;
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid+1, right);
//         mergeArr(arr, left, mid, right);
//     }
// }


// // QUICK SORT
// int partitionArray(int arr[], int low, int high){
//     int pivot = arr[high];
//     int i = low - 1;

//     for(int j=low; j<high; j++){
//         if(arr[j] < pivot){
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }

//     swap(arr[i+1], arr[high]);
//     return i+1;
// }

// void quickSort(int arr[], int low, int high){
//     if(low < high){
//         int p = partitionArray(arr, low, high);
//         quickSort(arr, low, p-1);
//         quickSort(arr, p+1, high);
//     }
// }



// // Display Array

// void display(int arr[], int n){
//     for(int i=0;i<n;i++) cout << arr[i] << " ";
//     cout << endl;
// }


// int main() {
//     int n, choice;

//     cout << "Enter number of elements: ";
//     cin >> n;

//     int arr[n];
//     cout << "Enter " << n << " elements: ";
//     for(int i=0;i<n;i++) cin >> arr[i];

//     cout << "\nChoose Sorting Method:\n";
//     cout << "1. Bubble Sort\n";
//     cout << "2. Insertion Sort\n";
//     cout << "3. Selection Sort\n";
//     cout << "4. Merge Sort\n";
//     cout << "5. Quick Sort\n";
//     cout << "6. Special Selection Sort (Min-Left Max-Right)\n";
//     cout << "Enter choice: ";
//     cin >> choice;

//     switch(choice){
//         case 1: bubbleSort(arr, n); break;
//         case 2: insertionSort(arr, n); break;
//         case 3: selectionSort(arr, n); break;
//         case 4: mergeSort(arr, 0, n-1); break;
//         case 5: quickSort(arr, 0, n-1); break;
//         case 6: specialSelectionSort(arr, n); break;
//         default: cout << "Invalid choice."; return 0;
//     }

//     cout << "\nSorted Array: ";
//     display(arr, n);

//     return 0;
// }
