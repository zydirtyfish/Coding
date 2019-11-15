/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode head(0);
        ListNode *new_head = &head;
        
        while(l1 && l2){
            if(l1->val < l2->val){
                new_head->next = l1;
                new_head = new_head->next;
                l1 = l1->next;
            }else{
                new_head->next = l2;
                new_head = new_head->next;
                l2 = l2->next;
            }
        }
        
        while(l1){
            new_head->next = l1;
            l1 = l1->next;
            new_head = new_head->next;
        }
        
        while(l2){
            new_head->next = l2;
            new_head = new_head->next;
            l2 = l2->next;
        }
        
        new_head->next = NULL;
        return head.next;
    }
};