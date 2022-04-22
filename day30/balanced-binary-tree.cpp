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
    bool ans=true;
    int height(TreeNode*p){
        if(!p)
            return 0;
        // if(!p->left and !p->right )
        //     return 1;
        return 1+max(height(p->left),height(p->right));
    }
    void dfs(TreeNode*t){
        if(!t)
            return ;
        if(abs(height(t->left)-height(t->right))>1){
            ans=false;return;
        }
        if(ans){
            dfs(t->left);
            dfs(t->right);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        dfs(root);
        return ans;
    }
};