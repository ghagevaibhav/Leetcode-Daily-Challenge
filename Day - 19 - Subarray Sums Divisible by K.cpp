class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> m;

        int cur = 0;
        int ans = 0;
        m[0]++;

        for(auto x: nums){
            cur+= x;
            int mod = (cur % k + k) % k;

            if(m.find(mod) != m.end()){
                ans += m[mod];
            }
            m[mod]++;
        }
        return ans;
    }
};
