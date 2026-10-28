class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj, int i, vector<int>& vis) {
        vis[i] = 1;

        for(int j = 0; j < adj[i].size(); j++) {
            int node = adj[i][j];

            if(vis[node] == 0) {
                dfs(adj, node, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        unordered_map<int,vector<int>> adj;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        int count = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(adj, i, vis);
                count++;
            }
        }

        return count;
    }
};