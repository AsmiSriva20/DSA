
class Solution {
public:
    int solve(vector<array<int, 3>>& jobs, vector<int>& starts, vector<int>& dp, int i) {
        if(i == jobs.size()) return 0;

        int next = lower_bound(starts.begin(), starts.end(), jobs[i][1]) - starts.begin();

        int take = jobs[i][2] + dp[next];
        int skip = dp[i + 1];

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs(n);

        for(int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end());

        vector<int> starts(n), dp(n + 1, 0);

        for(int i = 0; i < n; i++)
            starts[i] = jobs[i][0];

        for(int i = n - 1; i >= 0; i--)
            solve(jobs, starts, dp, i);

        return dp[0];
    }
};
