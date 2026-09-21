class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>seen;
        int remaining;
        for(int i=0;i<nums.size();i++){
            remaining=target-nums[i];
            if(seen.find(remaining)!=seen.end()) return {seen[remaining],i};
            seen[nums[i]]=i;
        }

       return {-1,-1}; 
    }
};