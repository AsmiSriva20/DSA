class Solution {
public:
   
    void dfs(vector<vector<int>>& isConnected, vector<int>&vis, int node){
         int n= isConnected.size();
        vis[node]=1;
        for(int i=0;i<n;i++){
            int x= isConnected[node][i];
            if(x==1 && !vis[i]){
                dfs(isConnected,vis,i);
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int n= isConnected.size();
        vector<int>vis(n,0);
        int num=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                num++;
                dfs(isConnected,vis,i);
            }

        }
        return num;
        
    }
};