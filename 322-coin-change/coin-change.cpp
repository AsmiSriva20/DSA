class Solution {
public:
    int func(vector<int>& coins,int amount,int i,vector<vector<int>>&dp){
        if(amount==0) return 0;
        if(amount<0 || i>=coins.size()) return 1e9;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick= 1+func(coins,amount-coins[i],i,dp);
        int notpick=func(coins,amount,i+1,dp);
        return dp[i][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        int ans=func(coins,amount,0,dp);
        return (ans==1e9)?-1: ans;
        
    }
};