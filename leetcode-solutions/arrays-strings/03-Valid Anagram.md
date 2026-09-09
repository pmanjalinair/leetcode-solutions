## Problem: Valid Anagram (Easy)

**Link:** https://leetcode.com/problems/valid-anagram/

### Approach
Since the inputs are lowercase English letters, use two fixed-size count arrays (size 26) instead
of a hash map or sorting. Increment the count for each character of both strings in one pass,
then compare the two count arrays.

### Complexity
- Time: O(n)
- Space: O(1) (fixed 26-element arrays regardless of input size)

### Notes
Sorting both strings and comparing (O(n log n)) is the more "obvious" first approach, but the
counting-array trick is strictly faster and simpler for a fixed alphabet. Checking `lenS != lenT`
first avoids wasted work and handles the classic anagram edge case cleanly.