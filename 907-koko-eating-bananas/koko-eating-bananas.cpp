class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1; int high=*max_element(piles.begin(),piles.end());
        while(low<high){
            int mid=low-(low-high)/2;
            int hours=0;
            for(int i=0;i<piles.size();i++){
                hours+=(piles[i]+mid-1)/mid;
            }
            if(hours>h) low=mid+1;
            else high=mid;
        }
     return low;
    }
};