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
    ListNode*res=NULL,*h2;
    int c=0;
    void Sum(int n,int m){ 
         ListNode *t=new ListNode((n+m+c)%10);
         t->next=res;
         res=t;
        c= (n+m+c)/10;
    }
    void iterate(ListNode*p,ListNode*q){
        if(!p and !q)
        {
            return;
        }
          iterate(p->next,q->next);
          Sum(p->val,q->val);
    }
    void adjust(ListNode *p,ListNode*q,int diff){
        if(diff==0)
        {
            iterate(p,q);
            return;
        } 
        adjust(p->next,q,diff-1); 
        Sum(p->val,0);  
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 and !l2)
            return NULL;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int len1=0,len2=0;
        ListNode*p=l1,*q=l2;
        h2=l2;
        while(p||q){
            if(p)
            {
                len1++;
                p=p->next;
            }
            if(q){
                len2++;
                q=q->next;
            }
        }
        if(len1>len2)
          adjust(l1,l2,len1-len2);
        else adjust(l2,l1,len2-len1);
         if(c!=0)
        {
            ListNode *t=new ListNode(c);
            t->next=res;
            res=t;
        }
        return res;
    }
};
// int main(){
// int n,m;
// cin>>n>>m;
// vector<int>v1(n,0),v2(m,0);
// for(int i=0;i<n;i++)
//  cin>>v1[i];
//  for(int i=0;i<m;i++)
//  cin>>v2[i];
// Solution ob;
// ListNode *l1=NULL,*l2=NULL;
// for(int i=n-1;i>=0;i--){
//     ListNode*t=new ListNode(v1[i],l1);
//     l1=t;
// }

// for(int i=m-1;i>=0;i--){
//     ListNode*t=new ListNode(v2[i],l2);
//     l2=t;
// }
// ListNode *res= ob.addTwoNumbers(l1,l2);
// while(res)
//   {
//       cout<<res->val<<" ";
//       res=res->next;
//   }
// return 0;
// }