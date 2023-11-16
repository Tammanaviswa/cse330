/*
Merge Sort is a classic divide-and-conquer algorithm used for sorting an array or a list. It divides the input array into two halves, calls itself for the two halves, and then merges the sorted halves.

The overall time complexity of Merge Sort is \(O(n \log n)\), where \(n\) is the number of elements in the array. This is because the array is repeatedly divided in half (logarithmic component) and each level of division requires a linear amount of work to merge. The space complexity is \(O(n)\) due to the auxiliary space used for merging.

Here's how you can implement Merge Sort in C++:

1. **Include Necessary Headers:** Use `<iostream>` and `<vector>`.
2. **Read User Input:** Get the array elements from the user.
3. **Merge Sort Algorithm:**
   - Implement a `mergeSort` function that recursively divides the array and then merges the sorted halves.
   - Implement a `merge` function that merges two sorted halves.
4. **Print the Sorted Array:**

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return; // Returns recursively
    }
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
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

    mergeSort(arr, 0, n - 1);

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
- The `mergeSort` function recursively divides the array into halves and sorts them.
- The `merge` function merges two sorted halves into a single sorted array.
- The `main` function reads the user input for the array, calls the `mergeSort` function, and then prints the sorted array.
*/
