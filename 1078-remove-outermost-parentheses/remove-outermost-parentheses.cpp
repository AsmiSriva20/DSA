class Solution {
public:
    string removeOuterParentheses(string s) {
        int counter=0;
        int n=s.size();
        string ans= "";
        for(int i=0;i<n;i++){
           if (s[i] == ')') counter--;
           if (counter != 0) ans.push_back(s[i]);
           if (s[i] == '(') counter++;

            
        }
       return ans; 
    }
};