class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>hash(256,-1);
        int l=0,maxlen=0;
        for(int r=0;r<s.size();r++){
            if(hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            maxlen=max(maxlen,r-l+1);
            hash[s[r]]=r;

        }
        return maxlen;
    }
};