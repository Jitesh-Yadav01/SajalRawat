#include <stdio.h>

int main() {
    int n, i, isPrime = 1;  // isPrime = 1 means true (prime)

    // Input number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Handle special cases
    if (n <= 1) {
        isPrime = 0;  // 0 and 1 are not prime
    } else {
        // Check divisibility from 2 to n/2
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isPrime = 0;  // Not prime
                break;
            }
        }
    }

    // Output result
    if (isPrime)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}
