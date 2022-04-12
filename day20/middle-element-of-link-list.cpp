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
    // int count(ListNode *p){
    //     int count=0;
    //     while(p){
    //         count++;
    //         p=p->next;
    //     }
    //     return count;
    // }
    // ListNode* middleNode(ListNode* head) {
    //     int coun=count(head)/2;
    //     while(coun--){
    //         head=head->next;
    //     }
    //     return head;
    // }
    ListNode*res,*first;
    void fun(ListNode* p){
        if(!p)
            return;
        fun(p->next);
        if(first->next==p||first==p)
            res=p;
        first=first->next;
    }
    ListNode* middleNode(ListNode* head) {
      first=head;
      fun(head);
        return res;
        
    }
};