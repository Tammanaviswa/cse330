/*
The Segmented Sieve is an optimization of the Sieve of Eratosthenes for generating primes in a specific range, especially useful when the range is large. It divides the range into smaller segments and applies the sieve method to each segment, reducing memory usage.

Here's how you can implement the Segmented Sieve in C++:

1. **Include Necessary Headers:** Use `<iostream>`, `<vector>`, and `<cmath>`.
2. **User Input:** Get the lower and upper limits for the range from the user.
3. **Algorithm Steps:**
    - Use the regular Sieve of Eratosthenes to find all primes up to the square root of the upper limit.
    - Segment the range and apply the sieve to each segment.
4. **Print Prime Numbers:** Print the primes in the specified range.

The time complexity of the Segmented Sieve is similar to the Sieve of Eratosthenes, O(n log(log n)), for a single segment. However, it handles large ranges more efficiently in terms of space complexity.

Here's the implementation:

```cpp
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void simpleSieve(int limit, vector<int> &prime) {
    vector<bool> mark(limit + 1, true);
    for (int p = 2; p * p < limit; p++) {
        if (mark[p]) {
            for (int i = p * p; i < limit; i += p) {
                mark[i] = false;
            }
        }
    }
    for (int p = 2; p < limit; p++) {
        if (mark[p]) {
            prime.push_back(p);
            cout << p << " ";
        }
    }
}

void segmentedSieve(int low, int high) {
    int limit = floor(sqrt(high)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime);

    int n = high - low + 1;
    vector<bool> mark(n, true);

    for (int i = 0; i < prime.size(); i++) {
        int loLim = floor(low / prime[i]) * prime[i];
        if (loLim < low) {
            loLim += prime[i];
        }
        if(loLim == prime[i]) {
            loLim += prime[i];
        }

        for (int j = loLim; j <= high; j += prime[i]) {
            mark[j - low] = false;
        }
    }

    for (int i = low; i <= high; i++) {
        if (mark[i - low]) {
            cout << i << " ";
        }
    }
}

int main() {
    int low, high;
    cout << "Enter the lower and upper limit to find primes: ";
    cin >> low >> high;

    cout << "Prime numbers between " << low << " and " << high << " are: ";
    segmentedSieve(low, high);
    cout << endl;

    return 0;
}
/*
```

In this code:
- `simpleSieve` is used to find all prime numbers up to the square root of the upper limit.
- `segmentedSieve` uses the primes found by `simpleSieve` to mark non-primes in each segment of the range.
- The main function takes the range from the user and calls `segmentedSieve`.
*/
