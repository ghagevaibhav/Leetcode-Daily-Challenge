// Solution 
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& a, int k) {
        int n = a.size();
        priority_queue<pair<double, pair<int, int>>> pq;
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double frac = static_cast<double>(a[i]) / a[j];
                pq.push({frac, {a[i], a[j]}});
                if(pq.size() > k) {
                    pq.pop();
                }
            }
        }
        
        pair<int, int> p = pq.top().second;
        return {p.first, p.second};
    }
};

// TC :- O(n^2 * log k)
// SC :- O(k)
