class Solution {
public:
    set<vector<int>> st;
    void func( vector<int> &nums, vector<int> & temp, int i){
        if(i>=nums.size()){
            st.insert(temp);
            return;
        }
        temp.push_back(nums[i]);
        func(nums,temp,i+1);
        temp.pop_back();
        func(nums,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        func(nums,temp,0);
        return vector<vector<int>>(st.begin(),st.end());
        
    }
};