## Problem: Binary Search (Easy–Medium)

**Link:** https://leetcode.com/problems/binary-search/

### Approach
Classic binary search on a sorted array. Maintain `left`/`right` bounds, compute `mid` using
`left + (right - left) / 2` (to avoid integer overflow on large arrays), and narrow the search
range based on whether `nums[mid]` is less than, greater than, or equal to the target.

### Complexity
- Time: O(log n)
- Space: O(1)

### Notes
Using `left + (right - left) / 2` instead of `(left + right) / 2` is a habit worth keeping even in
C, since it avoids overflow issues that would matter in languages/inputs with larger integer
ranges. The single-element edge case is a good sanity check that the `left <= right` loop
condition (not `<`) is correct — with one element, `left == right == mid` on the first iteration.