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
    int length(ListNode *l) {
        int len = 0;
        while(l != nullptr) { l = l->next; len++; }
        return len;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        ListNode dummy{0};
        ListNode *newList = &dummy;
        if(len1 == 0) return l2;
        if(len2 == 0) return l1;
        if(len1 < len2) return addTwoNumbers(l2,l1);
        int carry = 0;
        int i;
        for(i=0;i<len2;++i) {
            int a = l1->val;
            int b = l2->val;
            int curSum = a + b + carry;
            carry = curSum/10;
            newList->next = new ListNode(curSum%10);
            l1 = l1->next;
            l2 = l2->next;
            newList = newList->next;
        }
        
        for(;i<len1;++i) {
            int a = l1->val;
            int curSum = a + carry;
            carry = curSum/10;
            newList->next = new ListNode(curSum%10);
            l1 = l1->next;
            newList = newList->next;
        }
        
        if(carry != 0) {
            newList->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
