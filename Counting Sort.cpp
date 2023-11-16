/*
Counting Sort is an integer sorting algorithm that operates by counting the number of objects that have each distinct key value. It is efficient when the range of input data is not significantly greater than the number of objects to be sorted. Counting Sort is not a comparison-based sorting algorithm and can perform at \(O(n)\) time complexity, where \(n\) is the number of elements in the input array.

Here's an implementation of Counting Sort in C++:

1. **Include Necessary Headers:** Use `<iostream>`, `<vector>`.
2. **Read User Input:** Get the array elements from the user.
3. **Counting Sort Algorithm:**
   - Find the maximum value in the array to determine the size of the counting array.
   - Implement the counting sort algorithm.
4. **Print the Sorted Array:**

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSort(vector<int>& arr) {
    int maxElement = *max_element(arr.begin(), arr.end());
    vector<int> count(maxElement + 1, 0);

    // Count the frequency of each element
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i]]++;
    }

    // Sort the array
    int index = 0;
    for (int i = 0; i <= maxElement; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
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

    countingSort(arr);

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
- The `countingSort` function counts the occurrences of each element and then places them in the sorted order.
- The `main` function handles user input for the array elements, calls the `countingSort` function to sort the array, and then prints the sorted array. 

Keep in mind that Counting Sort works well when the range of the input data (the difference between the maximum and minimum elements) is not significantly larger than the number of elements. If the range is very large, Counting Sort can become inefficient in terms of space.
*/
