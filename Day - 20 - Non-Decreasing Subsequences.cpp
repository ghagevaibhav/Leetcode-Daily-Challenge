class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> st;

        st.insert(vector<int>({}));

        for(auto x : nums){
            set<vector<int>> temp_s;

            for(auto cur_s : st){

                if(cur_s.empty() || cur_s.back() <= x){
                    vector<int> new_s = cur_s;

                    new_s.push_back(x);
                    temp_s.insert(new_s);

                }
            }

            st.insert(temp_s.begin(), temp_s.end());

        }

        for(auto x: st){
            if(x.size() >= 2){
                ans.push_back(x);
            }
        }

        return ans;
    }
};
