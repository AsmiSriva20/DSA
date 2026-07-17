class Solution {
public:
    int solve(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if (amount == 0) return 0;
        if (ind >= coins.size() || amount < 0) return 1e9;

        if (dp[ind][amount] != -1) return dp[ind][amount];

        
        int pick = 1 + solve(ind, amount - coins[ind], coins, dp); 
       
        int notPick = solve(ind + 1, amount, coins, dp);

        return dp[ind][amount] = min(pick, notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(0, amount, coins, dp);
        return ans >= 1e9 ? -1 : ans;
    }
};