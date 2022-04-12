#include<bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
int counter;
    void fun(ListNode*prev,ListNode*curr,int n){
        if(!curr)
            return;
       
     fun(prev->next,curr->next,n);
     counter--;
      if(counter==0){
            ListNode*nxt=curr;
            prev->next=curr->next;
            curr=prev;
            delete nxt;
        }
    }
        
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *curr=head;
         ListNode*prev=new ListNode(-1);
        prev->next=curr;
        counter=n;
        fun(prev,curr,n);
        return prev->next;
    }
};
// int main(){
// ListNode *head= new ListNode(1);
// head->next=new ListNode(2);
// head->next->next=new ListNode(3);
// head->next->next->next=new ListNode(4);
// head->next->next->next->next=new ListNode(5);
// Solution ob;
// ListNode *res=ob.removeNthFromEnd(head,2);
// while(res){
//     cout<<res->val<<" ";
//     res=res->next;
// }
// return 0;
// }