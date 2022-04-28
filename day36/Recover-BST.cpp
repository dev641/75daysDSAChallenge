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
    TreeNode*prev,*first,*sec;
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(!first and prev and prev->val>root->val)
            first=prev;
        if(first and prev->val>root->val)
            sec=root;
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
     
        inorder(root);
        swap(first->val,sec->val);
    }
};