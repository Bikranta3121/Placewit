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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp=headA;
        ListNode *temp1=headB;
        int ha_s=0;
        int hb_s=0;
        while(temp!=NULL)
        {
            ha_s++;
            temp=temp->next;
        }
        while(temp1!=NULL)
        {
            hb_s++;
            temp1=temp1->next;
        }
        int diff=abs(ha_s-hb_s);
        temp=headA;
        temp1=headB;
        if(ha_s>hb_s)
        {
            
            while(diff--)
            {
                temp=temp->next;
            }
            while(temp!=NULL)
            {
                if(temp->val==temp1->val and temp==temp1)
                 return temp;
                temp=temp->next;
                temp1=temp1->next; 
            }
        }
        else
        {
           while(diff--)
            {
                temp1=temp1->next;
            }
            while(temp1!=NULL)
            {
                if(temp->val==temp1->val and temp==temp1)
                 return temp1;
                temp=temp->next;
                temp1=temp1->next; 
            } 
        }
        return NULL;
    }
};
