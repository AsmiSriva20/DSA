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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(root==NULL) return {};
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            int n=q.size();
            vector<int>v;
            for(int i=0;i<n;i++){
            TreeNode* somenode=q.front();

            v.push_back(somenode->val);
            q.pop();
            if(somenode->left) q.push(somenode->left);
            if(somenode->right) q.push(somenode->right);
            
            }
            ans.push_back(v);
        }
return ans;
    }
};