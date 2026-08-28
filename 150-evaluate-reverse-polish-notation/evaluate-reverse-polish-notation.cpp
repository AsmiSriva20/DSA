class Solution {
public:


    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int result;
        unordered_map<string, function<int (int, int) > > mpp = {
            { "+" , [] (int a, int b) { return a + b; } },
            { "-" , [] (int a, int b) { return a - b; } },
            { "*" , [] (int a, int b) { return a * b; } },
            { "/" , [] (int a, int b) { return a / b; } }
        };

        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*"){
                int b=st.top(); st.pop();
                int a=st.top();st.pop();
                result=mpp[tokens[i]](a,b);
                st.push(result);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
        
    }
};