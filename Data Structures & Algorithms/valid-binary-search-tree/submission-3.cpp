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
    bool check(TreeNode* root,int minval,int maxval){
        if(!root){
            return true;
        }
        if(root->val<=minval||root->val>=maxval){
            return false;
        }
        return check(root->right,root->val,maxval)&&check(root->left,minval,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return check(root,INT_MIN,INT_MAX);
    }
};
