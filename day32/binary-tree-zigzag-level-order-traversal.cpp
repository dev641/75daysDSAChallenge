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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         queue<pair<TreeNode*,int>>q;
//         vector<vector<int>>res;
//         if(!root)
//             return res;
//         q.push({root,0});    
//         while(!q.empty()){
//             pair<TreeNode*,int>p=q.front();
//             q.pop();
//              cout<<p.second<<" "<<p.first->val<<"\t";
//             if(p.second<res.size()){
//                 res[p.second].push_back(p.first->val);
//             }
//             else{
//                 res.push_back({p.first->val});
//             }
//             if(p.first->left)
//                     q.push({p.first->left,p.second+1});
//                 if(p.first->right)
//                 q.push({p.first->right,p.second+1});
// //             if(p.second%2==0){
// //                 if(p.first->right)
// //                 q.push({p.first->right,p.second+1});
// //                 if(p.first->left)
// //                     q.push({p.first->left,p.second+1});
// //             }
// //             else{
                
// //             }
//         }
//         for(int i=1;i<res.size();i+=2){
//             reverse(res[i].begin(),res[i].end());
//         }
//         return res;
        
        vector<vector<int>> ans;
        
        vector<int> row;
        
        queue<TreeNode *> q;
        
        int left = 1;
        
        if(root == NULL)
            return ans;
        
        q.push(root);
        
        while(!q.empty()) {
            
            
            TreeNode *curr;
            
            int size = q.size();
            
            for(int i = 0; i < size; i++) {  
            
                curr = q.front();
                q.pop();
                row.push_back(curr->val);    
                if(curr->left)
                    q.push(curr->left);
                
                if(curr->right)
                    q.push(curr->right);   
            }
            
            if(left) {
                ans.push_back(row);
            }
            else {
                reverse(row.begin(),row.end());
                ans.push_back(row);
            }
            row.clear();
            left = !left;
        }
        
        return ans;
    }
};