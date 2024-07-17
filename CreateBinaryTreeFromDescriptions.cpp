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
    TreeNode* createTree(int root, unordered_map<int,vector<pair<int,int>>> &childrens){
        TreeNode* node = new TreeNode(root);
        for(auto& p: childrens[root]){
            if(p.second){
                node->left = createTree(p.first,childrens);
            }else{
                node->right = createTree(p.first,childrens);
            }
        }
        return node;
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,vector<pair<int,int>>> childrens; // (parent, (children, isLeft))
        unordered_map<int,bool> has_parent;

        for(auto &desc: descriptions){
            // desc[0] parent
            // desc[1] children
            // desc[2] isLeft
            childrens[desc[0]].push_back({desc[1],desc[2]});
            has_parent[desc[1]] = true;

            has_parent[desc[0]] |= false;
        }
        // lets now find root of the tree
        // element which does not have parent is root!!
        int root = -1;
        for(auto &elem: has_parent){
            // cout<<elem.first<<" "<<elem.second<<endl;
            if(!elem.second){
                root = elem.first;
                break;
            }
        }
        if(root == -1) return NULL;
        return createTree(root,childrens);
    }
};