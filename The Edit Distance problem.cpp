/*
The Edit Distance problem, also known as the Levenshtein Distance, measures the minimum number of operations (insertions, deletions, or substitutions) required to change one string into another. This problem can be efficiently solved using dynamic programming.

The time complexity of the dynamic programming approach for the Edit Distance problem is \(O(m \times n)\), where \(m\) and \(n\) are the lengths of the two strings. The space complexity is also \(O(m \times n)\) due to the use of a two-dimensional array.

Here's how you can implement the Edit Distance algorithm in C++:

1. **Include Necessary Headers:** Use `<iostream>` and `<vector>`.
2. **Read User Input:** Get the two strings from the user.
3. **Dynamic Programming Solution:**
   - Create a two-dimensional array `dp` to store the edit distance at each point.
   - Fill the array based on the operations (insertion, deletion, substitution).
4. **Return the Edit Distance:** The edit distance is the value in the bottom-right corner of the `dp` array.

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int editDistance(const string& str1, const string& str2) {
    int m = str1.length();
    int n = str2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;  // Min operations = j
            } else if (j == 0) {
                dp[i][j] = i;  // Min operations = i
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j],    // Delete
                                    dp[i][j - 1],    // Insert
                                    dp[i - 1][j - 1] // Replace
                                   });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    cout << "Edit Distance: " << editDistance(str1, str2) << endl;
    return 0;
}
/*
```

In this code:
- The `editDistance` function computes the minimum number of operations needed to convert `str1` into `str2`.
- A 2D vector `dp` is used to store the edit distances at each subproblem.
*/
- The `main` function takes two strings from the user and calls `editDistance` to calculate and display the result.
