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
    int maxi=INT_MIN;
    int func(TreeNode* node){
        if(node==NULL) return 0;
        int l= max(0,func(node->left));
        int r= max(0,func(node->right));
        maxi=max(maxi,l+r+node->val);
        return max(l,r)+ node->val;
    }
    int maxPathSum(TreeNode* root) {
        func(root);
        return maxi;
        
    }
};