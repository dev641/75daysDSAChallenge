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
    
    vector<int>res;
    int val=INT_MIN;
    void fun(TreeNode* root,int& c,int k){
        if(!root)
            return;
        fun(root->left,c,k);
        // res.push_back(root->val);
        c++;
        if(c==k)
        {
          if(val==INT_MIN)
                val=root->val;
        }
        fun(root->right,c,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        fun(root,c,k);
        return val;   
    }
};