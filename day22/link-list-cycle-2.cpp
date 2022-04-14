/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        if(!head->next)
            return NULL;
        ListNode *slow=head,*fast=slow;
        bool hasLoop=false;
        while(slow&&fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                hasLoop=true;
                break;
            }
        }
        if(!hasLoop)
            return NULL;
        slow=head;
        while(slow!=fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
        
    }
};