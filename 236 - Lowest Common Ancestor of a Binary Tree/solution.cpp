/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root == p || root == q) return root;
        
        TreeNode* lnode = LCA(root->left, p, q);
        TreeNode* rnode = LCA(root->right, p, q);
        
        if (lnode && rnode) return root;
        if (lnode) return lnode;
        if (rnode) return rnode;
        
        return nullptr;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return LCA(root, p, q);
    }
};