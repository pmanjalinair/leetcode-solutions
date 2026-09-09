#include <stdio.h>
#include <string.h>

/*
 * Problem: Longest Common Prefix
 * Find the longest string prefix common to every string in the array.
 *
 * Approach: Start with the first string as the candidate prefix and
 * shrink it character-by-character whenever it stops matching the next
 * string. O(S) time, where S is the total number of characters.
 */

char* longestCommonPrefix(char** strs, int strsSize) {
    static char prefix[200];

    if (strsSize == 0) {
        prefix[0] = '\0';
        return prefix;
    }

    strcpy(prefix, strs[0]);

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (prefix[0] == '\0') break;
    }

    return prefix;
}

static void runTest(char** strs, int size, const char* expected, const char* label) {
    char* result = longestCommonPrefix(strs, size);
    if (strcmp(result, expected) == 0) {
        printf("[PASS] %s -> \"%s\"\n", label, result);
    } else {
        printf("[FAIL] %s -> got \"%s\", expected \"%s\"\n", label, result, expected);
    }
}

int main(void) {
    /* Typical case */
    char* strs1[] = {"flower", "flow", "flight"};
    runTest(strs1, 3, "fl", "typical case");

    /* Edge case: no common prefix at all */
    char* strs2[] = {"dog", "racecar", "car"};
    runTest(strs2, 3, "", "edge case (no common prefix)");

    return 0;
}