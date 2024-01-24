// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/submissions/1155417832/?envType=daily-question&envId=2024-01-24

there is another method of bitmasking , video dekh ke seekh lena, waise yeh bhi kaafi elegant question hai.

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
    // this function returns the no. of pseudo palindromic paths from the given node to the leaf.
    void solve(TreeNode* node, int need, vector<int>&f, int &count, int &ans){
        if(!node) return ;
        int val = node->val;
        
        f[val]^=1;
        if(f[val]) count++;
        else count--;

        if(!node->left && !node->right){
            if(need == count) ans++;
        }

        solve(node->left, need^1, f,count,  ans);
        solve(node->right, need^1, f,count,  ans);

        f[val]^=1;
        if(!f[val]) count--;
        else count++;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(10, 0);
        int ans = 0;
        int count = 0;
         solve(root, 1, f,count,  ans);
        return ans;

    }
};