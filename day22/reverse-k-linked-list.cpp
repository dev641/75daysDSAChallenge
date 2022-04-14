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
    ListNode*tail=NULL,*nextHead;
    ListNode* reverse(ListNode*p1,int k){
        int count=0;
        ListNode* r=p1,*q=p1,*s=NULL;
        tail=p1;
        while(count<k-1){
              q=q->next;
              r->next=s;
              s=r;
              r=q;
            count++;
        }
        nextHead=r->next;
        r->next=s;
        return r;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=0;
        ListNode* p=head;
        while(p){
            len++;
            p=p->next;
        }
        int timer=len/k;
        int j=0;
        ListNode*front=reverse(head,k);
        head=front;
        ListNode *ltail=tail;
        tail->next=nextHead;
        j++;
        p=tail->next;
        while(j<timer){
           front=reverse(p,k);
           ltail->next=front;
           ltail=tail;
           tail->next=nextHead;
           p=nextHead;
           j++;
        }
        return head;
    }
};
int main(){
int n;
cin>>n;
vector<int>v1(n,0);
for(int i=0;i<n;i++)
 cin>>v1[i];

Solution ob;
ListNode *l1=NULL;
for(int i=n-1;i>=0;i--){
    ListNode*t=new ListNode(v1[i],l1);
    l1=t;
}

ListNode *res= ob.reverseKGroup(l1,4);
while(res)
  {
      cout<<res->val<<" ";
      res=res->next;
  }
return 0;
}