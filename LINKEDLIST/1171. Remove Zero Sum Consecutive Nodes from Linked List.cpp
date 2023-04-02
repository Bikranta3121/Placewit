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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode *temp=head;
        ListNode *t1=head;
        ListNode *fake=new ListNode(0);
        fake->next=head;
        head=fake;
        while(head)
        {
           t1=head->next;
           int sum=0; 
           while(t1)
           {
               sum+=t1->val;
               if(sum==0)
               {
                head->next=t1->next;
               }
               t1=t1->next;
           }
           head=head->next;
        }
        head=fake;
        head=head->next;
        return head;
    }
};
