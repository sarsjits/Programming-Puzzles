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
        int lenA = 0, lenB = 0;
        ListNode *tmpA = headA, *tmpB = headB;
        
        while(tmpA != nullptr) {
            lenA++;
            tmpA = tmpA->next;
        }
        while(tmpB != nullptr) {
            lenB++;
            tmpB = tmpB->next;
        }
        tmpA = headA;
        tmpB = headB;
        
        ListNode *tmp;
        int t;
        if(lenA < lenB) {
            tmp = tmpA;
            tmpA = tmpB;
            tmpB = tmp;
            
            t = lenA;
            lenA = lenB;
            lenB = t;
        }
        
        int diff = lenA - lenB;
        int i;
        for(i=0;i<diff;i++) {
            tmpA = tmpA->next;
        }
        
        for(;i<lenA && tmpA != nullptr && tmpB != nullptr;i++) {
            if(tmpA == tmpB) {
                return tmpA;
            }
            tmpA = tmpA->next;
            tmpB = tmpB->next;
        }
        
        ListNode *res = nullptr;
        return res;
    }
};
