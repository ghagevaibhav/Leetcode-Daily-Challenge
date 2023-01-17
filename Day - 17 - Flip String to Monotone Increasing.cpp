class Solution {
public:
    int minFlipsMonoIncr(string &s) {
        int count = 0, ans = 0;
        for(auto i : s){
            if(i == '1'){
                count++;
            }
            else{
                ans++;
                ans = min(ans, count);
            }
        }
        return ans;
    }
};
