class Solution {
public:

    int lcs(string &s, string &t, int i, int j,vector<vector<int>>&dp){
        if(i>=s.size() || j>=t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(s[i]==t[j]){
        take = 1+lcs(s,t,i+1,j+1,dp);
        }
        int skip = max(lcs(s,t,i,j+1,dp),lcs(s,t,i+1,j,dp));
        int ans = max(take,skip);
        return dp[i][j]= ans;

    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        vector<vector<int>>dp(s.size(),vector<int>(t.size(),-1));
        reverse(t.begin(),t.end());
        return lcs(s,t,0,0,dp);
        
    }
};