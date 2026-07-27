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
struct Compare {
    bool operator()(pair<ListNode*,int>& a, pair<ListNode*,int>& b) {
        return a.first->val > b.first->val;  
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<ListNode*,int>,vector<pair<ListNode*,int>>,Compare> pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i],i});
                lists[i]=lists[i]->next;
            }
        }
        if(pq.size()==0){
            return nullptr;
        }
        ListNode* front=pq.top().first;
        int k=pq.top().second;
        if(lists[k]){
            pq.push({lists[k],k});
            lists[k]=lists[k]->next;
        }
        ListNode* curr=front;
        pq.pop();
        while(!pq.empty()){
            auto now=pq.top();
            pq.pop();
            curr->next=now.first;
            curr=curr->next;
            if(lists[now.second]){
                pq.push({lists[now.second],now.second});
                lists[now.second]=lists[now.second]->next;
            }
        }
        return front;
    }
};
