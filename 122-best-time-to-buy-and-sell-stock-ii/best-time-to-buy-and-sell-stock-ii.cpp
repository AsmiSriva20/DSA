class Solution {
public:
    int solve(int i,vector<int>& prices,int buy,vector<vector<int>>&dp){
        int n= prices.size();
        if(i==n) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        if(buy){
            profit= max(-prices[i]+ solve(i+1,prices,0,dp), solve(i+1,prices,1,dp));
        }
        else profit=max(prices[i]+solve(i+1,prices,1,dp), solve(i+1,prices,0,dp));
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,prices,1,dp);
        
        
    }
};