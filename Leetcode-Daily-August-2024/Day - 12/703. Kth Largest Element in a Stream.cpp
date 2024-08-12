class KthLargest {
    int num;  // This variable stores the value of 'k', which represents the k-th largest element.
    priority_queue<int, vector<int>, greater<int>> pq;  // A min-heap (priority queue) that keeps track of the k largest elements.

public:
    // Constructor that initializes the k-th largest number finder with the list of initial elements.
    KthLargest(int k, vector<int>& nums) {
        num = k;  // Set 'num' to 'k', indicating the k-th largest element to find.
        for(auto ele : nums) {  // Iterate through the initial list of numbers.
            pq.push(ele);  // Add each element to the priority queue.
            if(pq.size() > k) pq.pop();  // If the size of the queue exceeds 'k', remove the smallest element.
        }
    }
    
    // Method to add a new number and return the k-th largest element.
    int add(int val) {
        pq.push(val);  // Add the new value to the priority queue.
        if(pq.size() > num) pq.pop();  // If the size exceeds 'k', remove the smallest element to maintain the k largest elements.
        return pq.top();  // Return the smallest element in the priority queue, which is the k-th largest element in the data stream.
    }
};
