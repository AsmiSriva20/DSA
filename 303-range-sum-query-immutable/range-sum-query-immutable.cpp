class NumArray {
private:
    vector<int> preSums;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int& num: nums) {
            sum += num;
            preSums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return left == 0 ? preSums[right] : preSums[right] - preSums[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */