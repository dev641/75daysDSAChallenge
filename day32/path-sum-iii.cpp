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
//     int count=0;
//     long long sum=0;
//     void solve(TreeNode* root,int tar,vector<int>&temp){
//         if(!root)
//             return;
//         temp.push_back(root->val);
//         solve(root->left,tar,temp);
//         solve(root->right,tar,temp);
        
//         int size=temp.size();
//         for(int i=size-1;i>=0;i--){
//             sum+=temp[i];
//                 if(sum==tar)
//                     count++;
//         }
//         sum=0;
//         temp.pop_back();
//     }
//     int pathSum(TreeNode* root, int targetSum) {
//      vector<int>temp;
//      solve(root,targetSum,temp);
//         return count;
//     }
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL) return 0;
        return pathSum(root->left,sum) + helper(root,sum) + pathSum(root->right,sum);
    }
    
    int helper(TreeNode* root,long long sum){
        if(root == NULL) return 0;
        long long res = 0;
        if(root->val == sum) res++;
        res+=helper(root->left,sum-root->val);
        res+=helper(root->right,sum-root->val);
        return res;
    }
}
};