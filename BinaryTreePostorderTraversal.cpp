#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    void postorder(std::vector<int> &in, TreeNode* root){
        if(!root){
            return;
        }

        postorder(in, root->left);
        postorder(in, root->right);
        in.push_back(root->val);
    }
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> in;
        postorder(in, root);
        return in;
    }
};

int main() {
    // Create a sample binary tree:
    //       1
    //        \
    //         2
    //        /
    //       3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    // Create an instance of Solution and test the inorderTraversal method
    Solution solution;
    std::vector<int> result = solution.postorderTraversal(root);

    // Print the result
    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up the allocated memory
    delete root->right->left;
    delete root->right;
    delete root;

    return 0;
}
