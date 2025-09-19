#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int distinctCount = 0;
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = i+1; j < n; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) {
            distinctCount++;
        }
    }
    cout << "Total distinct elements: " << distinctCount << endl;
    return 0;
}
