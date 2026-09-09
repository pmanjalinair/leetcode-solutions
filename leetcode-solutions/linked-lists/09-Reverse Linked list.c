#include <stdio.h>
#include <stdlib.h>

/*
 * Problem: Reverse a Linked List (bonus)
 * Reverse a singly linked list.
 *
 * Approach: Iterative pointer reversal. Walk the list once, redirecting
 * each node's 'next' pointer backward while carrying a 'prev' pointer
 * forward. O(n) time, O(1) space.
 *
 * Note: struct ListNode is defined WITHOUT a typedef here to match
 * LeetCode's own boilerplate for this problem exactly. LeetCode already
 * pre-defines "struct ListNode" in the editor, so pasting a typedef'd
 * version alongside it causes a "redefinition of struct ListNode" error.
 * When submitting on LeetCode, copy only the reverseList() function below
 * (LeetCode already provides the struct + Definition comment).
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr != NULL) {
        struct ListNode* nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    return prev;
}

/* ---------- Local test harness (not part of the LeetCode submission) ---------- */

static struct ListNode* buildList(int* vals, int size) {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;
    for (int i = 0; i < size; i++) {
        struct ListNode* node = malloc(sizeof(struct ListNode));
        node->val = vals[i];
        node->next = NULL;
        if (head == NULL) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

static void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* next = head->next;
        free(head);
        head = next;
    }
}

static void runTest(int* vals, int size, int* expected, const char* label) {
    struct ListNode* head = buildList(vals, size);
    struct ListNode* reversed = reverseList(head);

    int pass = 1;
    struct ListNode* curr = reversed;
    for (int i = 0; i < size; i++) {
        if (curr == NULL || curr->val != expected[i]) { pass = 0; break; }
        curr = curr->next;
    }
    if (curr != NULL) pass = 0;

    printf("[%s] %s -> [", pass ? "PASS" : "FAIL", label);
    curr = reversed;
    while (curr != NULL) {
        printf("%d%s", curr->val, curr->next ? ", " : "");
        curr = curr->next;
    }
    printf("]\n");

    freeList(reversed);
}

int main(void) {
    /* Typical case: [1,2,3,4,5] -> [5,4,3,2,1] */
    int vals1[] = {1, 2, 3, 4, 5};
    int expected1[] = {5, 4, 3, 2, 1};
    runTest(vals1, 5, expected1, "typical case");

    /* Edge case: single-node list (reversal is a no-op) */
    int vals2[] = {42};
    int expected2[] = {42};
    runTest(vals2, 1, expected2, "edge case (single node)");

    return 0;
}