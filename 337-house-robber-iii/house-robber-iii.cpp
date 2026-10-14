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
    int robHouse(TreeNode* root, unordered_map<TreeNode*,int>&dp){
        if(root==NULL) return 0;
        if(dp.find(root)!=dp.end())return dp[root];
        int pick,notpick;
        pick=root->val;
        if(root->left) pick+=robHouse(root->left->left,dp)+robHouse(root->left->right,dp);
        if(root->right) pick+=robHouse(root->right->left,dp)+robHouse(root->right->right,dp);
        notpick=robHouse(root->left,dp)+robHouse(root->right,dp);
        return dp[root] = max(pick,notpick);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>dp;
        return robHouse(root,dp);
    }
};