class Solution {
public:
    // Function to double the values of nodes in the linked list
    ListNode* doubleIt(ListNode* head) {
        // Reverse the input linked list
        ListNode* reversedList = reverseList(head);
        int carry = 0;
        ListNode* current = reversedList, *previous = nullptr;
        // Traverse the reversed list
        while (current != nullptr) {
            // Calculate the new value for the current node
            int newValue = current->val * 2 + carry;
            current->val = newValue % 10; // Update the current node's value
            if (newValue > 9) {
                carry = 1; // Update carry if necessary
            } else {
                carry = 0;
            }
            previous = current;
            current = current->next; // Move to the next node
        }

        // If there's a carry after processing all nodes, add an extra node with the carry value
        if (carry != 0) {
            ListNode* extraNode = new ListNode(carry);
            previous->next = extraNode;
        }

        // Reverse the modified linked list again to get the final result
        ListNode* result = reverseList(reversedList);

        return result;
    }

    // Function to reverse a linked list
    ListNode* reverseList(ListNode* node) {
        ListNode* previous = nullptr, *current = node, *nextNode;
        // Traverse the input linked list
        while (current != nullptr) {
            nextNode = current->next;
            current->next = previous; // Reverse the pointers
            previous = current;
            current = nextNode;
        }
        return previous; // Return the new head of the reversed list
    }
};
