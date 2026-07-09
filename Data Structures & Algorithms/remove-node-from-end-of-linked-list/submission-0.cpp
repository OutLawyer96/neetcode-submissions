/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next){
            return nullptr;
        }
        ListNode* curr=head;
        ListNode* next=head;
        for(int i=1;i<n;i++){
            next=next->next;
        }
        if(!next->next){
            return head->next;
        }
        while(next->next->next){
            curr=curr->next;
            next=next->next;
        }
        if(n==1){
            curr->next=nullptr;
        }else{
            curr->next=curr->next->next;
        }
        return head;
    }
};
