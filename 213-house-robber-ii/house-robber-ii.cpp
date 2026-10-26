class Solution {
public:
    int robb(vector<int>&nums,int i,int end,vector<int> &dp){
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick= nums[i]+robb(nums,i+2,end,dp);
        int notpick= robb(nums,i+1,end,dp);
        return dp[i]= max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
      int last=  robb(nums,1,nums.size()-1,dp1);
      int first=  robb(nums,0,nums.size()-2,dp2);
     return max(last,first);
    }
};