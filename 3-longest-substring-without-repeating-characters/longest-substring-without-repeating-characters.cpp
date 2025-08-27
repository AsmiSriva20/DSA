class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0; 

        for (int i = 0; i < n; i++) {
            int hash[256] = {0};  
            string substr = "";

            for (int j = i; j < n; j++) {
                if (hash[s[j]] == 1) break;  
                substr += s[j];
                hash[s[j]] = 1;

                int len = substr.size();
                maxlen = max(len, maxlen);
            }
        }
        return maxlen;
    }
};
