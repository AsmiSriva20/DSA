class Solution {
public:
    void dfs(vector<vector<int>>& adj, int i, vector<int>& vis) {
        vis[i] = 1;

        for(int j = 0; j < adj.size(); j++) {
            if(adj[i][j] == 1 && vis[j] == 0) {
                dfs(adj, j, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(isConnected, i, vis);
                count++;
            }
        }

        return count;
    }
};