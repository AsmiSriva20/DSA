class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>subarr;
        int count=0,prefixsum=0;
        subarr[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(subarr.find(prefixsum-k)!=subarr.end()) count+=subarr[prefixsum-k];
            subarr[prefixsum]++;
        }
        return count;
        
    }
};