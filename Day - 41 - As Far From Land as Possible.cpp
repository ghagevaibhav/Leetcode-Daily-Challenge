class Solution {
public:
    #define exp(x, y) if (!g[x][y]) { g[x][y] = i+1; water++; }
    int maxDistance(vector<vector<int>>& g) {
        int r, c, R = g.size(), C = g[0].size(), i = 1, water = 1, land = 0;
        while(water) {
            water = 0; land = 0;
            for (r = 0; r < R; r++) {
                for (c = 0; c < C; c++) {
                    if (g[r][c] == i) { 
                        land++;
                        if (r > 0  ) exp(r-1, c); if (c > 0  ) exp(r, c-1); 
                        if (r < R-1) exp(r+1, c); if (c < C-1) exp(r, c+1);
                    }
                }
            }
            if (i == 1 && (!water || !land)) return -1;
            i++;
        }
        return i - 2; 
    }
};
