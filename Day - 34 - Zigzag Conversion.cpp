class Solution {
public:
    string convert(string s, int n) {
        if (n == 1) return s;
        vector<string> rows(n);
       
        int j = 0, d = 1;
        for (int i = 0; i < s.size(); i++) {
            rows[j] += s[i];
            if(j == n - 1) d = -1;
            else if(j == 0) d = 1;
            j += d;
        }
        return accumulate(rows.begin(), rows.end(), string{});
    }
};
