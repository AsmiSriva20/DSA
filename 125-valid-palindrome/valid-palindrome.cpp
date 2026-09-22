class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";

        for(auto it : s) {
            it = tolower(it);

            if(isalnum(it))
                ans.push_back(it);
        }

        int l = 0, r = ans.size() - 1;

        while(l <= r) {
            if(ans[l] != ans[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
};