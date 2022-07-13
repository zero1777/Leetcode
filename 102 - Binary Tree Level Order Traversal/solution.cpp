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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;
        
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            int sz = qu.size();
            vector<int> vec;
            for (int i=0; i<sz; i++) {
                TreeNode *node = qu.front();
                vec.push_back(node->val);
                if (node->left) qu.push(node->left);
                if (node->right) qu.push(node->right);
                qu.pop();
            } 
            ret.push_back(vec);
        }
        
        return ret;
    }
};