class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        using P = pair<int, pair<int,int>>;
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));

        vector<pair<int,int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        pq.push({0, {0,0}});
        effort[0][0] = 0;

        while(!pq.empty()) {
            auto curr = pq.top();
            pq.pop();

            int currEffort = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            if(row == n-1 && col == m-1)
                return currEffort;

            for(auto it : dir) {
                int nr = row + it.first;
                int nc = col + it.second;

                if(nr >= 0 && nc >= 0 && nr < n && nc < m) {

                    int newEffort = max(
                        currEffort,
                        abs(heights[row][col] - heights[nr][nc])
                    );

                    if(newEffort < effort[nr][nc]) {
                        effort[nr][nc] = newEffort;
                        pq.push({newEffort, {nr,nc}});
                    }
                }
            }
        }

        return 0;
    }
};