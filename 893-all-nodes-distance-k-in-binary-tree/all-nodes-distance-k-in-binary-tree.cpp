/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>v;
        map<TreeNode*,TreeNode*>mp;
        queue<TreeNode*>q;
        q.push(root);
        mp[root]=nullptr;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *t=q.front();
                q.pop();
                if(t->left)
                {
                    q.push(t->left);
                    mp[t->left]=t;
                }
                if(t->right)
                {
                    q.push(t->right);
                    mp[t->right]=t;
                }

            }
        }
        unordered_set<TreeNode*>vis;
        vis.insert(target);
        q.push(target);
        int c=0;
        while(!q.empty() && c!=k)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *t=q.front();
                q.pop();
                if(t->left && vis.find(t->left)==vis.end())
                {
                    q.push(t->left);
                    vis.insert(t->left);
                }
                if(t->right && vis.find(t->right)==vis.end())
                {
                    q.push(t->right);
                    vis.insert(t->right);
                }
                if(mp[t] && vis.find(mp[t])==vis.end())
                {
                    q.push(mp[t]);
                    vis.insert(mp[t]);
                }
            }
            c++;
        }
        if(q.empty()) return {};
        while(!q.empty())
        {
            v.push_back(q.front()->val);
            q.pop();
        }
        return v;
    }
    
};