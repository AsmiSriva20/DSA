class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>seen;
        int prefixsum=0;int count=0;
        seen[0]=1;
        for(int i=0;i<nums.size();i++){
            prefixsum+=nums[i];
            if(seen.find(prefixsum-k)!=seen.end()) count+=seen[prefixsum-k] ;
            seen[prefixsum]++;
        }
return count;
        
    }
};