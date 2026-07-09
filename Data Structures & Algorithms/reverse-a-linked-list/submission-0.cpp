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
    ListNode* reverser(ListNode* head,ListNode* res){
        ListNode* back=new ListNode();
        if(!head){
            return res;
        }
        back->val=head->val;
        back->next=res;
        return reverser(head->next,back);
    }
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* res=new ListNode(head->val);
        res=reverser(head->next,res);
        return res;
    }
};
