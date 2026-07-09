/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy1=new Node(0);
        Node* dummy=dummy1;
        Node* header=head;
        unordered_map<Node*,Node*> mapi;
        while(head){
            Node* curr=new Node(head->val);
            dummy1->next=curr;
            dummy1=dummy1->next;
            mapi[head]=dummy1;
            head=head->next;
        }
        head=header;
        dummy1=dummy->next;
        while(head){
            if(head->random){
                dummy1->random=mapi[head->random];
            }else{
                dummy1->random =NULL;
            }
            dummy1=dummy1->next;
            head=head->next;
        }
        return dummy->next;
    }
};