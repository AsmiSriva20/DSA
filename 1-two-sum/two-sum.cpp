class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        int remaining;
        for(int i=0;i<nums.size();i++){
            remaining=target-nums[i];
            if(mpp.find(remaining)!=mpp.end()){
                return {mpp[remaining],i};
            }
            mpp[nums[i]]=i;
        }
        return {-1,-1};
    }
};