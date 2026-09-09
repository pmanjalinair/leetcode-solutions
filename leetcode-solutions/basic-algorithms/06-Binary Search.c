#include <stdio.h>

/*
 * Problem: Binary Search
 * Search a sorted array for a target value; return its index, or -1
 * if the target is not present.
 *
 * Approach: Classic iterative binary search, halving the search window
 * each step. O(log n) time, O(1) space.
 */

int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

static void runTest(int* nums, int size, int target, int expected, const char* label) {
    int result = search(nums, size, target);
    if (result == expected) {
        printf("[PASS] %s -> %d\n", label, result);
    } else {
        printf("[FAIL] %s -> got %d, expected %d\n", label, result, expected);
    }
}

int main(void) {
    /* Typical case */
    int nums1[] = {-1, 0, 3, 5, 9, 12};
    runTest(nums1, 6, 9, 4, "typical case");

    /* Edge case: target not present in the array */
    int nums2[] = {-1, 0, 3, 5, 9, 12};
    runTest(nums2, 6, 2, -1, "edge case (not found)");

    return 0;
}