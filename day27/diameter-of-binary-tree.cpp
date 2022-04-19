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
    int dia=0;
    int fun(TreeNode* root){
        if(!root)
            return 0;
        int l=fun(root->left);
        int r=fun(root->right);
        int ans=1+max(l,r);
        dia=max(dia,1+l+r);
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=fun(root);
        ans=max(ans,dia);
        return ans-1;
    }
};

