class Solution {
public:

    class nodevalue {
    public:
        int sum;
        int minval;
        int maxval;

        nodevalue(int sum, int minval, int maxval) {
            this->sum = sum;
            this->minval = minval;
            this->maxval = maxval;
        }
    };

    int ans;

    nodevalue postorder(TreeNode* root) {

        if(root == NULL)
            return {0, INT_MAX, INT_MIN};

        nodevalue left = postorder(root->left);
        nodevalue right = postorder(root->right);

        if(root->val <= left.maxval || root->val >= right.minval)
            return {max(left.sum, right.sum), INT_MIN, INT_MAX};

        ans = max(ans, left.sum + right.sum + root->val);

        return {
            left.sum + right.sum + root->val,
            min(root->val, left.minval),
            max(root->val, right.maxval)
        };
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        postorder(root);
        return ans;
    }
};