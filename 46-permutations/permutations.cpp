class Solution {
public:
    vector<vector<int>>ans;
    void solver(vector<int>& nums,vector<int>&temp, vector<bool>&tick){
        if(nums.size()==temp.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!tick[i]){
                temp.push_back(nums[i]);
                tick[i]=true;
                solver(nums,temp,tick);
                tick[i]=false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<bool>tick(nums.size(),false);
        solver(nums,temp,tick);
        return ans;
        
    }
};