/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        queue<Node *> qu;
        qu.push(root);
        
        while (!qu.empty()) {
            Node *prev = nullptr;
            int t = qu.size();
            
            while (t--) {
                Node *node = qu.front();
                qu.pop();
                node->next = prev;
                prev = node;
                
                if (node->right) qu.push(node->right);
                if (node->left) qu.push(node->left);
            }
        }
        
        return root;
    }
};