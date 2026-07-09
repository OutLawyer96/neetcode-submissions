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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root=new TreeNode();
        if(preorder.size()!=0){
            root->val=preorder[0];
        }
        else{
            return nullptr;
        }
        vector<int> inleft;
        vector<int> inright;
        int i=0;
        while(inorder[i]!=preorder[0]){
            inleft.push_back(inorder[i]);
            i++;
        }
        i++;
        while(i!=inorder.size()){
            inright.push_back(inorder[i]);
            i++;
        }
        vector<int> preleft;
        vector<int> preright;
        i=inleft.size();
        for(int j=1;j<=i;j++){
            preleft.push_back(preorder[j]);
        }
        i=preleft.size()+1;
        while(i!=preorder.size()){
            preright.push_back(preorder[i]);
            i++;
        }
        root->left=buildTree(preleft,inleft);
        root->right=buildTree(preright,inright);
        return root;
    }
};
