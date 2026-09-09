#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
 * Problem: Valid Parentheses
 * Determine whether a string of brackets is valid: every opening
 * bracket must be closed by the same type of bracket, in the correct
 * order.
 *
 * Approach: Push opening brackets onto a stack; on a closing bracket,
 * pop and check it matches. The string is valid if the stack ends
 * empty. O(n) time, O(n) space.
 */

bool isValid(char* s) {
    int n = (int)strlen(s);
    char stack[10000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;
            char open = stack[top--];
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                return false;
            }
        }
    }
    return top == -1;
}

static void runTest(char* s, bool expected, const char* label) {
    bool result = isValid(s);
    if (result == expected) {
        printf("[PASS] %s -> %s\n", label, result ? "true" : "false");
    } else {
        printf("[FAIL] %s -> got %s, expected %s\n", label, result ? "true" : "false", expected ? "true" : "false");
    }
}

int main(void) {
    /* Typical case */
    runTest("{[]}", true, "typical case");

    /* Edge case: empty string is trivially valid */
    runTest("", true, "edge case (empty string)");

    return 0;
}