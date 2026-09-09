#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
 * Problem: Valid Anagram
 * Check whether string t is an anagram of string s.
 *
 * Approach: Count lowercase-letter frequencies in a fixed 26-slot array
 * (increment for s, decrement for t), then confirm every count is zero.
 * O(n) time, O(1) space.
 */

bool isAnagram(char* s, char* t) {
    if (strlen(s) != strlen(t)) return false;

    int counts[26] = {0};
    for (int i = 0; s[i]; i++) counts[s[i] - 'a']++;
    for (int i = 0; t[i]; i++) counts[t[i] - 'a']--;

    for (int i = 0; i < 26; i++) {
        if (counts[i] != 0) return false;
    }
    return true;
}

static void runTest(char* s, char* t, bool expected, const char* label) {
    bool result = isAnagram(s, t);
    if (result == expected) {
        printf("[PASS] %s -> %s\n", label, result ? "true" : "false");
    } else {
        printf("[FAIL] %s -> got %s, expected %s\n", label, result ? "true" : "false", expected ? "true" : "false");
    }
}

int main(void) {
    /* Typical case */
    runTest("anagram", "nagaram", true, "typical case");

    /* Edge case: both empty strings */
    runTest("", "", true, "edge case (empty strings)");

    return 0;
}