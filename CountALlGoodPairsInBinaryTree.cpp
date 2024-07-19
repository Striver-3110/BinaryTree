
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
public:
    int countPairs(TreeNode* root, int distance) {
        //? approach 1
        bool flg = false;
        int cnt = 0;
        dfs(root, distance, cnt);
        return cnt;


    }
};
