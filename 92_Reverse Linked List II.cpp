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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || m >= n){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        
        ListNode new_head(0);
        ListNode *head_ptr = &new_head, *ptr1 = head, *ptr2, *ptr3,*ptr4, *ptr_tmp;
        ListNode *rst = head;
        int cnt = 0;
        while(head){
            cnt++;
            ptr_tmp = head->next;
            if(cnt >= m && cnt <=n){
                if(cnt == m){
                    ptr2 = head;
                }
                if(cnt == n){
                    ptr3 = head;
                    ptr4 = head->next;
                    head->next = head_ptr->next;
                    head_ptr->next = head;
                    break;
                }
                head->next = head_ptr->next;
                head_ptr->next = head;
            }
            
            if(cnt < m){
                ptr1 = head;
            }
            head = ptr_tmp;
        }
        
        if(m == 1){
            ptr2->next = ptr4;
            return ptr3;
        }else{
            ptr1->next = head_ptr->next;
            ptr2->next = ptr4;
            return rst;
        }
        
    }
};