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
    bool isValid(TreeNode *root,long min,long max){
        if(!root)
            return true;
        
        if((root->val <=min )||(root->val>=max))
            return false;
      
           bool left=isValid(root->left,min,root->val);
           bool right=isValid(root->right,root->val,max);
    
        return  left and right;
            
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        return isValid(root,LONG_MIN,LONG_MAX) ;
    }
};