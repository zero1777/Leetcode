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
class BSTIterator {
public:
    queue<int> qu;
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    void inorder(TreeNode* root) {
        if (root) {
            inorder(root->left);
            qu.push(root->val);
            inorder(root->right);
        }
    }
    
    int next() {
        int val = qu.front();
        qu.pop();
        
        return val;
    }
    
    bool hasNext() {
        return !qu.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */