class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<int,int>mpp;
        int l=0; int count=0;
        for(int r=0;r<s.size();r++){
            mpp[s[r]]++;
            while(mpp.size()==3){
                 count+=s.size()-r;
                 mpp[s[l]]--;
                 if(mpp[s[l]]==0) mpp.erase(s[l]);
                 l++;
            }
            
                
            }
            return count;
        }

        
    
};