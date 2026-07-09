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
    int maxDepth(TreeNode* root,int maxi=1) {
        if(root==nullptr){
            return 0;
        }
        cout<<root->val<<endl;
        if(root->left!=nullptr && root->right!=nullptr){
            maxi=max(maxDepth(root->left,maxi+1),maxDepth(root->right,maxi+1));
        }else if(root->left==nullptr && root->right!=nullptr){
            maxi=maxDepth(root->right,maxi+1);
        }else if(root->left!=nullptr && root->right==nullptr){
            maxi=maxDepth(root->left,maxi+1);
        }
        return maxi;
    }
};
