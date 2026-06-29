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
    void inorder(int &count,int &ans, TreeNode* root, int k){
    if(root==NULL) return;
    inorder(count,ans,root->left,k);
    count++;
    if(count==k){
        ans=root->val;
        return;
    }
    inorder(count,ans,root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
     int count=0;
     int ans;
     inorder(count,ans,root,k);
     return ans;
        
    }
};