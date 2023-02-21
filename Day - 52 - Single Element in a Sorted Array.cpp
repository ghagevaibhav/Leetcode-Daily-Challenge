class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto c : nums) mp[c]++;
        for(auto [c, freq] : mp)
            if(freq == 1) return c;                
        return -1;                                
    }
};
