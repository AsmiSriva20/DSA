
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int l = 0, ans = 0;
        int n = nums.size();
        long long total = 0;

        for(int r = 0; r < n; r++) {
            total += nums[r];

            while(1LL * nums[r] * (r - l + 1) - total > k) {
                total -= nums[l];
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
