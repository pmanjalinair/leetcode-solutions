#include <stdio.h>

/*
 * Problem: Best Time to Buy and Sell Stock
 * Given daily prices, find the maximum profit from a single buy
 * followed by a single sell.
 *
 * Approach: One pass, tracking the minimum price seen so far and the
 * best profit achievable if sold today. O(n) time, O(1) space.
 */

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = prices[0];
    int best = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] - minPrice > best) best = prices[i] - minPrice;
        if (prices[i] < minPrice) minPrice = prices[i];
    }
    return best;
}

static void runTest(int* prices, int size, int expected, const char* label) {
    int result = maxProfit(prices, size);
    if (result == expected) {
        printf("[PASS] %s -> %d\n", label, result);
    } else {
        printf("[FAIL] %s -> got %d, expected %d\n", label, result, expected);
    }
}

int main(void) {
    /* Typical case: [7,1,5,3,6,4] -> buy at 1, sell at 6 -> profit 5 */
    int prices1[] = {7, 1, 5, 3, 6, 4};
    runTest(prices1, 6, 5, "typical case");

    /* Edge case: strictly decreasing prices -> no profit possible */
    int prices2[] = {7, 6, 4, 3, 1};
    runTest(prices2, 5, 0, "edge case (decreasing prices)");

    return 0;
}