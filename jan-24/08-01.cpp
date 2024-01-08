// https://leetcode.com/problems/range-sum-of-bst/submissions/?envType=daily-question&envId=2024-01-08

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
    int preorder(TreeNode* node, int low, int high){
        if(!node) return 0;
        int left = preorder(node->left, low, high);
        int right = preorder(node->right, low, high);
        if(node->val<=high && node->val>=low)
        return node->val+left+right;
        return left+ right;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return preorder(root, low, high);
    }
};