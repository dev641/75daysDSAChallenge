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
        queue<pair<TreeNode*,int>>q;
        vector<vector<int>>res;
        if(!root)
            return res;
        q.push({root,0});    
        while(!q.empty()){
            pair<TreeNode*,int>p=q.front();
            q.pop();
             cout<<p.second<<" "<<p.first->val<<"\t";
            if(p.second<res.size()){
                res[p.second].push_back(p.first->val);
            }
            else{
                res.push_back({p.first->val});
            }
            if(p.first->left)
                    q.push({p.first->left,p.second+1});
                if(p.first->right)
                q.push({p.first->right,p.second+1});
//             if(p.second%2==0){
//                 if(p.first->right)
//                 q.push({p.first->right,p.second+1});
//                 if(p.first->left)
//                     q.push({p.first->left,p.second+1});
//             }
//             else{
                
//             }
        }
        return res;
    }
};