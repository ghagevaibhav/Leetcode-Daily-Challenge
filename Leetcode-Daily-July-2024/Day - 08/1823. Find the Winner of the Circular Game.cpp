class Solution {
public:

    void solve(int ind, int &ans, int k, vector<int> v){
        if(v.size() == 1){
            ans = v[0];
            return;
        }
        ind = (ind + k) % v.size();
        v.erase(v.begin() + ind);
        solve(ind, ans, k, v);
        return;
    }

    int findTheWinner(int n, int k) {
        int ans = -1, ind = 0;
        k = k-1;
        vector<int> v;
        for(int i = 1; i <= n; i++){
            v.push_back(i);
        } 
        solve(ind, ans, k, v);
        return ans;
    }
};
