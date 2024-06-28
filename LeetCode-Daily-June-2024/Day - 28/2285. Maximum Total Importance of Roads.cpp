class Solution {
public:
    // Function to calculate the maximum importance of a city based on its connectivity
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Vector to store the degree (number of connections) of each city
        vector<long long> degrees(n, 0);
        
        // Calculate the degree of each city
        for(auto edge: roads){
            long long u = edge[0], v = edge[1];
            degrees[u]++;
            degrees[v]++;
        }

        // Sort the degrees in ascending order
        sort(degrees.begin(), degrees.end());
        
        long long value = 1, ans = 0;
        
        // Assign values to cities based on their degree and calculate the total importance
        for(auto deg: degrees){
            ans += deg * value;
            value++;
        }
        
        // Return the total importance
        return ans;
    }
};
