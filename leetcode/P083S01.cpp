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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res = head;
        if(head == nullptr) return res;
        while(res != nullptr && res->next != nullptr) {
            if(res->val == (res->next)->val) {
                ListNode *tmp = res->next;
                res->next = (res->next)->next;
                delete tmp;
            } else {
                res = res->next;
            }
        }
        return head;
    }
};
