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
struct compare{
  bool operator()(const ListNode*a, const ListNode*b){
      return a->val>b->val;
  }  
};
class Solution {
public:
    // void insert(ListNode*p,int n){
    //     if(!p){
    //         p=new ListNode(n);
    //     }
    //     else{
    //         p->next=new ListNode(n);     
    //     }
    // }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*,vector<ListNode*>,compare>pq;
        for(auto i:lists){
           if(i) pq.push(i);
        }
        ListNode*head=new ListNode(0);
        ListNode*last=head; 
        if(pq.empty())
            return NULL;
        
        while(!pq.empty()){
            ListNode*curr=pq.top();
            pq.pop();
            last->next=curr;
            last=last->next;
            if(curr->next)
               pq.push(curr->next);
        }
        return head->next;
    }
};