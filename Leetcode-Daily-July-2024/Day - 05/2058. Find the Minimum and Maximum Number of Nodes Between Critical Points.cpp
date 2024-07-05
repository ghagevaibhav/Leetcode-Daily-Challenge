class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> critical;  // Vector to store indices of critical points
        ListNode* curr = head;  // Current node
        ListNode* prev = NULL;  // Previous node
        ListNode* next = head->next;  // Next node
        int ind = 0;  // Index counter

        while(next != NULL)  // Traverse the list until we reach the end
        {
            // Check if current node is a local minima or maxima
            if((prev != NULL && curr->val < next->val && curr->val < prev->val) ||
               (prev != NULL && prev->val < curr-> val && curr->val > next->val) )
            {
                critical.push_back(ind);  // Add index to critical points vector
            }
            prev = curr;  // Move prev pointer
            curr = next;  // Move curr pointer
            next = next->next;  // Move next pointer
            ind++;  // Increment index
        }

        if(critical.size() < 2){  // If less than 2 critical points found
            return {-1, -1};  // Return {-1, -1} as per problem requirement
        }

        int maxi = critical.back() - critical.front();  // Maximum distance between critical points
        int mini = INT_MAX;  // Initialize minimum distance to max possible value

        // Find minimum distance between adjacent critical points
        for(int i = 0; i < critical.size() - 1; i++){
            mini = min(mini, critical[i+1] - critical[i]);
        }

        return {mini, maxi};  // Return minimum and maximum distances
    }
};
