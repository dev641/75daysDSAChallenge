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
    unordered_map<TreeNode*,TreeNode*>mp;
     unordered_map<TreeNode*,bool>vis;
    void dfs(TreeNode* r){
        if(!r)
            return;
        vis[r]=false;
        if(r->right)
           mp[r->right]=r;
        if(r->left)
           mp[r->left]=r;
        dfs(r->left);
        dfs(r->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
         dfs(root);
        vector<int>res;
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
       
        while(!q.empty()){
            pair<TreeNode*,int>p=q.front();
             q.pop();
            if(!vis[p.first]){
                vis[p.first]=true;
                   if(p.second==k){
                res.push_back(p.first->val);
            }
            else{
                int x=p.second+1; 
             if(mp.find(p.first)!=mp.end())
                   q.push({mp[p.first],x});
            if(p.first->left)
                   q.push({p.first->left,x});
             if(p.first->right)
                   q.push({p.first->right,x});
            }
            }
        }
        return res;
    }
};