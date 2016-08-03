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
    void reverse(ListNode **head) {
        ListNode *prev = nullptr;
        ListNode *cur = *head;
        ListNode *next = nullptr;
        
        while(cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        *head = prev;
    }
    bool isPalindrome(ListNode *a, ListNode *b) {
        while(a != nullptr && b != nullptr) {
            if(a->val != b->val)
                return false;
            a = a->next;
            b = b->next;
        }
        if(a == nullptr && b == nullptr) return true;
        return false;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = nullptr;
        ListNode *newList = nullptr;
        bool res = false;
        
        // No element
        if(head == nullptr) return true;
        
        // One element
        if(head->next == nullptr) return true;
        
        // To find the middle of the linked list
        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // list has odd elements if fast->next is null
        // else even elements
        if(fast == nullptr) {
            prev->next = nullptr;
            reverse(&head);
            res = isPalindrome(head,slow);
            reverse(&head);
            prev->next = slow;
        } else if(fast->next == nullptr) {
            prev->next = nullptr;
            newList = slow->next;
            reverse(&head);
            res = isPalindrome(head,newList);
            reverse(&head);
            prev->next = slow;
        }
        
        return res;
    }
};
