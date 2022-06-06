/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
            return nullptr;
        ListNode *curA = headA;
        ListNode *curB = headB;
        
        while (curA != curB) {
            if (curA == NULL) curA = headB;
            else curA = curA->next;
            if (curB == NULL) curB = headA;
            else curB = curB->next;
        }
        return curA;
    }
};