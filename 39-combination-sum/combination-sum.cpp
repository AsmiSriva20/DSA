class Solution {
public:
    
    void generate(int i,vector<int>& candidates,int target,vector<int> &stored,vector<vector<int>> &ans){
        if(i==candidates.size()){
            if(target==0)  ans.push_back(stored);
            return;
        }
        if(candidates[i]<=target){
        stored.push_back(candidates[i]);
        generate(i,candidates,target-candidates[i],stored,ans);
        stored.pop_back();
        }
        generate(i+1,candidates,target,stored,ans);
        return;


    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> stored;
        vector<vector<int>> ans;
        generate(0,candidates,target,stored,ans);
        return ans;
    }
};