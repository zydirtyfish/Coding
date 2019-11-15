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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        
        ListNode *fast,*slow;
        slow = head->next;
        fast = head->next->next;
        while(fast && fast != slow){
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL) return NULL;
            fast = fast->next;
        }
        if(fast == NULL)    return NULL;
        
        while(head != fast){
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
};