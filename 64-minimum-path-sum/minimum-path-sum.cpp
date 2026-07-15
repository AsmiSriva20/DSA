class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        int m= grid.size();
        int n=grid[0].size();
        if(i>=m || j>=n || i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return grid[0][0] ;
        if(dp[i][j]!= INT_MAX) return dp[i][j];
        int up = solve(grid,i-1,j,dp);
        int left= solve(grid,i,j-1,dp);
        int ans = min(up,left);
        if(ans== INT_MAX) return INT_MAX;
        else return dp[i][j]= grid[i][j]+ ans;

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        return solve(grid,m-1,n-1,dp);
        
    }
};