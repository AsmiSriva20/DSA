class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>>mpp;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string temp;
            temp=strs[i];
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(strs[i]);
        }
        for(auto it:mpp){
            result.push_back(it.second);
        }
        return result;
    }
};