class Solution {
public:
    bool ispalin(string s,int l, int r){
        while(l<=r){
        if(s[r]!=s[l]) return false;
        r--;l++;
        
        }
        return true;
    }
    bool validPalindrome(string s) {
        int l=0; int r=s.size()-1;
        if(s.size()==1) return true;
        while(r>=l){
            if(s[r]!=s[l]){
            return ispalin(s,l+1,r)|| ispalin(s,l,r-1);}
            l++;r--;
        }
     return true;   
    }
};