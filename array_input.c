#include <stdio.h>

int main() {
    int arr[100], n, choice, i, num, count;
    float avg;
    int max, min;

    printf("Enter number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1. Find Average\n");
        printf("2. Find Frequency of an Element\n");
        printf("3. Find Maximum Element\n");
        printf("4. Find Minimum Element\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                avg = 0;
                for (i = 0; i < n; i++)
                    avg += arr[i];
                avg /= n;
                printf("Average of array elements = %.2f\n", avg);
                break;

            case 2:
                printf("Enter element to find frequency: ");
                scanf("%d", &num);
                count = 0;
                for (i = 0; i < n; i++) {
                    if (arr[i] == num)
                        count++;
                }
                printf("Frequency of %d = %d\n", num, count);
                break;

            case 3:
                max = arr[0];
                for (i = 1; i < n; i++) {
                    if (arr[i] > max)
                        max = arr[i];
                }
                printf("Maximum element = %d\n", max);
                break;

            case 4:
                min = arr[0];
                for (i = 1; i < n; i++) {
                    if (arr[i] < min)
                        min = arr[i];
                }
                printf("Minimum element = %d\n", min);
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
