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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,double>>q;
        double ans=INT_MIN;
        q.push(make_pair(root,0));
        while(!q.empty()){
            int size=q.size();
            double left=q.front().second,right=left;
            while(size--){
            TreeNode * p=q.front().first;
            right=q.front().second;
                q.pop();
            if(p->left)
                q.push({p->left,(right-left)*2});
            if(p->right)
               q.push({p->right,(right-left)*2+1});
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};