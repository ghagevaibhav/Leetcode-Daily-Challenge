class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        // If the list is empty or has only one node, return the head as is
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* prev = head;        // Initialize prev to the head of the list
        ListNode* curr = head->next;  // Initialize curr to the second node of the list
        
        // Traverse the list until the node before the last node
        while(curr->next != NULL){
            if(curr->val != 0){
                // If the current node's value is not zero, add it to the value of the prev node
                prev->val = prev->val + curr->val;
                curr = curr->next;    // Move to the next node
            }
            else if(curr->val == 0){
                // If the current node's value is zero, link prev to the current node
                prev->next = curr;
                prev = curr;          // Move prev to the current node
                curr = curr->next;    // Move to the next node
            }
        }
        prev->next = nullptr;  // Set the next pointer of the last node to nullptr
        return head;           // Return the modified head
    }
};
