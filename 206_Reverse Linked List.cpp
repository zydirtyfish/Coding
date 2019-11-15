/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * https://leetcode.com/problems/reverse-linked-list/
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        
        ListNode new_head(0);
        ListNode *new_ptr = &new_head,*tmp_ptr;
        new_ptr->next = NULL;
        
        while(head){
            tmp_ptr = head->next;
            head->next = new_ptr->next;
            new_ptr->next = head;
            head = tmp_ptr;
        }
        return new_ptr->next;
    }
};