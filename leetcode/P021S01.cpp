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
    ListNode *merge(ListNode *a,ListNode *b) {
        ListNode *result = nullptr;
        if(a == nullptr) {
            return b;
        } else if(b == nullptr) {
            return a;
        }
        if(a->val <= b->val) {
            result = a;
            result->next = merge(a->next,b);
        } else {
            result = b;
            result->next = merge(a,b->next);
        }
        
        return result;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = merge(l1,l2);
        return res;
    }
};
