#include <iostream>
using namespace std;

// Partition Function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick Sort Function
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

// Binary Search Function
bool binarySearch(int arr[], int n, int key)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return true;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}

int main()
{
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Sort the array
    quickSort(arr, 0, n - 1);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--)
    {
        int key;
        cout << "Enter element to search: ";
        cin >> key;

        if (binarySearch(arr, n, key))
            cout << "Found" << endl;
        else
            cout << "Not Found" << endl;
    }

    return 0;
}