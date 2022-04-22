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
    int sum=0;
    void fun(TreeNode* p,int flag){
      if(!p)
          return ;
    if(!p->left and !p->right){
          if(flag==1)
          sum+=p->val;
        return;
    }
        fun(p->left,1);
        fun(p->right,2);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        fun(root,0);
       return sum;
        
    }
};
