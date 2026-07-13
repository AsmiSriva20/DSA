class Solution {
public:
    int solve(vector<int> &nums, int idx, vector<int> &dp, int start){
        if(idx<0) return 0;
        if (idx<start) return 0;
        if (nums.size() == 1) return nums[0];
        if(dp[idx]!=-1) return dp[idx];
        int take = nums[idx] + solve(nums,idx-2,dp,start);
        int not_take= solve(nums,idx-1,dp,start);
        return dp[idx]= max(take,not_take);

    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);

        return max(solve(nums,nums.size()-2,dp1,0),solve(nums,nums.size()-1,dp2,1));
        
    }
};