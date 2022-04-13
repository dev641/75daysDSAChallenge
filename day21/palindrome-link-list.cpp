#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool res=true;
    ListNode* first;
    void fun(ListNode* p){
        if(!p)
            return;
        fun(p->next);
        if(first->val!=p->val)
        {
            res=false;
        }
        first=first->next;
    }
    bool fun1(string s){
        int i=0,j=s.length()-1;
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
//        if(!head)
//            return false;
        
//         first=head;
//         fun(head);
//         return res;
        string s="";
        while(head){
            s+=to_string(head->val);
            head=head->next;
        }
        return fun1(s);
    }
};
// int main(){
// ListNode *head= new ListNode(1);
// head->next=new ListNode(2);
// head->next->next=new ListNode(3);
// head->next->next->next=new ListNode(2);
// head->next->next->next->next=new ListNode(1);
// Solution ob;
// bool res=ob.isPalindrome(head);
// cout<<res;
// return 0;
// }