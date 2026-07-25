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
    int dfs(TreeNode* root,int& ans){
        if(!root->left && !root->right){
            ans=max(ans,root->val);
            return root->val;
        }
        int l=0;
        int r=0;
        if(root->left){
            l=max(l,dfs(root->left,ans));
        }
        if(root->right){
            r=max(r,dfs(root->right,ans));
        }
        ans=max(ans,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        int ans=root->val;
        dfs(root,ans);
        return ans;
    }
};
