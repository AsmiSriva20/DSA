class Solution {
public:
    int solve(vector<vector<int>> &triangle,vector<vector<int>> &dp, int i,int j){
        int rows=triangle.size();
        if(i<0 || j<0 || i>=rows|| j>=triangle[i].size()) return INT_MAX;
        if(i==rows-1) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int down = solve(triangle,dp,i+1,j);
        int diag= solve(triangle,dp,i+1,j+1);
        int ans=min(down,diag);
        if(ans==INT_MAX) return INT_MAX;
        return dp[i][j]= ans+triangle[i][j];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        vector<vector<int>> dp(rows, vector<int>(rows, INT_MAX));
        
        return solve(triangle,dp,0,0);   
    }
};