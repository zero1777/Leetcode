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
    int maxPath = -1;
    int maxZigZag(TreeNode* node, int direction) {
        if (!node) return -1;
        int ret;
        
        // right
        if (direction == 1) {
            ret = maxZigZag(node->left, -1) + 1;
            maxPath = max(maxPath, maxZigZag(node->right, 1) + 1);
        }
        // left
        else {
            ret = maxZigZag(node->right, 1) + 1;
            maxPath = max(maxPath, maxZigZag(node->left, -1) + 1);
        }
        
        return ret;
    }
    int longestZigZag(TreeNode* root) {
        return max(maxZigZag(root, 1), maxPath);
    }
};