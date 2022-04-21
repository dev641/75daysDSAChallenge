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
    int res=INT_MAX,prev=-1;
    void fun(TreeNode *p){
         if(!p)
            return;
        fun(p->left);
        if(prev!=-1)
            res=min(abs(p->val-prev),res);
        prev=p->val;
        fun(p->right);
    }
    int getMinimumDifference(TreeNode* root) {
        // stack<TreeNode*>st;
        // int res=INT_MAX;
        // TreeNode* curr=root,*prev=NULL;
        // while(curr!=NULL || !st.empty()){
        //     if(curr!=NULL){
        //         st.push(curr);
        //         curr=curr->left;
        //     }
        //     else {
        //         TreeNode *t=st.top();
        //         st.pop();
        //         if(prev!=NULL){
        //             res=min(res,curr->val-prev->val);
        //         }
        //         prev=curr;
        //         curr=curr->right;
        //     }
        // }
        // return res;
       fun(root);
        return res;
    }
};