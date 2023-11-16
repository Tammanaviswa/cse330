/*The Integer Knapsack Problem, specifically the 0/1 Knapsack Problem where duplicate items are forbidden, involves choosing items with given weights and values to maximize the total value without exceeding a given weight capacity. This problem is a classic example of a combinatorial optimization problem solved using dynamic programming.

The time complexity of the dynamic programming approach for the 0/1 Knapsack Problem is \(O(N \times W)\), where \(N\) is the number of items and \(W\) is the maximum weight capacity. The space complexity is also \(O(N \times W)\) due to the use of a two-dimensional array.
f
Here's how you can implement this in C++:

1. **Include Necessary Headers:** Use `<iostream>` and `<vector>`.
2. **Read User Input:** Get the number of items, their weights and values, and the maximum weight capacity.
3. **Dynamic Programming Solution:**
   - Create a two-dimensional array `dp` to store the maximum value at each weight capacity for each item.
   - Fill the array based on whether to include or exclude each item.
4. **Return the Maximum Value:** The maximum value for the given weight capacity is found in the bottom-right corner of the `dp` array.

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val) {
    int N = wt.size();
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;
    cout << "Enter the number of items: ";
    cin >> N;

    vector<int> wt(N), val(N);
    for (int i = 0; i < N; i++) {
        cout << "Enter weight and value of item " << i + 1 << ": ";
        cin >> wt[i] >> val[i];
    }

    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    cout << "Maximum value in knapsack = " << knapsack(W, wt, val) << endl;
    return 0;
}
/*
```

In this code:
- `knapsack` function implements the dynamic programming solution.
- A 2D vector `dp` is used to keep track of the maximum value that can be achieved with each item at each weight capacity.
- The `main` function handles user input for the items' weights and values and the maximum weight capacity, and then it calls `knapsack` to compute and display the result.
*/
