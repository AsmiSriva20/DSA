class Solution {
public:
    int find_days(vector<int> &arr, int cap){
        int d=1; int load=0;
        for(int i=0;i<arr.size();i++){
            if(load+arr[i]>cap){
                d=d+1;
                load= arr[i];
            }
            else load= arr[i]+ load;
        }
        return d;
    }
    int max_of(vector<int> &arr){
        int maxx=INT_MIN;
        for(int i=0;i<arr.size();i++){
         maxx=max(maxx, arr[i]);
         
        }
        return maxx;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=max_of(weights); int high =accumulate(weights.begin(), weights.end(), 0);

        while(low<=high){
            int mid = low+(high-low)/2;
            int num_days= find_days(weights,mid);
            if(num_days<=days){
                high=mid-1;
            }
            else low=mid+1;
        } 
    return low;
    }
};