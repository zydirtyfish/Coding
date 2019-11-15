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
    ListNode* partition(ListNode* head, int x) {
        ListNode low(0),great(0);
        ListNode *lp = &low, *gp = &great;
        while(head){
            if(head->val < x){
                lp->next = head;
                lp = lp->next;
            }else{
                gp->next = head;
                gp = gp->next;
            }
            head = head->next;
        }
        lp->next = great.next;
        gp->next = NULL;
        return low.next;
    }
};