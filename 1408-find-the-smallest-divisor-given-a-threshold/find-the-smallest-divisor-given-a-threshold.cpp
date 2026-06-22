class Solution {
public:
    int max_element(vector<int> &arr){
        sort(arr.begin(),arr.end());
        return arr[arr.size()-1];
    }
    int sum_of_ceils(vector<int> &arr, int k){
        int sum=0;
        for(int i=0;i<arr.size();i++){
           sum += (arr[i] + k - 1) / k;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1; int high = max_element(nums);
        
        while(low<=high){
            int mid= low+(high-low)/2;
            if(sum_of_ceils(nums,mid)<=threshold) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};