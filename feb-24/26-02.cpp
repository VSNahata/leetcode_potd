// https://leetcode.com/problems/same-tree/submissions/1187895591/?envType=daily-question&envId=2024-02-26

class Solution {
public:
    bool preorder(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if(!p || !q) return false;
        return p->val == q->val && preorder(p->left, q->left) && preorder(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p, q);
    }
};