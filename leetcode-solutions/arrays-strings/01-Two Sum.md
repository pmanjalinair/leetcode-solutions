## Problem: Two Sum (Easy)
**Link:** https://leetcode.com/problems/two-sum/

### Approach
I used a brute-force approach with two nested loops to check every possible pair of numbers in the array. If the sum of the current pair equals the target, their indices are stored and returned.

### Complexity
- Time: O(n^2) because of the nested loops iterating through the array.
- Space: O(1) auxiliary space, as only a fixed-size array is allocated for the result.

### Notes
While this approach is easy to implement and uses minimal memory, it is not the most efficient for large inputs. A cleaner and faster approach for next time would be using a Hash Map to reduce the time complexity to O(n), though it would require more memory.