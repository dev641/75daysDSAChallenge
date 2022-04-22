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
    int ans=0;
    void fun(TreeNode *p,int maxi){
        if(!p)
            return;
        if(maxi<=p->val)
            ans++;
        maxi=max(maxi,p->val);
        fun(p->left,maxi);
        fun(p->right,maxi);
    }
    int goodNodes(TreeNode* root) {
   
        fun(root,INT_MIN);
        return ans;
    }
};