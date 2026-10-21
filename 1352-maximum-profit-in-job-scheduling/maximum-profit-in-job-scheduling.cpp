class Solution {
public:
    int solve(int i, vector<vector<int>>&jobs,vector<int>&dp){
        if(i==jobs.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int next = lower_bound(jobs.begin() + i + 1, jobs.end(),
                       vector<int>{jobs[i][1]}) - jobs.begin();// kyaaaa
        int skip= solve(i+1,jobs,dp);
        int take= jobs[i][2]+ solve(next,jobs,dp);
        return dp[i]=max(skip,take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
     vector<vector<int>>jobs(startTime.size(),vector<int>(3));
     vector<int>dp(startTime.size(),-1);
     for(int i=0;i<startTime.size();i++){
        jobs[i][0]=startTime[i];
        jobs[i][1]=endTime[i];
        jobs[i][2]=profit[i];
     }
     sort(jobs.begin(),jobs.end());
     return solve(0,jobs,dp);

    }
};