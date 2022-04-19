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
    bool subroot(TreeNode *p,TreeNode *q){
        if(!p || !q)
           return p==q;
        return p->val==q->val and subroot(p->left,q->left) and subroot(p->right,q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        // cout<<temp->val;
        if(!root)
            return false;
        return isSubtree(root->left,subRoot)|| isSubtree(root->right,subRoot)||subroot(root,subRoot);        
    }
};