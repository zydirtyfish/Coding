/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !n)
           return head;
        
        ListNode *fast = head,*slow = head;
        
        while(n--){
            fast = fast->next;
        }
        
        if(!fast)
            return head->next;
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};