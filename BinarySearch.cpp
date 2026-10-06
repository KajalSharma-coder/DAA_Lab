#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];

    cout << "Enter sorted elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int index = binarySearch(arr, n, target);

    if(index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";

    return 0;
}