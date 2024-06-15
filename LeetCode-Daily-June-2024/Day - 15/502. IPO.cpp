class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        // Create a vector of pairs where each pair is (capital required, profit).
        vector<pair<int, int>> projects(n);
        for(int i = 0; i < n; i++){
            projects[i] = {capital[i], profits[i]};
        }
        
        // Sort projects by the capital required in ascending order.
        sort(projects.begin(), projects.end());
        
        // Initialize a priority queue (max-heap) to store profits.
        int i = 0;
        priority_queue<int> maximizeCapital;
        
        // Perform up to k projects.
        while(k--){
            // Push all projects that can be afforded with current capital into the max-heap.
            while(i < n && projects[i].first <= w){
                maximizeCapital.push(projects[i].second);
                i++;
            }
            
            // If no projects can be afforded, break out of the loop.
            if(maximizeCapital.empty())
                break;
            
            // Select the project with the maximum profit.
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }
        
        // Return the final capital after completing up to k projects.
        return w;
    }
};
