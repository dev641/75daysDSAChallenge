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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(k==0)
            return head;
        if(!head->next)
            return head;
        int len=1;
        ListNode*temp=head,*t=NULL;
        while(temp->next){
            len++;
            temp=temp->next;
        }
        int d=len-k%len;
        temp->next=head;
         while(d--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
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
ListNode *l1=NULL,*l2=NULL;
for(int i=n-1;i>=0;i--){
    ListNode*t=new ListNode(v1[i],l1);
    l1=t;
}

ListNode *res= ob.rotateRight(l1,2);
while(res)
  {
      cout<<res->val<<" ";
      res=res->next;
  }
return 0;
}