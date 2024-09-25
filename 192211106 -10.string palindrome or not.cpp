#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(const char *str) {
    int left = 0, right = strlen(str) - 1;
    while (left < right) {
        if (tolower(str[left]) != tolower(str[right])) return 0;
        left++;
        right--;
    }
    return 1;
}

int main() {
    char str[1000];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    printf("The string is %sa palindrome.\n", isPalindrome(str) ? "" : "not ");
    return 0;
}

