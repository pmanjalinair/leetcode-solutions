#include <stdio.h>

/*
 * Problem: Move Zeroes
 * Move all zeroes in an array to the end while preserving the relative
 * order of the non-zero elements, in place.
 *
 * Approach: Two-pointer swap. 'insertPos' marks where the next non-zero
 * value belongs; swap it into place as we scan left to right. O(n)
 * time, O(1) space.
 */

void moveZeroes(int* nums, int numsSize) {
    int insertPos = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            int tmp = nums[insertPos];
            nums[insertPos] = nums[i];
            nums[i] = tmp;
            insertPos++;
        }
    }
}

static void runTest(int* nums, int size, int* expected, const char* label) {
    moveZeroes(nums, size);
    int pass = 1;
    for (int i = 0; i < size; i++) if (nums[i] != expected[i]) pass = 0;

    printf("[%s] %s -> [", pass ? "PASS" : "FAIL", label);
    for (int i = 0; i < size; i++) printf("%d%s", nums[i], i == size - 1 ? "" : ", ");
    printf("]\n");
}

int main(void) {
    /* Typical case */
    int nums1[] = {0, 1, 0, 3, 12};
    int expected1[] = {1, 3, 12, 0, 0};
    runTest(nums1, 5, expected1, "typical case");

    /* Edge case: single-element array that is zero */
    int nums2[] = {0};
    int expected2[] = {0};
    runTest(nums2, 1, expected2, "edge case (single zero)");

    return 0;
}