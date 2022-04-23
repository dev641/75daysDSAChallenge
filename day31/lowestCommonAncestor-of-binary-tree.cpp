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
    // bool find(TreeNode *r,TreeNode* s){
    //     if(!r)
    //         return false;
    //     if(r==s)
    //         return true;
    //     bool left=find(r->left,s);
    //     bool right=find(r->right,s);
    //     return left||right;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return NULL;
        if(root==p||root==q)
            return root;
        TreeNode*left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
         if(left and right)
            return root;
        else if(left)
            return left;
        else
            return right;
    }
};