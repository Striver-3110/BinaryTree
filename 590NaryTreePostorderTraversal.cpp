/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root) return {}; // The number of nodes in the tree is in the range [0, 10^4].


        vector<int> postOrder;
        // lets create dfs function
        function<void(Node*)> dfs = [&](Node* node) {
            // in post order we will visite all the children and push them into result
            // and at the last we will add the root of the sub tree

            // here node->children is a vector 
            for(auto child: node->children){    
                dfs(child);
                // cout<<child;
            }
            postOrder.push_back(node->val);
        };
        dfs(root);
        return postOrder;

    }
};