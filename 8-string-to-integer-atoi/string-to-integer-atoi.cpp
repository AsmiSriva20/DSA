class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long long result = 0;

        while (i < s.size() && s[i] == ' ') i++;

        if (i < s.size() && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '-' ? -1 : 1;

        while (i < s.size() && isdigit(s[i])) {
            result = result * 10 + (s[i++] - '0');

            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;
        }

        return sign * result;
    }
};