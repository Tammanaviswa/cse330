/*
Finding prime factors of a number by taking the square root is an efficient approach in C programming. Here's a basic outline of how you can implement this:

1. **Input the Number**: Start by getting the number from the user.

2. **Find Prime Factors**:
    - Iterate from 2 to the square root of the number. The reason for only going up to the square root is that a larger factor would have a corresponding smaller factor that would have already been identified.
    - During each iteration, check if the current number divides the input number.
    - If it does, then it is a prime factor. Keep dividing the input number by this factor as long as it is divisible. This step ensures that you are getting the prime factorization.
    - Once the number is no longer divisible by this factor, move to the next number.

3. **Check for Remaining Number**: After the loop, if the remaining number is greater than 1, then this number itself is a prime factor (since it is prime and greater than the square root of the original number).

Here is a sample C program to demonstrate this:

```c
*/
#include <iostream>
#include <cmath>

using namespace std;

void findPrimeFactors(int n) {
    // Divide by 2 until n becomes odd
    while (n % 2 == 0) {
        cout << 2 << " ";
        n /= 2;
    }

    // n must be odd at this point
    for (int i = 3; i <= sqrt(n); i += 2) {
        // While i divides n, print i and divide n
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        cout << n;
    }
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Prime factors of " << number << " are: ";
    findPrimeFactors(number);
    cout << endl;

    return 0;
}

//o(logn)
/*
```

This program will find and print the prime factors of the number entered by the user. 	The use of `sqrt(num)` in the loop condition significantly reduces the number of iterations, making it an efficient way to find prime factors.
*/
