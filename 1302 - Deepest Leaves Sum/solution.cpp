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
    int deepestLeavesSum(TreeNode* root) {
        int ans;
        
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            ans = 0;
            int sz = qu.size();
            while (sz--) {
                TreeNode *cur = qu.front();
                qu.pop();
                
                ans += cur->val;
                if (cur->left) qu.push(cur->left);
                if (cur->right) qu.push(cur->right);
            }
        }
        
        return ans;
    }
};