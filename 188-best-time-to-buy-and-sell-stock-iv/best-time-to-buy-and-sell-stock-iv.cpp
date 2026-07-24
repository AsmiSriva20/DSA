class Solution {
public:
    int kuch(vector<int>& prices,int idx, int buy, int cap,vector<vector<vector<int>>>& dp){
        int n=prices.size();
        if(idx==n) return 0;
        if(cap==0) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap]; 

        if(buy){
            return dp[idx][buy][cap]= max(-prices[idx]+kuch(prices,idx+1,0,cap,dp), kuch(prices,idx+1,1,cap,dp));
     }
     
      return dp[idx][buy][cap]=  max(prices[idx]+kuch(prices,idx+1,1,cap-1,dp), kuch(prices,idx+1,0,cap,dp));

    }

    int maxProfit(int k,vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return kuch(prices,0,1,k,dp);

        
    }
};