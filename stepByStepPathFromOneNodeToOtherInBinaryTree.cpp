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
private:
    TreeNode* findAncestor(TreeNode* root, int s, int d){
        if(!root){
            return new TreeNode(-1);
        }
        if(root->val == s){
            return root;
        }
        if(root->val == d){
            return root;
        }

        TreeNode* left = findAncestor(root->left, s, d);
        TreeNode* right = findAncestor(root->right, s, d);

        if(left->val != -1 && right->val != -1)return root;
        if(left->val != -1) return left;
        return right;
    }
    void dfs(TreeNode* node, string &str, bool &flg, int &p){
        if(!node){
            return;
        }
        if(node->val == p){
            flg = true;
        }

        if(!flg){
            str += "L";
            dfs(node->left,str, flg, p);
        }
        if(!flg) str.pop_back();
        if(!flg) str += "R", dfs(node->right,str, flg, p);
        if(!flg) str.pop_back();
        return ;
    }
public:
    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* ancestor = findAncestor(root, s, d);

        string str1 = "", str2 = "";
        bool flg = false;


        dfs(ancestor, str1, flg, s);

        flg = false;
        
        dfs(ancestor, str2, flg, d);

        string ans = "";
        for(auto &ch: str1){
            ans+='U';
        }
        ans += str2;

        return ans;
    }
};