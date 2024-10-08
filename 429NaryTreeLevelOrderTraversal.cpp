/*
Definition for a Node.
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
    vector<vector<int>> levelOrder(Node* root) {
        // handle the base case
        // The total number of nodes is between [0, 10^4]
        if(!root) return {};


        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int s = q.size();
            vector<int> temp;
            while(s--){
                Node * node = q.front(); q.pop();
                temp.push_back(node->val);
                for(auto &child: node->children){
                    q.push(child);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};