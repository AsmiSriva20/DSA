class Solution {
public:
    int solve(vector<int>& cuts, int l, int r, vector<vector<int>>& dp) {

    if (r - l < 2) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    int ans = INT_MAX;
    for (int i = l + 1; i < r; i++) {
    int cost = cuts[r] - cuts[l]+ solve(cuts, l, i, dp)+ solve(cuts, i, r, dp);
    ans = min(ans, cost);
        }
        
    return dp[l][r] = ans;
    }

    int minCost(int n, vector<int>& cuts) {

        sort(cuts.begin(), cuts.end());

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return solve(cuts, 0, m - 1, dp);
    }
};