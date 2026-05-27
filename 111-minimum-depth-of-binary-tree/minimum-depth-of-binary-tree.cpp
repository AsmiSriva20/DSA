/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(root && !root->left && !root->right){
            return 1;
        }
        int lefth = INT_MAX , righth = INT_MAX;

         if(root->left){
            lefth = 1 + minDepth(root->left);
        }

        if(root->right){
            righth = 1 + minDepth(root->right);
        }

        return min(lefth, righth);
    }
};