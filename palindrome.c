#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], rev[100];
    int i, len, isPalindrome = 1;

    printf("Enter a string or number: ");
    scanf("%s", str);

    len = strlen(str);

    // Compare characters from both ends
    for (i = 0; i < len / 2; i++) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome)
        printf("\"%s\" is a palindrome.\n", str);
    else
        printf("\"%s\" is not a palindrome.\n", str);

    return 0;
}
