class Solution {
public:
    void letterComb(string digits, string op,int i,vector<string>& ans,string map[]){
        {
            if(i>=digits.length()){
                ans.push_back(op);
                return;
            }
            int num=digits[i]-48;
            string value =map[num];
            for(int j=0;j<value.length();j++){
                op.push_back(value[j]);
                letterComb(digits,op,i+1,ans,map);
                op.pop_back();
            }

        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string op;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        letterComb(digits,op,0,ans,map);
        return ans;

        
    }
};