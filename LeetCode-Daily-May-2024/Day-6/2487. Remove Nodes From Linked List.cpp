class Solution {
public:
    // Function to remove nodes from the linked list
    ListNode* removeNodes(ListNode* head) {
        vector<int> v; // Vector to store values of nodes
        ListNode* h = head; // Pointer to iterate through the linked list
        ListNode* h2 = head; // Pointer to track the head of the modified list
        
        // Extract values from nodes and store them in the vector
        while (h) {
            v.push_back(h->val);
            h = h->next;
        }
        
        h = head; // Reset the pointer to the head of the linked list
        int n = v.size(); // Number of nodes in the linked list
        stack<int> s; // Stack to track indices of nodes with larger values
        vector<int> r; // Vector to store indices of nodes to be removed
        
        // Iterate through the values from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Remove smaller elements from the stack
            while (!s.empty() && v[s.top()] <= v[i]) {
                s.pop();  
            }
            // If the stack is empty, no larger element found
            if (s.empty())
                r.push_back(-1); // Mark as -1 to indicate no larger element
            else
                r.push_back(s.top()); // Store index of larger element
            s.push(i); // Push the current index to the stack
        }
        
        reverse(r.begin(), r.end()); // Reverse the vector of indices
        
        set<int> st; // Set to store indices of nodes to be removed
        // Populate the set with valid indices (not marked as -1)
        for (int i = 0; i < r.size(); i++) {
            if (r[i] != -1) {
                st.insert(i);
            }
        }
        
        int i = 0; // Index tracker
        ListNode* prev = NULL; // Pointer to track the previous node
        
        // Iterate through the linked list
        while (h) {
            // If the current index is marked for removal
            if (st.find(i) != st.end()) {
                // If it's the head of the list, move the head
                if (h == h2) {
                    h = h->next;
                    h2 = h2->next;
                } else {
                    // Otherwise, remove the node by adjusting pointers
                    prev->next = h->next;
                    h = h->next;
                }
            } else {
                // If not marked for removal, move to the next node
                prev = h;
                h = h->next;
            }
            i++; // Increment the index
        }
        
        return h2; // Return the head of the modified list
    }
};
