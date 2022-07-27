/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flat(Node* cur) {
        Node *right;
        while (cur) {
            if (!cur->next) right = cur;
            if (cur->child) {
                Node *tmp = flat(cur->child);
                tmp->next = cur->next;
                if (cur->next) cur->next->prev = tmp;
                
                cur->next = cur->child;
                cur->child->prev = cur;
                cur->child = nullptr;
            }
            cur = cur->next;
        }
        return right;
    }
    Node* flatten(Node* head) {
        flat(head);
        return head;
    }
};