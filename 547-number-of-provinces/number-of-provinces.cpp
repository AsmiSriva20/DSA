class Solution {
public:
    void dfs(int node, vector<int> adjlis[], vector<int>& vis) {
        vis[node] = 1;
        for (int i = 0; i < adjlis[node].size(); i++) {
            int num = adjlis[node][i];
            if (!vis[num]) {
                dfs(num, adjlis, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adjlis[n]; 

       
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjlis[i].push_back(j);
                    adjlis[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0); 
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjlis, vis); 
            }
        }

        return count;
    }
};