#include <stdio.h>
#include <stdlib.h>

// Your LeetCode solution function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int returnSize;

    // Test Case 1: Standard input
    int nums1[] = {2, 7, 11, 15};
    int* ans1 = twoSum(nums1, 4, 9, &returnSize);
    if (ans1) {
        printf("Test 1 Result: [%d, %d]\n", ans1[0], ans1[1]);
        free(ans1);
    }

    // Test Case 2: Duplicate / edge input
    int nums2[] = {3, 3};
    int* ans2 = twoSum(nums2, 2, 6, &returnSize);
    if (ans2) {
        printf("Test 2 Result: [%d, %d]\n", ans2[0], ans2[1]);
        free(ans2);
    }

    return 0;
}