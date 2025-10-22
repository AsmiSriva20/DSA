class Solution {
public:
    string largestOddNumber(string num) {
        int r=num.size()-1;
        while(r>=0)
        {
           if((num[r]-'0')&1){break;};
            r--;
        }
        return num.substr(0,r+1);
    }
};