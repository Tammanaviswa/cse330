/* The Fermat's factorization method is based on the representation of an odd integer as the difference of two squares. 
That is, \( n = a^2 - b^2 \) where \( n \) is the number to be factored. This method works particularly well when 
\( n \) is a product of two primes that are close to each other.

Here's how you can implement Fermat's factorization method in C, along with getting user input:

1. **Input the Number**: Get the number from the user.

2. **Fermat's Factorization**:
    - Start with a value of `a` that is the ceiling of the square root of `n`. 
    - Compute `b^2 = a^2 - n`.
    - Check if `b^2` is a perfect square. If it is, then `a` and `b` are such 
	that `n = a^2 - b^2 = (a + b)(a - b)`. The factors of `n` are `a + b` and `a - b`.
    - Increment `a` and repeat until a factor is found.

Here is the C program for this:

```c
*/


#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectSquare(int n) {
    int sqrt_n = static_cast<int>(sqrt(n));
    return (sqrt_n * sqrt_n == n);
}

void fermatFactorization(int n) {
    int a = static_cast<int>(ceil(sqrt(n)));
    int b2 = a * a - n;
    int b = static_cast<int>(round(sqrt(b2)));

    while (b2 != b * b) {
        a = a + 1;
        b2 = a * a - n;
        b = static_cast<int>(round(sqrt(b2)));
    }

    cout << "Factors are " << a + b << " and " << a - b << endl;
}

int main() {
    int n;
    cout << "Enter an odd number to factor: ";
    cin >> n;

    if (n % 2 == 0) {
        cout << "Number must be odd." << endl;
    } else {
        fermatFactorization(n);
    }

    return 0;
}

/*
```

### Time Complexity

The time complexity of Fermat's factorization method is more challenging to analyze compared to other methods like trial division. The efficiency of the method depends heavily on the difference between the two prime factors of `n`. If the number `n` is a product of two primes that are relatively close to each other, Fermat's method can be very efficient, potentially even more efficient than trial division.

However, if the factors are far apart, the method can become much slower. In the worst case, the time complexity can be O(n^(1/4)), which is less efficient than the trial division method up to the square root of `n`. This worst-case scenario occurs when `n` is a product of two primes that are far apart.

In practice, Fermat's factorization method is often used as a part of a larger factorization algorithm, where it can quickly handle cases where the primes are close together, leaving other methods to deal with the remaining cases.
*/
