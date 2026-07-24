class Solution {
public:
    
    int solve(vector<int>&prices,int idx,int buy, int limit,vector<vector<vector<int>>>&dp){
        int n= prices.size();
        int profit=0;
        if(limit==0 || idx==n) return 0;
        if(dp[idx][buy][limit]!=-1) return dp[idx][buy][limit];
        if(buy){
           return dp[idx][buy][limit]= profit= max(-prices[idx]+solve(prices,idx+1,0,limit,dp), solve(prices,idx+1,1,limit,dp));
        }
        else return dp[idx][buy][limit]= profit=max(prices[idx]+solve(prices,idx+1,1,limit-1,dp), solve(prices,idx+1,0,limit,dp));
        
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,1,2,dp);
        
    }
};