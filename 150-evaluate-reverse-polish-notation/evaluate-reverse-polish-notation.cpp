class Solution {
public:
    int operate(int a,int b, string &ch){
        if(ch=="+"){
            return a+b;
        }
        if(ch=="-"){
            return a-b;
        }
        if(ch=="/"){
            return a/b;
        }
        if(ch=="*"){
            return a*b;
        }
        else return 0;
    }


    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int result;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"||tokens[i]=="*"){
                int b=st.top(); st.pop();
                int a=st.top();st.pop();
                result=operate(a,b,tokens[i]);
                st.push(result);
            }
            else st.push(stoi(tokens[i]));
        }
        return st.top();
        
    }
};