class Solution {
public:
    bool solve(string &s, int l,int r){
        int n= s.size();
        if(l>=r) return true;
        if(s[l]==s[r]){
            return solve(s,l+1,r-1);
        }
        return false;
        
    }
    string longestPalindrome(string s) {

        int n=s.size();
        int maxlen=INT_MIN;
        int start=0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1>maxlen){
                        maxlen=j-i+1;
                        start=i;
                    }
                }
            }
        }

       return s.substr(start,maxlen); 
    }
};