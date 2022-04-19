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
    TreeNode *prev = nullptr;
    TreeNode *first = nullptr, *second;
    void recoverTree(TreeNode* root) {
        inorderTraverse(root);
        swap(first->val, second->val);
    }
    void inorderTraverse(TreeNode* root) {
        if (!root) return ;
        if (root->left) inorderTraverse(root->left);
        
        if (prev) {
            if (!first && prev->val > root->val) {
                first = prev;
                second = root;
            }
            
            if (first && root->val < second->val) {
                second = root;
            }
        }
        prev = root;
        
        if (root->right) inorderTraverse(root->right);
    }
};