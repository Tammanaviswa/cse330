/*
Quick Sort is a widely used sorting algorithm that, like Merge Sort, follows the divide and conquer paradigm. Its basic idea is to select a 'pivot' element from the array and partition the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. 

The average and best-case time complexity of Quick Sort is \(O(n \log n)\), but its worst-case complexity is \(O(n^2)\). However, in practice, it's very efficient and often faster than Merge Sort, especially for large arrays. The space complexity is \(O(\log n)\) due to the recursive stack calls.

Here's an implementation of Quick Sort in C++:

1. **Include Necessary Headers:** Use `<iostream>` and `<vector>`.
2. **Read User Input:** Get the array elements from the user.
3. **Quick Sort Algorithm:**
   - Implement a `partition` function to find the pivot position and rearrange elements.
   - Implement the `quickSort` function that recursively sorts the sub-arrays.
4. **Print the Sorted Array:**

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
```

In this code:
- The `partition` function selects the last element as the pivot, places the pivot element at its correct position in the sorted array, and places all smaller elements to the left of the pivot and all larger elements to the right.
- The `quickSort` function recursively sorts the elements before and after the partition.
- The `main` function handles user input and output.
*/
