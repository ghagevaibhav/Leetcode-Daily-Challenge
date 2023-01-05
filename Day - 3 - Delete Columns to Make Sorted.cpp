class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count = 0;
        int n = strs.size();
        int l = strs[0].length();
        for(int i =0; i < l ; i++){
            for(int j = 0; j < n - 1; j++){
                if(strs[j][i] > strs[j+1][i]){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
