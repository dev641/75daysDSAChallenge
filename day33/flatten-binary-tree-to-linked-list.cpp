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
void helper(TreeNode* left,TreeNode *curr){
        if(!left)
            return ;
        helper(left->left,curr->left);
        TreeNode* right=curr->right;
         TreeNode* t=left;
        while(t->right)
            t=t->right;
        curr->left=NULL;
        curr->right=left;
        t->right=right;
    }
    void flatten(TreeNode* root) {
        if(!root)
            return;
         // while(!root->right)
         //     root=root->right;
         // flatten()
        // if(!root->left)
        //     flatten(root->right);
        // else
        //   helper(root->left,root);
        TreeNode *curr=root;
        while(curr){
            if(!curr->left){
                curr=curr->right;
            }
            else{
                TreeNode *t=curr->left;
                while(t->right)
                    t=t->right;
                t->right=curr->right;
                curr->right=curr->left;
                curr->left=NULL;
                curr=curr->right;
            }
        }
        
    }
};