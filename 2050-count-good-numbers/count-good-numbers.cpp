class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long a, long long n) {
        if (n == 0) return 1;

        long long half = power(a, n / 2);

        if (n % 2 == 0)
            return (half * half) % MOD;

        return (a * half % MOD * half) % MOD;
    }

    int countGoodNumbers(long long n) {
        return (power(5, (n + 1) / 2) * power(4, n / 2)) % MOD;
    }
};