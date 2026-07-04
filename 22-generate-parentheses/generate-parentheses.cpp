class Solution {
public:
    vector<string> result;

    bool isValid(string s){
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[0]==')') return false;
            if(s[i]=='(') count++;
            else count--;    
            if(count<0) return false;
        }
        if(count==0) return true;
        else return false;
    }

    void solve(int n,string &s){
        if(s.size()==2*n){
           if(isValid(s))
             result.push_back(s);
             return;
           }
        s.push_back('(');
        solve(n,s);
        s.pop_back();

        s.push_back(')');
        solve(n,s);  
        s.pop_back();
        
    }
   
    vector<string> generateParenthesis(int n) {
        string curr = "";
        solve(n, curr);
        return result;

        
    }
};