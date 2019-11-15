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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        int la = get_len(headA);
        int lb = get_len(headB);
        
        while(la > lb){
            headA = headA->next;
            la--;
        }
        
        while(lb > la){
            headB = headB->next;
            lb--;
        }
        
        while(headA){
            if(headA == headB){
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    static int get_len(ListNode *list){
        int cnt = 0;
        ListNode *tmp = list;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        return cnt;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL){
            return NULL;
        }
        
        ListNode *la = headA, *lb = headB;
        while(la&&lb){
            if(la == lb) return la;
            la = la->next;
            lb = lb->next;
            if(la == lb) return la;
            if(la == NULL) la = headB;
            if(lb == NULL) lb = headA;
        }
        return la;
    }
    
};