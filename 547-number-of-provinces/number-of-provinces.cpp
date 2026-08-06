class Solution {
public:
    void bfs(int start, vector<vector<int>>& isConnected, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[node][i] == 1 && !vis[i]) {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                bfs(i, isConnected, vis);
            }
        }

        return provinces;
    }
};