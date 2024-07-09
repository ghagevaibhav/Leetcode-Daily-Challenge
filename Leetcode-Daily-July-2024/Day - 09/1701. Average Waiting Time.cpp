class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();  // Number of customers
        double total = 0;  // Total waiting time
        int av = 0;  // Available time for next customer
        
        for(auto& c: customers){
            int arrival = c[0], t = c[1];  // Arrival time and food preparation time
            
            // Update available time: max of current available time or customer arrival time
            // Then add food preparation time
            av = max(av, arrival) + t;
            
            // Add waiting time for this customer to total
            // Waiting time = time food is ready (av) - arrival time
            total += av - arrival;
        }
        
        // Return average waiting time
        return (double)(total / n);
    }
};
