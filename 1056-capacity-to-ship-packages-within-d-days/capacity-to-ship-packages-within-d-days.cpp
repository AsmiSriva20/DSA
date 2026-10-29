class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<high){
            int load=0;
            int numdays=1;
            int mid=low+(high-low)/2;
            for(int i=0;i<weights.size();i++){
                if(load+weights[i]>mid){
                    numdays++;
                    load=0;
                }
                load+=weights[i];
            }
            if(numdays>days) low=mid+1;
            else high=mid;
        }
       return low; 
    }
};