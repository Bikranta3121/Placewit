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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* node=head;
        ListNode* prev=head;
        while(node!=NULL)
        {
           if(head->val==val)
           {
               head=head->next;
               node=head;
               prev=head;
           }
           else if(node->val==val)
           {
             prev->next=node->next;
             node=node->next;
           } 
           else
           {
               prev=node;
               node=node->next;
           }

        }
        
        return head;
    }
};
