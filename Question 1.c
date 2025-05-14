#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;  // Start fast one step ahead to avoid immediate match

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return true;
        }
        slow = slow->next;       // Move slow by 1
        fast = fast->next->next; // Move fast by 2
    }

    return false;  // No cycle found
}

struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

int main() {
    // Test Case 1: No cycle (1 → 2 → 3 → NULL)
    struct ListNode *head1 = newNode(1);
    head1->next = newNode(2);
    head1->next->next = newNode(3);
    printf("Test Case 1 (No Cycle): %s\n", hasCycle(head1) ? "Cycle Found" : "No Cycle");

    // Test Case 2: Cycle (1 → 2 → 3 → 1 → ...)
    struct ListNode *head2 = newNode(1);
    head2->next = newNode(2);
    head2->next->next = newNode(3);
    head2->next->next->next = head2;  // Creates a cycle
    printf("Test Case 2 (Cycle Exists): %s\n", hasCycle(head2) ? "Cycle Found" : "No Cycle");

    free(head1->next->next);
    free(head1->next);
    free(head1);


    return 0;
}
