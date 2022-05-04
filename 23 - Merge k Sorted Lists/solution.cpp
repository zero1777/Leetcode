/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    #define pr pair<ListNode*, int> 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](pr a, pr b) { return a.second > b.second; };
        priority_queue<pr, vector<pr>, decltype(compare)> pq(compare);
        
        ListNode *dummy = new ListNode(), *tail;
        tail = dummy;
        
        for (auto list : lists) 
            if (list) pq.push({list, list->val});
        
        while (!pq.empty()) {
            auto [node, num] = pq.top();
            pq.pop();
            tail = tail->next = node;
            if (node->next) pq.push({node->next, node->next->val});
        }
        
        return dummy->next;
    }
};