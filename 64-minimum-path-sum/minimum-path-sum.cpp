class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        int m= grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n || i<0 || j<0) return 100000000;
        if(i==0 && j==0) return grid[0][0] ;
        if(dp[i][j]!= INT_MAX) return dp[i][j];
        int up = grid[i][j] + solve(grid,i-1,j,dp);
        int left= grid[i][j] + solve(grid,i,j-1,dp);
        return dp[i][j] = min(up,left);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        return solve(grid,m-1,n-1,dp);
        
    }
};