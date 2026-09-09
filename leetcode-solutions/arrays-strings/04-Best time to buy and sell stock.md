## Problem: Best Time to Buy and Sell Stock (Easy–Medium)

**Link:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

### Approach

Made a single pass through the prices while tracking the lowest price seen so far. At each day, checked whether selling today (current price minus the running minimum) would beat the best profit found so far, then updated the running minimum if today's price is a new low.

### Complexity

- Time: O(n)
- Space: O(1)

### Notes

The key insight is that you never need to consider selling before you've seen a lower buy price — the running minimum always represents the best possible buy point up to the current day. Edge case: strictly decreasing prices should return 0, since there's no profitable buy/sell pair (you're never allowed to lose money by not trading).