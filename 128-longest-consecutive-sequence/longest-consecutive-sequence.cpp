class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int maxlen=1;int currlen=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]) continue;
            else if(nums[i]==nums[i-1]+1) currlen++;
            else {maxlen=max(maxlen,currlen);
            currlen=1;}
        }
        return max(maxlen,currlen);
        
    }
};