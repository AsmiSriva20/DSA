class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>> &dp){
        int m= obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(i>=m || j>=n  || i<0|| j<0 || obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==m-1 && j==n-1) return 1;
        int right = solve(obstacleGrid, i, j+1,dp);
        int left = solve(obstacleGrid, i+1, j,dp);
        return dp[i][j]=left+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m= obstacleGrid.size();
      int n=obstacleGrid[0].size();
      vector<vector<int>>dp(m,vector<int>(n,-1));   
      return solve(obstacleGrid,0,0,dp);  
        
    }
};