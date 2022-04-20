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
    void fun(string s,vector<string>&res,TreeNode*p){
        if(!p)
            return ;
        if(!p->left and !p->right){
            s+=to_string(p->val);
            res.push_back(s);
            return ;
        }
        fun(s+to_string(p->val)+"->",res,p->left);
         fun(s+to_string(p->val)+"->",res,p->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        fun("",res,root);
        return res;
    }
};