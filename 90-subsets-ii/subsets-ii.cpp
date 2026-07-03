class Solution {
public:

    set<vector<int>> result;
    void pickornotpick(int i, vector<int> & nums, vector<int>& temp){
        if(i>=nums.size()){
         result.insert(temp);
         return;
        }
        temp.push_back(nums[i]);
        pickornotpick(i+1,nums,temp);
        temp.pop_back();
        pickornotpick(i+1,nums,temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<int> temp;
     sort(nums.begin(),nums.end());
     pickornotpick(0,nums,temp);
     return vector<vector<int>>(result.begin(),result.end());
        
    }
};