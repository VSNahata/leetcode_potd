//https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28

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
    void solve(TreeNode* node, int level, pair<int, int>&ans){
        if(!node) return;
        if(ans.first<level){
            ans.first = level;
            ans.second = node->val;
        }
        solve(node->left, level+1, ans);
        solve(node->right, level+1, ans);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(!root->left&& !root->right) return root->val;
        pair<int, int> ans;
        solve(root, 0, ans);
        return ans.second;
    }
};