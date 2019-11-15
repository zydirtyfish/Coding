/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 2) return mergeTwoLists(lists[0],lists[1]);
        
        int mid = lists.size() / 2;
        vector<ListNode *> v1;
        vector<ListNode *> v2;
        for(int i = 0; i < mid ; i ++){
            v1.push_back(lists[i]);
        }
        for(int i = mid ; i < lists.size() ; i++){
            v2.push_back(lists[i]);
        }
        
        ListNode *l1 = mergeKLists(v1);
        ListNode *l2 = mergeKLists(v2);
        return mergeTwoLists(l1,l2);
    }
    
    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2){
        if(!l1)return l2;
        if(!l2)return l1;
        
        ListNode new_head(0);
        ListNode *ptr = &new_head;
        while(l1&&l2){
            if(l1->val <= l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        
        while(l1){
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        while(l2){
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
        return new_head.next;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
    
    ListNode *helper(vector<ListNode*>&lists,int start,int end){
        if(start > end) return NULL;
        if(start == end) return lists[start];
        int mid = (start + end) / 2;
        ListNode *l1 = helper(lists,start,mid);
        ListNode *l2 = helper(lists,mid+1,end);
        return mergeTwoLists(l1,l2);
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return NULL;
        if(lists.size() == 1) return lists[0];
        if(lists.size() == 2) return mergeTwoLists(lists[0],lists[1]);
        return helper(lists,0,lists.size()-1);
    }
    
    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2){
        if(!l1)return l2;
        if(!l2)return l1;
        
        ListNode new_head(0);
        ListNode *ptr = &new_head;
        while(l1&&l2){
            if(l1->val <= l2->val){
                ptr->next = l1;
                l1 = l1->next;
            }else{
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        
        while(l1){
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        while(l2){
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
        return new_head.next;
    }
};