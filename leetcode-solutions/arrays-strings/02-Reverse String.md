## Problem: Reverse a String (Easy)

**Link:** https://leetcode.com/problems/reverse-string/

### Approach
Two-pointer swap in place: one pointer starts at the front, one at the back, and they swap
characters and move toward each other until they meet or cross.

### Complexity
- Time: O(n)
- Space: O(1) (in-place, excluding the local test buffer)

### Notes
This is the canonical two-pointer pattern — good to recognize it quickly since it shows up again
in problems like palindrome checks and array reversal. The single-character edge case confirms
the loop condition (`left < right`) correctly does nothing when there's nothing to swap.