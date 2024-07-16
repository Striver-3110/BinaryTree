/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return new TreeNode(-1);
        if(root == p){
            return p;
        }
        if(root == q){
            return q;
        }

        TreeNode* left = dfs(root->left,p,q);
        TreeNode* right = dfs(root->right,p,q);
        if(left->val != -1 && right->val != -1)return root;
        if(left->val != -1)return left;
        return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};