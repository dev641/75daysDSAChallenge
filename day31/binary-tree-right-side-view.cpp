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
    vector<int>res;
    void fun(TreeNode*r){
        if(!r)
            return ;
        queue<pair<TreeNode* ,int>>q;
        q.push({r,0});
        int level=0;
        while(!q.empty()){
            pair<TreeNode*,int>p=q.front();
            q.pop();
            if(p.second==level)
            {
                res.push_back(p.first->val);
                level++;
            }
            if(p.first->right)
            q.push({p.first->right,p.second+1});
             if(p.first->left)
            q.push({p.first->left,p.second+1});
        }
        
            
    }
    vector<int> rightSideView(TreeNode* root) {
       
        fun(root);
        return res;
    }
};