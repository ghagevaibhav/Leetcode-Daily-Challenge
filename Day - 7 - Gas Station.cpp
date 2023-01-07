class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int l = gas.size();
        int t_gas = 0, t_cost = 0, curr_gas = 0, start = 0;
        for(int  i = 0; i < l; i++){
            
            t_gas += gas[i];
            t_cost += cost[i];

            curr_gas += gas[i] - cost[i];
            if(curr_gas < 0){
                start = i+1;
                curr_gas = 0;
            }
        }
        return (t_gas < t_cost)? -1 : start;
    }
};
