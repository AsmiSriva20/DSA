class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        char lastChar = (char)0x00;
        int min = 0, max = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == lastChar) continue;

            lastChar = s[i];
            int k = i - 1;
            int j = i + 1;
            while (k >= 0 && s[k] == s[i]) k--;
            while (j < s.length() && s[j] == s[i]) j++;

            while (k >= 0 && j < s.length() && s[j] == s[k]) {
                k--;
                j++;
            }
            if (j - k > max - min) {
                min = k;
                max = j;
            }
        }

        return s.substr(min + 1, max - min - 1);
    }
};