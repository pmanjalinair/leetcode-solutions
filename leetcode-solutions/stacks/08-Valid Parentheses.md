## Problem: Valid Parentheses (Easy–Medium)

**Link:** https://leetcode.com/problems/valid-parentheses/

### Approach
Use a stack. Push every opening bracket. On a closing bracket, pop the top of the stack and check
it matches the corresponding opening bracket type — if the stack is empty or the types don't
match, the string is invalid immediately. At the end, the string is valid only if the stack is
empty (every opener was closed).

### Complexity
- Time: O(n)
- Space: O(n) (worst case, e.g. a string of all opening brackets)

### Notes
This is the textbook use case for a stack — matching nested/paired structures. Two edge cases
were important to test: an empty string (should be valid, vacuously true) and a case with
correctly *balanced counts* but *mismatched types* like `"(]"`, which a naive counter-based
solution (counting opens vs closes) would wrongly accept. The stack approach handles both
correctly because it checks bracket type, not just balance.