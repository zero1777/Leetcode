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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        
        queue<pair<TreeNode*, int>> qu;
        qu.push({root, 1});
        while (!qu.empty()) {
            auto [node, lv] = qu.front();
            qu.pop();
            
            if (node->left) qu.push({node->left, lv+1});
            if (node->right) qu.push({node->right, lv+1});
            
            if (qu.empty() || lv != qu.front().second) ret.push_back(node->val);
        }
        
        return ret;
    }
};