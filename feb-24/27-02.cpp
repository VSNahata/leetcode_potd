//https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27

class Solution {
public:
    int dfs(TreeNode *root, int &maxi){
        if(root == nullptr) return 0;

        int lh = dfs(root->left,maxi);
        int rh = dfs(root->right,maxi);

        maxi = max(maxi,lh+rh);

        return 1+max(lh,rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};