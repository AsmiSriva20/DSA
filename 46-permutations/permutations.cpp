class Solution {
public:
    vector<vector<int>> result;
    int n;
    unordered_set<int> this_set;

    void solve(vector<int>& nums, vector<int>& temp) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (this_set.find(nums[i]) == this_set.end()) {
                this_set.insert(nums[i]);
                temp.push_back(nums[i]);

                solve(nums, temp);

                temp.pop_back();
                this_set.erase(nums[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(nums, temp);
        return result;
    }
};