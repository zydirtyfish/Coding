/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * https://leetcode.com/problems/reverse-linked-list-ii/description/
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || head->next == NULL || m >= n){
            return head;
        }
        
        ListNode new_head(0);
        ListNode *pre_ptr = &new_head,*ptr_tmp,*ptr1;
        pre_ptr->next = head;
        int cnt = 0;
        
        while(pre_ptr){
            if(cnt == m - 1){break;}
            cnt++;
            pre_ptr = pre_ptr->next;
        }
        
        if(cnt != m-1){return head;}
        
        head = ptr1 = pre_ptr->next;
        while(head){
            ptr_tmp = head->next;
            cnt++;
            head->next = pre_ptr->next;
            pre_ptr->next = head;
            head = ptr_tmp;
            if(cnt == n){
                ptr1->next = ptr_tmp;
                break;
            }
        }
        return new_head.next;
    }
};