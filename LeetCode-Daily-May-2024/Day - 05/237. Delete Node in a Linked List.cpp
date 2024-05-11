class Solution {
public:
    void deleteNode(ListNode* node) {
        // Update current node's value with the value of the next node
        node->val = node->next->val;
        
        // Point current node's next pointer to the next node's next pointer
        node->next = node->next->next;
    }
};
