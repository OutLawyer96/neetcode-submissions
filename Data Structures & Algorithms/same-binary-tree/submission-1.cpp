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
    int dfs(TreeNode* p, TreeNode* q){
        if(!p&&!q){
            return 0;
        }else if(!p||!q){
            return -1;
        }
        int l=dfs(p->left,q->left);
        int r=dfs(p->right,q->right);
        if(l==-1||r==-1||(p->val!=q->val)){
            return -1;
        }
        return 1+max(l,r);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p,q)!=-1;
    }
};
