// https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09


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
    void solve(TreeNode* node, vector<int> &leaf){
        if(!node) return;
        if(!node->left&& !node->right) leaf.push_back(node->val);
        solve(node->left, leaf);
        solve(node->right, leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1;
        vector<int> leaf2;
        solve(root1, leaf1);
        solve(root2, leaf2);
        for(auto leaf:leaf1){
            cout<< leaf<<" ";
        }
        cout<< endl;
        for(auto leaf:leaf2){
            cout<< leaf<<" ";
        }
        // cout<< endl<<leaf1;
        return (leaf1 == leaf2);
    }
};

/*
yeh recursion aise likha ki solve saare roots laake de dega toh first node pr decision yeh lena tha ki yaa toh woh hi first node hai toh usko vector mein daal do nahi toh aage ke nodes pr toh function call karna hi hai
*/