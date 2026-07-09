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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return nullptr;
        }
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }
        ListNode* res=new ListNode();
        ListNode* curr=res;
        while(true){
            if(!list1 && !list2){
                break;
            }
            if(!list1){
                curr->next=list2;
                break;
            }
            if(!list2){
                curr->next=list1;
                break;
            }
            if(list1->val<=list2->val){
                ListNode* nexter=new ListNode(list1->val);
                curr->next=nexter;
                curr=curr->next;
                list1=list1->next;
            }else{
                ListNode* nexter=new ListNode(list2->val);
                curr->next=nexter;
                curr=curr->next;
                list2=list2->next;
            }
        }
        return res->next;
    }
};
