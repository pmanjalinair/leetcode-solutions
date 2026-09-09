## Problem: Reverse a Linked List (Easy–Medium, bonus)

**Link:** https://leetcode.com/problems/reverse-linked-list/

### Approach

Used the iterative pointer-reversal technique: walked the list once while keeping a `prev` pointer (initially `NULL`) and a `curr` pointer (starting at `head`). At each step, saved `curr->next` before overwriting it to point backward at `prev`, then advanced both `prev` and `curr` forward. When `curr` becomes `NULL`, `prev` is the new head of the reversed list.

### Complexity

- Time: O(n)
- Space: O(1) — reverses in place with only a few pointer variables

### Notes

Saving `curr->next` into a temporary variable before rewiring `curr->next` is the detail that makes this work — otherwise the rest of the list becomes unreachable the moment the first pointer is flipped. Edge case: a single-node list should come back unchanged, since there's only one node to "reverse."