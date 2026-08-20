class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0,count=0,maxone=0;
        while(r<nums.size() && l<nums.size()){
            if(nums[r]==1) count++;
            else {
                l=r+1;
                count=0;
            }
            maxone=max(maxone,count);
            r++;
        }
        return maxone;
        
    }
};