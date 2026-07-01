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
    class Nodeval{

    public: 
        int sum; int Minval; int Maxval;

        Nodeval(int sum, int Minval, int Maxval){
            this->sum=sum;
            this->Minval=Minval;
            this->Maxval=Maxval;
        }

    };

    int ans;

    Nodeval postorder(TreeNode* root){

        if(root==NULL) return {0,INT_MAX, INT_MIN};

        Nodeval left=postorder(root->left);
        Nodeval right=postorder(root->right);

        if(root->val<=left.Maxval || root->val>=right.Minval){
            return {max(left.sum,right.sum),INT_MIN, INT_MAX};
        }
        ans=max(ans,left.sum+right.sum+root->val);
        return {left.sum+right.sum+root->val,
                min(root->val,left.Minval),
                max(right.Maxval,root->val)};
    }

    int maxSumBST(TreeNode* root) {
        ans=0;
        postorder(root);
        return ans;

    }
};