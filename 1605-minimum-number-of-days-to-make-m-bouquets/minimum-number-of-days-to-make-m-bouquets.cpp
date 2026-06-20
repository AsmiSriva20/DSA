class Solution {
public:
    int min_of_days(vector<int> &arr){
        int minday= INT_MAX;
        for(int i=0;i<arr.size();i++){
            if(arr[i]<minday) minday=arr[i];
        }
        return minday;
    }

    int max_of_days(vector<int> &arr){
        int maxday= INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>maxday) maxday=arr[i];
        }
        return maxday;
    }
    bool possible(vector<int>& bloomDay, int m, int k,int day){
        int count=0; int bouquet =0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }
            else {bouquet+=(count/k);
            count=0;
            }
        }
        bouquet+=count/k;
        return bouquet>=m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if( 1LL *m * k > bloomDay.size()) return -1;
        int low= min_of_days(bloomDay);
        int high =max_of_days(bloomDay);
        while(low<=high){
            int mid= low+(high -low)/2;
            if(possible(bloomDay, m, k, mid)){
                high=mid-1;
             }
             else low=mid+1;
        }
       return low; 
    }
};