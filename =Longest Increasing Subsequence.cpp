/*
The Longest Increasing Subsequence (LIS) problem is a classic problem in computer science. The goal is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

The LIS problem can be solved efficiently using dynamic programming. The time complexity of this approach is \(O(N^2)\), where \(N\) is the length of the input sequence. The space complexity is \(O(N)\), as it requires an array of the same size as the input to store the lengths of the longest increasing subsequences.

Here's how you can implement the LIS algorithm in C++:

1. **Include Necessary Headers:** Use `<iostream>` and `<vector>`.
2. **Read User Input:** Get the sequence from the user.
3. **Dynamic Programming Solution:**
   - Initialize an array `dp` to store the length of the longest increasing subsequence at each index.
   - For each element in the sequence, determine the length of the longest increasing subsequence that ends with that element.
4. **Find the Maximum Length:** After filling the `dp` array, the length of the longest increasing subsequence is the maximum value in `dp`.

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestIncreasingSubsequence(const vector<int>& sequence) {
    int n = sequence.size();
    vector<int> dp(n, 1); // Initialize all values to 1

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    vector<int> sequence(n);
    cout << "Enter the elements of the sequence: ";
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    cout << "Length of the longest increasing subsequence: "
         << longestIncreasingSubsequence(sequence) << endl;
    return 0;
}

/*
In this code:
- The `longestIncreasingSubsequence` function computes the length of the LIS.
- A vector `dp` is used to keep track of the longest increasing subsequence at each index.
- The `main` function takes the length and elements of the sequence from the user and calls `longestIncreasingSubsequence` to find and print the result.
*/
