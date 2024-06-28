#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

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
public:
    // Method 1: Using DFS and backtracking
    void maxD(int& cnt, int& mx, TreeNode* root) {
        if (!root) return;
        cnt++;
        maxD(cnt, mx, root->left);
        maxD(cnt, mx, root->right);
        mx = max(mx, cnt);
        cnt--;
    }

    int maxDepthBacktracking(TreeNode* root) {
        int cnt = 0;
        int mx = 0;
        maxD(cnt, mx, root);
        return mx;
    }

    // Method 2: Using DFS with global variable
    int ans = 0;
    
    void dfs(TreeNode* root, int cnt) {
        if (!root) {
            ans = max(ans, cnt);
            return;
        }
        dfs(root->left, cnt + 1);
        dfs(root->right, cnt + 1);
    }

    int maxDepthDFS(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

    // Method 3: Using DFS and returning depth directly
    int Dfs(TreeNode* root) {
        if (!root) return 0;
        
        int left = Dfs(root->left);
        int right = Dfs(root->right);
        
        return max(left, right) + 1;
    }

    int maxDepthDirectDFS(TreeNode* root) {
        return Dfs(root);
    }

    // Method 4: Using Level Order Traversal
    int maxDepthLevelOrder(TreeNode* root) {
        if (!root) return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }
        
        return depth;
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
    
    cout << "Max Depth (Backtracking): " << solution.maxDepthBacktracking(root) << endl;
    cout << "Max Depth (DFS with Global Variable): " << solution.maxDepthDFS(root) << endl;
    cout << "Max Depth (Direct DFS): " << solution.maxDepthDirectDFS(root) << endl;
    cout << "Max Depth (Level Order): " << solution.maxDepthLevelOrder(root) << endl;

    // Clean up the allocated memory
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
