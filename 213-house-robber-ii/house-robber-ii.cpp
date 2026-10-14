class Solution {
public:
    int robHouse(vector<int>&nums,int i,int end,vector<int>&dp){
        if(i>end) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick,notpick;
        pick = nums[i]+robHouse(nums,i+2,end,dp);
        notpick =robHouse(nums,i+1,end,dp);
        return dp[i]=max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        vector<int>dp1(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        if(nums.size()==1)return nums[0];
        int one=robHouse(nums,0,nums.size()-2,dp1);
        int two=robHouse(nums,1,nums.size()-1,dp2);
        return max(one,two);

        
    }
};