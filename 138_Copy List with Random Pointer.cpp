/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
* https://leetcode.com/problems/copy-list-with-random-pointer/description/
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        
        Node *tmp = head;
        unordered_map<Node *,int> index_map;
        vector<Node *> new_node;
        int cnt = 0;
        
        while(tmp){
            index_map[tmp] = cnt++;
            Node *nt = new Node(tmp->val,NULL,NULL);
            new_node.push_back(nt);
            tmp = tmp->next;
        }
        
        for(int i = 0 ; i < new_node.size() ; i ++){
            
            if(i == new_node.size()-1){
                new_node[i]->next = NULL;
            }else{
                new_node[i]->next = new_node[i+1];
            }
            
            if(head->random != NULL){
                new_node[i]->random = new_node[index_map[head->random]];
            }else{
                new_node[i]->random = NULL;
            }
            head = head->next;
        }
        
        return new_node[0];
    }
};