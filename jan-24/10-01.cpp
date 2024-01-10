// https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/?envType=daily-question&envId=2024-01-10
// simple sa approach hai graph banao fir rotten oranges wala approach lagao
// iska ek aur variation hai but usmein start hmesha leaf node hona chahiye fir jo tum sochoge woh ho jayega.

// here's my solution
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
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>> g;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                g[node->val].push_back(node->left->val) ;
                g[node->left->val] .push_back(node->val) ;
                q.push(node->left);
            }
            if(node->right){
                g[node->val].push_back(node->right->val);
                g[node->right->val].push_back(node->val) ;
                q.push(node->right);
            }
        }

        int time = 0;
        queue<pair<int, int>> qu;
        qu.push({start, time});
        unordered_set<int> vis;
        vis.insert(start);
        while(!qu.empty()){
            pair<int, int> curr = qu.front();
            qu.pop();
            for(auto nnode: g[curr.first]){
                if(vis.find(nnode) == vis.end()){
                    vis.insert(nnode);
                    time = curr.second +1 ;
                    qu.push({nnode, time});
                }
            }
        }
        return time;
    }
};

// another solution which i didn't understand
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        int ans = 0;
        map<TreeNode *, int> height;
        height[nullptr] = 0;
        
        function<int(TreeNode *)> dfs1 = [&](TreeNode * node) -> int {
            if(!node)
                return -1;
            
            int left = dfs1(node -> left);
            int right = dfs1(node -> right);
            
            return height[node] = max(left, right) + 1;
        };
        
        function<void(TreeNode *, int)> dfs2 = [&](TreeNode * node, int prev) {
            if(!node)
                return;
            
            if(node -> val == start){
                ans = max(prev, height[node]);
                return;
            }
            
            int left = (node -> left) ? height[node -> left] + 1 : 0;
            int right = (node -> right) ? height[node -> right] + 1 : 0;
            
            dfs2(node -> left, 1 + max(prev, right));
            dfs2(node -> right, 1 + max(prev, left));
        };
        
        dfs1(root);
        dfs2(root, 0);
        
        return ans;
    }
};
