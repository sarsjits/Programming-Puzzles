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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *tNode = head;
        
        // If the given value is in the beginning 
        while(tNode != nullptr && tNode->val == val) {
            head = tNode->next;
            delete tNode;
            tNode = head;
        }
        
        // If the value is anywhere else
        if(tNode != nullptr) {
            ListNode *prev = nullptr;
            prev = tNode;
            tNode = tNode->next;
            while(tNode != nullptr) {
                if(tNode->val == val) {
                    prev->next = tNode->next;
                    delete tNode;
                    tNode = prev->next;
                } else {
                    prev = tNode;
                    tNode = tNode->next;
                }
            }
        }
        
        return head;
    }
};
