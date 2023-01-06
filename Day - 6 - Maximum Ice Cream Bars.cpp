class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(costs.begin(), costs.end());
        int l = costs.size();
        for(int i = 0 ; i < l; i++){
            if(costs[i] <= coins)
                coins -= costs[i];
            else
                return i;
        }        
        return l;
    }
};
