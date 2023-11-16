/*
The Balanced Partition problem is about dividing a set of numbers into two subsets such that the difference of their sums is minimized. This problem can be approached as a variation of the 0/1 Knapsack problem, specifically aiming to find a subset with a sum closest to half of the total sum of all numbers.

This approach has a time complexity of \( O(n \times \text{sum}) \), where \( n \) is the number of elements and \( \text{sum} \) is the total sum of all elements. The space complexity is also \( O(n \times \text{sum}) \) due to the use of a two-dimensional array.

Here's how you can implement the Balanced Partition problem in C++:

1. **Include Necessary Headers:** Use `<iostream>`, `<vector>`, and `<numeric>` for `accumulate`.
2. **Read User Input:** Get the set of numbers from the user.
3. **Dynamic Programming Solution:**
   - Calculate the total sum of all numbers.
   - Create a two-dimensional boolean array to store whether a sum is achievable with a subset of the numbers.
   - Fill the array to find the subset with a sum closest to half of the total sum.
4. **Calculate and Return the Minimum Difference:**

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int findMinDifference(vector<int>& nums) {
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(totalSum / 2 + 1, false));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= totalSum / 2; j++) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int j = totalSum / 2; j >= 0; j--) {
        if (dp[n][j]) {
            return totalSum - 2 * j;
        }
    }

    return totalSum;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Minimum difference: " << findMinDifference(nums) << endl;
    return 0;
}
/*
```

In this code:
- `findMinDifference` function calculates the minimum difference between the sums of two subsets.
- A 2D vector `dp` is used to determine whether a certain sum can be achieved with a subset of the numbers.
- The `main` function takes the set of numbers from the user and calls `findMinDifference` to compute and display the result. */
