class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>sset(nums.begin(),nums.end());
        int lcs=0;

        for(auto s:sset){
            int curr=0;
            int count=0;
            if(s==INT_MIN || !sset.count(s-1)){
                curr=s;
                count=1;
                while( curr!=INT_MAX && sset.count(curr+1)){
                    count++;
                    curr=curr+1;
                }
lcs= max(count,lcs);
            }
            
        }
      return lcs;  
    }
};
