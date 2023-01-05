class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int l = tasks.size();
        map<int, int> m;
        for(int i = 0; i < l; i++){
            m[tasks[i]]++;
        }
        int freq, ans = 0 ;
        for(auto i : m){
            freq = i.second;
            if(freq == 1){
                return -1;
            }
            if(freq % 3 == 0){
                ans += freq/3;
            }
            else{
                ans+= freq/3 + 1;
            }
        }
        return ans;
    }
};
