// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/solutions/4543655/beats-100-recursion-top-down-explained-with-video-c-java-python-js/?envType=daily-question&envId=2024-01-11

my approach>working>
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
public:
    int solveMin(TreeNode* node, int &diff){
        if(!node) return 1e5;
        int left = solveMin(node->left, diff); 
        int right = solveMin(node->right, diff);
        diff = max(diff, (node->val)-left); 
        diff = max(diff, (node->val)-right); 
        return min(node->val, min(left, right));
    }
    int solveMax(TreeNode* node, int &diff){
        if(!node) return 0;
        int left = solveMax(node->left, diff); 
        int right = solveMax(node->right, diff);
        diff = max(diff, left-(node->val)); 
        diff = max(diff, right - (node->val)); 
        return max(node->val, max(left, right));
    }
    int maxAncestorDiff(TreeNode* root) {
        int diff = 0;
        solveMin(root, diff);
        solveMax(root, diff);
        return diff;
    }
};

another cool approach using stl>

class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        const int inf = 1e6;
        
        function<pair<int,int>(TreeNode *)> dfs = [&](TreeNode * node) -> pair<int,int> {
            if(!node)
                return {inf, -inf};
            
            pair<int,int> left = dfs(node -> left);
            pair<int,int> right = dfs(node -> right);
            
            int MIN = min(left.first, right.first);
            int MAX = max(left.second, right.second);
            
            if(node -> left or node -> right)
                ans = max({ans, abs(MIN - node -> val), abs(MAX - node -> val)});
            
            return {min(MIN, node -> val), max(MAX, node -> val)};
        };
        
        dfs(root);
        
        return ans;
    }
};