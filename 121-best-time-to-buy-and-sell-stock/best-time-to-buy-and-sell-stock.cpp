class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof=0;
        int minyet=INT_MAX;
        for(int i=0;i<prices.size();i++){
            minyet=min(minyet,prices[i]);
            maxprof=max(maxprof,prices[i]-minyet);
        }
        return maxprof;
        
    }
};