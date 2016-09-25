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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *prev = head;
        ListNode *cur = head->next;
        head = cur;
        while(true) {
            ListNode *next = cur->next;
            cur->next = prev;
            if(next == nullptr || next->next == nullptr) {
                prev->next = next;
                break;
            }
            prev->next = next->next;
            prev = next;
            cur = next->next;
        }
        return head;
    }
};
