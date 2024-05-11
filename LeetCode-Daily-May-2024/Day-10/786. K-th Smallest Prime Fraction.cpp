class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        int n = a.size(); // Get the size of the input array.
        priority_queue<pair<double, pair<int, int>>> pq; // Create a max heap to store fractions along with their corresponding pairs.

        // Iterate through all pairs of elements in the array.
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double frac = static_cast<double>(a[i]) / a[j]; // Calculate the fraction for the current pair.
                pq.push({frac, {a[i], a[j]}}); // Push the fraction and the corresponding pair onto the max heap.
                if(pq.size() > k) { // If the size of the max heap exceeds 'k', pop the top element.
                    pq.pop();
                }
            }
        }

        pair<int, int> p = pq.top().second; // Get the pair corresponding to the top element of the max heap.
        return {p.first, p.second}; // Return the pair.
    }
};
