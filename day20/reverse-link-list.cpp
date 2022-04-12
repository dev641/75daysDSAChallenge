#include<bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        if(head==NULL)
         return head;

        ListNode* q=head,*p=head,*r=NULL;
        while(p->next!=NULL){
           p=p->next;
           q->next=r;
           r=q;
           q=p;
     
        }
        q->next=r;
        return q;
    }
 
};
