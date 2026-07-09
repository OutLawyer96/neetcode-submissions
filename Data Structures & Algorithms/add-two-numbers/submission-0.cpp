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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans=new ListNode;
        ListNode* curr=new ListNode;
        int carry=0;
        int res=l1->val+l2->val+carry;
        carry=res/10;
        curr->val=res%10;
        ans=curr;
        l1=l1->next;
        l2=l2->next;
        while(l1 || l2){
            if(l1 && l2){
                res=l1->val+l2->val+carry;
                carry=res/10;
                ListNode* next=new ListNode(res%10);
                curr->next=next;
                curr=next;
                l1=l1->next;
                l2=l2->next;
            }
            else if(!l1){
                res=l2->val+carry;
                carry=res/10;
                ListNode* next=new ListNode(res%10);
                curr->next=next;
                curr=next;
                l2=l2->next;
            }else if(!l2){
                res=l1->val+carry;
                carry=res/10;
                ListNode* next=new ListNode(res%10);
                curr->next=next;
                curr=next;
                l1=l1->next;
            }
        }
        if(carry>0){
            ListNode* next=new ListNode(carry);
            curr->next=next;
        }
        return ans;
    }
};