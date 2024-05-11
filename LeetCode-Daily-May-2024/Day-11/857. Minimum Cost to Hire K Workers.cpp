#include <vector>
#include <queue>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        double res = numeric_limits<double>::infinity(); // Initialize the result as positive infinity.
        vector<pair<double, int>> pairs; // Create a vector to store pairs of (wage/quality, quality).
        
        // Step 1: Create pairs of (wage/quality, quality) and store them in 'pairs'.
        for (int i = 0; i < quality.size(); ++i) {
            pairs.push_back(make_pair((double)wage[i] / quality[i], quality[i]));
        }
        
        // Step 2: Sort the 'pairs' vector based on the first element of the pair (wage/quality ratio).
        sort(pairs.begin(), pairs.end());

        priority_queue<int> maxHeap; // Create a max heap to store qualities.
        int total_quality = 0; // Initialize the total quality to 0.
        
        // Step 3: Iterate through each pair in 'pairs'.
        for (auto& p : pairs) {
            maxHeap.push(p.second); // Push the quality onto the max heap.
            total_quality += p.second; // Add the quality to the total quality.

            // Step 4: If the size of the max heap exceeds 'k', pop the top element.
            if (maxHeap.size() > k) {
                total_quality -= maxHeap.top(); // Subtract the quality of the top element from the total quality.
                maxHeap.pop(); // Remove the top element from the max heap.
            }

            // Step 5: If the size of the max heap reaches 'k', calculate the cost and update 'res'.
            if (maxHeap.size() == k) {
                res = min(res, total_quality * p.first); // Update 'res' by taking the minimum of the current 'res' and the calculated cost.
            }
        }
        return res; // Return the minimum cost.
    }
};

/*
Time Complexity Analysis:
- Constructing the pairs vector: O(n)
- Sorting the pairs vector: O(n log n)
- Iterating through the pairs vector: O(n)
- Pushing/popping elements to/from the max heap: O(n log k) (Since there are 'n' elements and each operation takes log k time)
Overall Time Complexity: O(n log n)

Space Complexity Analysis:
- Space required for the pairs vector: O(n)
- Space required for the max heap: O(k)
Overall Space Complexity: O(n + k)
*/
