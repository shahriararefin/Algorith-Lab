#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

void lcs(char* str1, char* str2, int len1, int len2) {
    int table[MAX_LENGTH][MAX_LENGTH];
    int i, j;

    // Initialize the table with 0
    for (i = 0; i <= len1; i++) {
        for (j = 0; j <= len2; j++) {
            table[i][j] = 0;
        }
    }

    // Fill the table
    for (i = 1; i <= len1; i++) {
        for (j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            } else {
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    // Find the LCS by backtracking the table
    int index = table[len1][len2];
    char lcsString[index + 1];
    lcsString[index] = '\0';

    i = len1;
    j = len2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcsString[index - 1] = str1[i - 1];
            i--;
            j--;
            index--;
        } else if (table[i - 1][j] > table[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print the LCS
    printf("Longest Common Subsequence: %s\n", lcsString);
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];

    printf("Enter the first string: ");
    scanf("%s", str1);

    printf("Enter the second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    lcs(str1, str2, len1, len2);

    return 0;
}
