class Solution {
public:
    int i = 0, sign = 1;

    long long solve(string &s, long long num) {
        if (i == s.size() || !isdigit(s[i])) return num;
        num = num * 10 + (s[i++] - '0');

        if (sign == 1 && num > INT_MAX) return INT_MAX;
        if (sign == -1 && -num < INT_MIN) return -(long long)INT_MIN;

        return solve(s, num);
    }

    int myAtoi(string s) {
        while (i < s.size() && s[i] == ' ') i++;
        if (i < s.size() && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '-' ? -1 : 1;

        long long num = solve(s, 0);
        return sign == 1 ? min(num, (long long)INT_MAX)
                         : max(-num, (long long)INT_MIN);
    }
};