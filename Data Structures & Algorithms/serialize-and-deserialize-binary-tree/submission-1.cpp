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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        queue<TreeNode*> q;
        q.push(root);
        string s="";
        s+=to_string(root->val);
        s+=',';
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(!curr->left){
                s+="#,";
            }else{
                s+=to_string(curr->left->val)+',';
                q.push(curr->left);
            }
            if(!curr->right){
                s+="#,";
            }else{
                s+=to_string(curr->right->val)+',';
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return nullptr;
        }
        stringstream ss(data);
        string token;
        vector<string> vals;
        while(getline(ss,token,',')){
            vals.push_back(token);
        }
        TreeNode* root=new TreeNode(stoi(vals[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i=1;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(i>=vals.size() || vals[i]=="#"){
                i++;
            }else{
                curr->left=new TreeNode(stoi(vals[i]));
                q.push(curr->left);
                i++;
            }
            if(i>=vals.size() || vals[i]=="#"){
                i++;
            }else{
                curr->right=new TreeNode(stoi(vals[i]));
                q.push(curr->right);
                i++;
            }
        }
        return root;
    }
};
