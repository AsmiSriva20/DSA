class Solution {
public:
    int robHouse(vector<int> &nums,int i,vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick,notpick;
        pick=nums[i]+robHouse(nums,i+2,dp);
        notpick=robHouse(nums,i+1,dp);
        return dp[i]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return robHouse(nums,0,dp);
        
    }
};