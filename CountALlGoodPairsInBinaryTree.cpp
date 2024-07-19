
class Solution {
    vector<int> dfs(TreeNode* node, int &d, int &cnt){
        if(!node->left && !node->right){
            return {1};
        }

        vector<int> left, right;
        if(node->left) 
            left = dfs(node->left, d, cnt);
        if(node->right)
            right = dfs(node->right, d, cnt);


        for(int i = 0; i < size(left); i++){
            for(int j = 0; j < size(right); j++){
                if(left[i] + right[j] <= d) cnt++;
            }
        }

        vector<int> ret;
        for(int i = 0 ; i < size(left); i++){
            left[i]++;
            if(left[i] < d) ret.push_back(left[i]);
        }
        for(int i = 0 ; i < size(right); i++){
            right[i]++;
            if(right[i] < d) ret.push_back(right[i]);
        }
        return ret;
    }
    
    void getLeaves(TreeNode* node, vector<nodePos> &leaves, int64_t depth, int64_t pos){
        if(node->left != nullptr){
            getLeaves(node->left, leaves, depth+1, pos);
        }
        if(node->right != nullptr){
            getLeaves(node->right, leaves, depth+1, pos | int64_t(1) << depth);
        }
        if(node->left == nullptr && node->right == nullptr){
            nodePos n;
            n.depth = depth;
            n.pos = pos;
            leaves.emplace_back(n);
        }
    }
public:
    int countPairs(TreeNode* root, int distance) {
        //? approach 1
        // bool flg = false;
        // int cnt = 0;
        // dfs(root, distance, cnt);
        // return cnt;


        std:: vector<nodePos> leaves;
        getLeaves(root, leaves, 0, 0); //( node, leaves[], depth, pos);
        int result = 0;

        for(size_t i = 0; i < size(leaves) - 1; i++){
            auto fd = leaves[i].depth;
            auto fp = leaves[i].pos;
            for(size_t j = i+1; j < size(leaves); j++){
                auto sd = leaves[j].depth;
                auto sp = leaves[j].pos;

                auto diff = __builtin_ctzl(fp ^ sp);

                auto d = fd + sd - 2*diff;
                if(d == 0 && fd != sd){
                    d = std::abs(fd-sd);
                }
                result += d <= distance;
            }
        }
        return result;

    }
};
