
class Solution {
public:
    int solve(vector<vector<int>>& jobs, int i, vector<int>& dp) {
        if (i == jobs.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int skip = solve(jobs, i + 1, dp);

        int j = lower_bound(jobs.begin() + i + 1, jobs.end(),
                            vector<int>{jobs[i][1], 0, 0}) - jobs.begin();

        int take = jobs[i][2] + solve(jobs, j, dp);

        return dp[i] = max(take, skip);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));

        for (int i = 0; i < n; i++)
            jobs[i] = {startTime[i], endTime[i], profit[i]};

        sort(jobs.begin(), jobs.end());

        vector<int> dp(n, -1);
        return solve(jobs, 0, dp);
    }
};
