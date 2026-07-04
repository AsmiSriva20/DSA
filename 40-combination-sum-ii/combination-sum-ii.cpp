class Solution {
public:
    
    void generate(int index,vector<int>& candidates,int target,vector<int> &stored,vector<vector<int>> &ans){
       
       if(target==0){  ans.push_back(stored);
        return;
       }
        
        
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            stored.push_back(candidates[i]);
            generate(i+1,candidates,target-candidates[i],stored,ans);
            stored.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> stored;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        generate(0,candidates,target,stored,ans);
        
        return ans;
    }
};