class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        int m = worker.size();
        
        // Create a vector of pairs to store jobs with their respective difficulty and profit
        vector<pair<int, int>> jobs;
        for(int i = 0; i < n; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        
        // Sort jobs based on difficulty
        sort(jobs.begin(), jobs.end());
        
        // Sort workers based on their ability
        sort(worker.begin(), worker.end());
        
        int job = 0;         // Index to track the current job
        int curProfit = 0;   // Variable to track the current maximum profit for the available jobs
        int totalProfit = 0; // Variable to accumulate the total profit
        
        // Iterate through each worker
        for(int i = 0; i < m; i++) {
            // Update the current maximum profit the worker can achieve based on their ability
            while(job < n && worker[i] >= jobs[job].first) {
                curProfit = max(curProfit, jobs[job].second);
                job++;
            }
            // Add the current maximum profit to the total profit
            totalProfit += curProfit;
        }
        
        return totalProfit; // Return the total profit obtained
    }
};
