#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    
    vector<int> postorderTraversal2stack(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<int> post;
        if(!root){
            return post;
        }
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();st1.pop();
            st2.push(node);
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
        }
        while(!st2.empty()){
            TreeNode* node = st2.top(); st2.pop();
            post.push_back(node->val);
        }
        return post;
    }
    vector<int> postorderTraversal1stack(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        vector<int> post;
        if(!root){
            return post;
        }
        st1.push(root);
        while(!st1.empty()){
            TreeNode* node = st1.top();st1.pop();
            post.push_back(node->val);
            if(node->left)st1.push(node->left);
            if(node->right)st1.push(node->right);
        }
        int i = 0, j = post.size()-1;
        while(i <= j){
            int temp = post[i];
            post[i] = post[j];
            post[j] = temp;
            i++;j--;
        }
        return post;
    }
};

int main() {
    // Example binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution solution;
    vector<int> result = solution.postorderTraversal2stack(root);

    for (const auto& level : result) {
        cout<<level<<" ";
    }

    // Clean up the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
