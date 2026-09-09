## Problem: Move Zeroes (Easy–Medium)

**Link:** https://leetcode.com/problems/move-zeroes/

### Approach
Two-pass, in-place, single array. First pass: walk through the array and copy every non-zero
element forward into an `insertPos` slot, which effectively compacts all non-zero values to the
front while preserving their relative order. Second pass: fill everything from `insertPos` to the
end with zeroes.

### Complexity
- Time: O(n)
- Space: O(1) (in-place)

### Notes
This is essentially the "partition" step from other array problems (like removing a value in
place). The all-zeroes edge case confirms `insertPos` correctly stays at 0 and the second loop
fills the whole array without touching anything in the first loop — good confirmation the two
passes don't interfere with each other.