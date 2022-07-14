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
    int preIdx = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1); 
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end) {
        if (start > end) return nullptr;
        
        int idx;
        int val = preorder[preIdx++];
        for (int i=start; i<=end; i++) {
            if (inorder[i] == val) {
                idx = i;
                break;
            }
        }
        
        TreeNode* newNode = new TreeNode(val);
        newNode->left = build(preorder, inorder, start, idx-1);
        newNode->right = build(preorder, inorder, idx+1, end);
        
        return newNode;
    }
};