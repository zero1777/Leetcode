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
    TreeNode *ans, *tgt;
    void preorder(TreeNode *o, TreeNode *c) {
        if (!o) return ;
        
        if (o == tgt) {
            ans = c;
            return ;
        }
        
        if (o->left) preorder(o->left, c->left);
        if (o->right) preorder(o->right, c->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        tgt = target;
        preorder(original, cloned);
        return ans;
    }
};