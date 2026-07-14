class Solution {
public:
    int m,n;
    int solve(int i, int j, vector<vector<int>> &dp){
        if(i<0||j<0||i>=m||j>=n) return 0;
        if(i==m-1 || j==n-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = solve(i,j+1,dp);
        int down = solve(i+1,j,dp);
        return dp[i][j] = right+down;
    }
    int uniquePaths(int m, int n) {
        this->m=m; this->n=n;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,dp);
    }
};