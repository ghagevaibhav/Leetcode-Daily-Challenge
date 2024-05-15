class Solution {
public:
    // Direction vectors for moving in the four possible directions: left, right, up, and down
    vector<int> roww = {0, 0, -1, 1};
    vector<int> coll = {-1, 1, 0, 0};

    // BFS function to calculate the minimum distance (score) from any '1' in the grid
    void bfs(vector<vector<int>>& grid, vector<vector<int>>& score, int n) {
        queue<pair<int, int>> q;

        // Initialize the queue with all the positions where grid[i][j] == 1
        // Set the score for these positions to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // BFS to propagate the scores from the initial positions
        while (!q.empty()) {
            auto t = q.front();
            q.pop();

            int x = t.first, y = t.second;
            int s = score[x][y];

            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int newX = x + roww[i];
                int newY = y + coll[i];

                // If the new position is within bounds and the new score is less than the current score
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s) {
                    // Update the score and push the new position into the queue
                    score[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }
    }

    // Main function to find the maximum safeness factor
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        int n = grid.size();

        // If the start or end cell is '1', return 0 as it's not possible to start or end there
        if (grid[0][0] || grid[n - 1][n - 1]) return 0;

        // Initialize the score matrix with INT_MAX to represent unvisited cells
        vector<vector<int>> score(n, vector<int>(n, INT_MAX));

        // Run BFS to fill in the score matrix
        bfs(grid, score, n);

        // Visited matrix to keep track of visited cells
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        // Max-heap priority queue to keep track of the path with the highest safeness factor
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});

        // Dijkstra's-like algorithm to find the path with the maximum safeness factor
        while (!pq.empty()) {
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            // If the bottom-right cell is reached, return the safeness factor
            if (temp.first == n - 1 && temp.second == n - 1) return safe;
            vis[temp.first][temp.second] = true;

            // Explore the four possible directions
            for (int i = 0; i < 4; i++) {
                int newX = temp.first + roww[i];
                int newY = temp.second + coll[i];

                // If the new position is within bounds and not visited
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY]) {
                    // Update the safeness factor and push the new position into the priority queue
                    int s = min(safe, score[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }

        // If no path is found, return -1
        return -1;
    }
};
