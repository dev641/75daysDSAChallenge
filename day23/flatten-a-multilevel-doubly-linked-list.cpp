#include<bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

};


class Solution {
public:
    Node *fun(Node *p){
        Node *res=p;
        while(res->next)
            res=res->next;
        return res;
    }
   Node* fun1(Node *p,Node *q){
        Node *curr=p,*currnxt=q;
        while(curr &&currnxt){
        if(curr->child)
        {
            Node *child=fun1(curr->child,curr->child->next);
            Node *tail=fun(child);
            p->next=child;
            child->prev=p;
            p->child=NULL;
            tail->next=q;
            q->prev=tail;
        }
           curr=currnxt;
           currnxt=currnxt->next;
       }
       return p;
    }
    Node* flatten(Node* head) {
      Node *p=head;
      fun1(p,p->next);
      return head;
    }
};
