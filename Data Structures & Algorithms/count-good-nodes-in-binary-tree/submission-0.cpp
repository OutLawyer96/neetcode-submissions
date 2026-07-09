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
    int count=0;
    bool checker(TreeNode* node,int high){
        if(!node){
            return false;
        }
        if(node->val>=high){
            checker(node->left,node->val); 
            checker(node->right,node->val);
            count++;
            return true;
        }else{
            checker(node->left,high);
            checker(node->right,high);
            return false;
        }
    }
    int goodNodes(TreeNode* root) {
        checker(root,root->val);
        return count;
    }
};
