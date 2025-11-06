#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    char sport[30];
};

int main() {
    struct Student s[100];
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student names and sports
    for (i = 0; i < n; i++) {
        printf("\nEnter name of student %d: ", i + 1);
        scanf("%s", s[i].name);
        printf("Enter preferred sport: ");
        scanf("%s", s[i].sport);
    }

    printf("\n===== Students and Their Sports Preferences =====\n");
    for (i = 0; i < n; i++) {
        printf("%s → %s\n", s[i].name, s[i].sport);
    }

    // Display unique sports and the students who prefer them
    printf("\n===== List of Students Grouped by Sports =====\n");
    for (i = 0; i < n; i++) {
        int alreadyPrinted = 0;

        // Check if sport already processed
        for (j = 0; j < i; j++) {
            if (strcmp(s[i].sport, s[j].sport) == 0) {
                alreadyPrinted = 1;
                break;
            }
        }

        if (!alreadyPrinted) {
            printf("\n%s:\n", s[i].sport);
            for (j = 0; j < n; j++) {
                if (strcmp(s[i].sport, s[j].sport) == 0)
                    printf("  - %s\n", s[j].name);
            }
        }
    }

    return 0;
}
