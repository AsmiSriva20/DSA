class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cheapest_yet=prices[0];
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            maxprofit=max(maxprofit,prices[i]-cheapest_yet);
            cheapest_yet=min(cheapest_yet,prices[i]);
        }
        return maxprofit;
        
    }
};