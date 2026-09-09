## Problem: Longest Common Prefix (Easy–Medium)

**Link:** https://leetcode.com/problems/longest-common-prefix/

### Approach
Start with the first string as a candidate prefix, then compare it character-by-character against
each subsequent string, shrinking the candidate down to the point where they stop matching. If the
prefix ever becomes empty, stop early — no need to check the rest.

### Complexity
- Time: O(S), where S is the total number of characters across all strings (worst case, before
  early exit)
- Space: O(1) extra (excluding the output buffer)

### Notes
Comparing against the first string as the initial "worst case" prefix and shrinking it is simpler
to reason about than trying to compare all strings against each other at once. The early break
when the prefix hits `""` saved unnecessary work on the "no common prefix" edge case.