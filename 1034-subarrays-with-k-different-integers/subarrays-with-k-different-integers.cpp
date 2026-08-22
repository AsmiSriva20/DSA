class Solution {
public:
    int atmost(vector<int> &nums, int k){
        int l=0,r=0,count=0;
        if(k<0) return 0;
        unordered_map<int,int>mpp;
        while(r<nums.size() && l<=r){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            count=count+ r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return atmost(nums,k)-atmost(nums,k-1);
        
    }
};