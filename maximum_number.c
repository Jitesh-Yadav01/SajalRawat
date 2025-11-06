#include <stdio.h>

int main() {
    int n, i, max;

    // Ask the user for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    // Input elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is the maximum
    max = arr[0];

    // Compare each element with the current max
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Display the maximum value
    printf("The maximum value is: %d\n", max);

    return 0;
}
