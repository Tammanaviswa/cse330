/*
The tiling problem is a classic example of a problem that can be solved using dynamic programming. In one common version of this problem, you are asked to find the number of ways to cover a 2xN board with 2x1 tiles. This is similar to the Fibonacci sequence, as the solution for a board of length N depends on the solutions for lengths N-1 and N-2.

Here's a C++ implementation for the tiling problem:

1. **Include Necessary Headers:** Use `<iostream>` for input/output operations.
2. **Read User Input:** Get the length of the board from the user.
3. **Dynamic Programming Solution:**
   - Use an array to store the number of ways to tile boards of smaller lengths.
   - The number of ways to tile a board of length N is the sum of the ways to tile a board of length N-1 (adding a vertical tile) and N-2 (adding two horizontal tiles).
4. **Return the Result:** Print the total number of ways to tile the board of the given length.

The time complexity of this dynamic programming solution is O(N), and the space complexity is also O(N).

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>

using namespace std;

int countWays(int N) {
    vector<int> dp(N + 1, 0);
    dp[1] = 1; // only one way to place a 2x1 tile on a 2x1 board
    dp[2] = 2; // two ways to place 2x1 tiles on a 2x2 board

    for (int i = 3; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[N];
}

int main() {
    int N;
    cout << "Enter the length of the board: ";
    cin >> N;

    cout << "Number of ways to tile a 2x" << N << " board: " << countWays(N) << endl;
    return 0;
}
/*
```

In this code:
- `countWays` function calculates the number of ways to tile the board using dynamic programming.
- An array `dp` is used to store the number of ways to tile boards of lengths up to `N`.
- The `main` function takes the length of the board from the user and calls `countWays` to find and print the result.
*/
