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
    TreeNode* tmp = nullptr;
    void preorder(TreeNode* root) {
        if (!root) return ;
        preorder(root->right);
        preorder(root->left);
        
        root->left = nullptr;
        root->right = tmp;
        tmp = root;
    }
    void flatten(TreeNode* root) {
        preorder(root);
    }
};