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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return NULL;
        ListNode *odd = head, *even = head->next;
        ListNode *evenHead = head->next;
        
        while(1) {
            if(even == nullptr || even->next == nullptr) {
                odd->next = evenHead;
                break;
            }
            odd->next = even->next;
            odd = odd->next;
            
            if(odd->next == nullptr) {
                odd->next = evenHead;
                even->next = nullptr;
                break;
            }
            
            even->next = odd->next;
            even = even->next;
        }
        return head;
    }
};
