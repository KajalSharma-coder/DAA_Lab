#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[],int low,int high){
  if(low<high){
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
}

int BinarySearch(int arr[], int tar, int n) {
    int st = 0;
    int end = n - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == tar)
            return mid;
        else if (arr[mid] < tar)
            st = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "\nSorted Array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int q;
    cout << "\nEnter number of queries: ";
    cin >> q;

    while(q--) {
        int key;
        cout << "Enter element to search: ";
        cin >> key;

        int index = BinarySearch(arr, key, n);

        if(index != -1)
            cout << key << " found at index " << index << endl;
        else
            cout << key << " not found" << endl;
    }

    return 0;
}