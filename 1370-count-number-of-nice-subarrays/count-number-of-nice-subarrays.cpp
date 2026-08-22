class Solution {
public:
    int atmost(vector<int>&nums, int k){
        int l=0,r=0,count=0,odd=0;
        if(k<0) return 0;
        while(r<nums.size()){
             odd+=nums[r]%2;
             while(odd>k){
                odd-=nums[l]%2;
                l++;
             }
             count+=r-l+1;
             r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
        
    }
};