class Solution {
public:
    int num_of_partitions(vector<int>&nums, int maxsum){
        long long sum=0;
        int parts=1;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=maxsum){
                sum+=nums[i];
            }
            else{
                parts++;
                sum=nums[i];
            }
        }

    return parts;
    }
    int splitArray(vector<int>& nums, int k) {
        int low= *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid= low+(high-low)/2;
            int partitions=num_of_partitions(nums,mid);
           
            if(partitions>k) low=mid+1;
            else high=mid-1;
        }

return low;
        
    }
};