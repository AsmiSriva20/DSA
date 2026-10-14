class Solution {
public:
    int solve(string s, int i, vector<int> &dp){
        if(i==s.size() ) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        int one = solve(s,i+1,dp);
        int two = 0;
        if(i+1<s.size()){
            int num=stoi(s.substr(i,2));
            if(num>=10 &&num<=26) two+=solve(s,i+2,dp);

        }
        return dp[i]=one+two;
        
    } 
    int numDecodings(string s) {
        vector<int> dp(s.size(),-1);
        return solve(s, 0, dp);
    }
};