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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1&& !list2||!list2)
            return list1;
        if(!list1)
            return list2;
        if(list1->val>list2->val)
            return mergeTwoLists(list2,list1);
        ListNode*res=list1,*p=res,*curr1=list1->next,*curr2=list2;
        while(curr1&&curr2){
            if(curr1->val<=curr2->val)
            {
                p->next=curr1;
                p=curr1;
                curr1=curr1->next;
            }
            else{
                p->next=curr2;
                p=curr2;
                curr2=curr2->next;
            }
        }
        while(curr1){
             p->next=curr1;
                p=curr1;
                curr1=curr1->next;

        }
        while(curr2){
                p->next=curr2;
                p=curr2;
                curr2=curr2->next;
               
        }
        return res;
        
    }
};