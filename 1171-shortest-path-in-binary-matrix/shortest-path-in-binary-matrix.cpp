class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, -1));

        if (grid[0][0] == 0) {
            q.push({0, 0});
            vis[0][0] = 1;
        };

        while (!q.empty()) {
            int nRow[] = {-1, -1, -1, 0, 0, 1, 1, 1};  int nCol[] = {-1, 0, 1, -1, 1, -1, 0, 1};

            auto [row, col] = q.front();
            q.pop();

            for (int i = 0; i < 8; i++) {
                int adjRow = row + nRow[i];
                int adjCol = col + nCol[i];

                if (adjRow >= 0 && adjRow < m &&
                    adjCol >= 0 && adjCol < n &&
                  grid[adjRow][adjCol] == 0 &&
                    vis[adjRow][adjCol] == -1) {

                    vis[adjRow][adjCol] = vis[row][col] + 1;
                    q.push({adjRow, adjCol});
                }
            }
        }
        return vis[m - 1][n - 1];
    }
};