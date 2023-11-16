/*
The Sieve of Eratosthenes is an ancient algorithm used to find all prime numbers up to any given limit. It does so by iteratively marking the multiples of each prime number starting from 2. The C++ implementation of this algorithm can be written with user input and using the `using namespace std;` directive.

Here's how you can implement the Sieve of Eratosthenes:

1. **Include Necessary Headers:** Use `<iostream>` for input/output operations and `<vector>` for using the vector container.
2. **Read User Input:** Prompt the user to enter the upper limit for finding prime numbers.
3. **Sieve Algorithm:**
    - Create a boolean vector to track prime numbers.
    - Mark non-prime numbers as false.
    - Iterate through the numbers and mark their multiples as non-prime.
4. **Print Prime Numbers:** Print out the numbers that are still marked as prime.

The time complexity of the Sieve of Eratosthenes is O(n log(log n)), and its space complexity is O(n), where n is the upper limit up to which prime numbers are to be found.

Here's a sample implementation:

```cpp
*/
#include <iostream>
#include <vector>

using namespace std;

void sieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
}

int main() {
    int n;
    cout << "Enter the maximum number to find primes: ";
    cin >> n;

    cout << "Prime numbers up to " << n << " are: ";
    sieveOfEratosthenes(n);
    cout << endl;

    return 0;
}
/*
```

In this code:
- `sieveOfEratosthenes` function performs the sieve algorithm.
- A vector `prime` is used to track whether a number is prime or not.
- Non-prime numbers' indices in this vector are set to `false`.
- The main function gets user input for the upper limit and calls `sieveOfEratosthenes` to find and print all primes up to that limit.
*/
