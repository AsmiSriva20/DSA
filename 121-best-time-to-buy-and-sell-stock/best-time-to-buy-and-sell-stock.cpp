class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=INT_MIN;
       
        int cheapestyet= prices[0];
        for(int i=1;i<prices.size();i++){
          cheapestyet=min(cheapestyet,prices[i]);
          int profit=prices[i]-cheapestyet;
          maxprofit=max(profit,maxprofit);
        }
       return maxprofit==INT_MIN? 0: maxprofit; 
    }
};