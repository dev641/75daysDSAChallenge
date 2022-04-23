/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.{
    void dfs(TreeNode *root,string &res){
        if(!root)
        {
          res+="NULL,";
            return;
        }
        res+=to_string(root->val)+',';
        dfs(root->left,res);
        dfs(root->right,res);
    }
    string serialize(TreeNode* root) {
        // if(!root)
        //     return "NULL,";
        // return to_string(root->val)+','+serialize(root->left)+serialize(root->right);
        string res="";
        dfs(root,res);
        return res;
    }
    // Decodes your encoded data to tree.
    queue<string>q;
    void fun(string s){
       for(int i=0;i<s.length();i++){
        string res="";
        while(s[i]!=','){
            res+=s[i++];   
        }
        q.push(res);
       }
    }
    TreeNode* helper(){
        
        string x=q.front();
        q.pop();
        if(x=="NULL")
            return NULL;
        TreeNode*root=new TreeNode(stoi(x));
        root->left=helper();
        root->right=helper();
        return root;
    }
    TreeNode* deserialize(string data) {
        fun(data);
        TreeNode*root=helper();
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));