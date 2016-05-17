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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;
        ListNode *one,*two,*prev;
        one = head; two = head; prev = NULL;
        
        int i = 0;
        while(i<n) {
            one = one->next;
            i++;
        }
        
        while(one != NULL) {
            prev = two;
            two = two->next;
            one = one->next;
        }
        if(prev != NULL) {
            prev->next = two->next;
        } else {
            head = head->next;
        }
        return head;
    }
};
