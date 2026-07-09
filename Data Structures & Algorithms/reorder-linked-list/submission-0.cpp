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
    void reorderList(ListNode* head) {
        if(!head || !head->next){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=nullptr;
        slow=nullptr;
        while(fast){
            ListNode* next=fast->next;
            fast->next=slow;
            slow=fast;
            fast=next;
        }
        fast=head;
        while(slow){
            ListNode* next=fast->next;
            ListNode* nexter=slow->next;
            fast->next=slow;
            slow->next=next;
            fast=next;
            slow=nexter;
        }
    }
};
