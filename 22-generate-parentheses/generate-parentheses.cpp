class Solution {
public:
    vector<string> result;

    void solve(int n,string &s, int open, int close){
        if(s.size()==2*n){
             result.push_back(s);
             return;
           }
        if(open<n){
        s.push_back('(');
        solve(n,s,open+1,close);
        s.pop_back();
        }
        if(close<open){
        s.push_back(')');
        solve(n,s,open,close+1);  
        s.pop_back();
        }
        
    }
   
    vector<string> generateParenthesis(int n) {
        string curr = "";

        solve(n, curr,0,0);
        return result;

        
    }
};