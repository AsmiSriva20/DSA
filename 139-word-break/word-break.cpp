class Solution {
public:
    bool solver(string s,int i,unordered_set<string>dict,vector<int>&dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<s.size();j++){
            string substrg= s.substr(i,j-i+1);
            if(dict.find(substrg)!=dict.end()){
                if(solver(s,j+1,dict,dp)) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        unordered_set<string>dict(wordDict.begin(),wordDict.end());
        return solver(s,0,dict,dp);
        
    }
};