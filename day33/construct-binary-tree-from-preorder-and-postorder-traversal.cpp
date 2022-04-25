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
    int pindex=0;
    TreeNode *fun(vector<int>preorder,vector<int>postorder,int l,int r,int size){
        if(pindex>size || l>r)
            return NULL;
        TreeNode *root=new TreeNode(preorder[pindex]);
        pindex++;
        if(l==r)
            return root;
        int i;
        for(i=l;i<=r;i++){
            if(preorder[pindex]==postorder[i])
                break;
        }
        if(l<=r){
          root->left=  fun(preorder,postorder,l,i,size);
          root->right=fun(preorder,postorder,i+1,r-1,size);
        }
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if(preorder.size()==0)
            return NULL;
        return fun(preorder,postorder,0,preorder.size()-1,preorder.size());
    }
};