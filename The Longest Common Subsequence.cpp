/*The Longest Common Subsequence (LCS) problem is another classic problem in computer science. It involves finding the longest subsequence common to two sequences (which may not be contiguous). The LCS problem can be solved using dynamic programming.

The time complexity of the LCS algorithm using dynamic programming is \(O(M \times N)\), where \(M\) and \(N\) are the lengths of the two sequences. The space complexity is also \(O(M \times N)\) due to the use of a two-dimensional array.

Here's how you can implement the LCS algorithm in C++:

1. **Include Necessary Headers:** Use `<iostream>` and `<vector>`.
2. **Read User Input:** Get the two sequences from the user.
3. **Dynamic Programming Solution:**
   - Create a two-dimensional array `dp` to store the lengths of LCS at different points.
   - Fill the array based on the comparison of elements in the two sequences.
4. **Return the LCS Length:** The length of the LCS is the value in the bottom-right corner of the `dp` array.

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int longestCommonSubsequence(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter the first sequence: ";
    cin >> str1;
    cout << "Enter the second sequence: ";
    cin >> str2;

    cout << "Length of the longest common subsequence: "
         << longestCommonSubsequence(str1, str2) << endl;
    return 0;
}
/*
```

In this code:
- The `longestCommonSubsequence` function computes the length of the LCS.
- A 2D vector `dp` is used to store the length of the LCS at each pair of indices.
- The `main` function takes two sequences from the user and calls `longestCommonSubsequence` to find and print the result.
*/
