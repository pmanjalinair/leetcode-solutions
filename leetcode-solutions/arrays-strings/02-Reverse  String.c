#include <stdio.h>
#include <string.h>

/*
 * Problem: Reverse a String
 * Reverse a string in place.
 *
 * Approach: Two-pointer swap, moving from both ends toward the middle.
 * O(n) time, O(1) extra space.
 */

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

static void runTest(const char* input, const char* expected, const char* label) {
    char buf[100];
    strcpy(buf, input);
    reverseString(buf, (int)strlen(buf));
    if (strcmp(buf, expected) == 0) {
        printf("[PASS] %s -> \"%s\"\n", label, buf);
    } else {
        printf("[FAIL] %s -> got \"%s\", expected \"%s\"\n", label, buf, expected);
    }
}

int main(void) {
    /* Typical case */
    runTest("hello", "olleh", "typical case");

    /* Edge case: single character (no-op) */
    runTest("a", "a", "edge case (single char)");

    return 0;
}