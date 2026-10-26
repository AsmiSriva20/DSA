class Solution {
public:
    int robb(vector<int>&nums,int i,vector<int> &dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick= nums[i]+robb(nums,i+2,dp);
        int notpick= robb(nums,i+1,dp);
        return dp[i]= max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return robb(nums,0,dp);
    }
};