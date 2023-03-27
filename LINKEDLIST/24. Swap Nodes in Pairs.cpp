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
    struct ListNode *f(struct ListNode *&temp,int k)
    {
        ListNode *prev=NULL;
        ListNode *curr=NULL;
        while(k-- and temp!=NULL)
        {
            curr=temp->next;
            temp->next=prev;
            prev=temp;
            temp=curr;
        }
        temp=prev;
        while(prev->next!=NULL)
        {
            prev=prev->next;
        }
        prev->next=curr;
        return prev;
    }
    ListNode* swapPairs(ListNode* head) {
      ListNode *temp=head;
      ListNode *start=NULL;
      while(temp!=NULL)
      {
          if(temp==head)
          {
              start=f(temp,2);
              head=temp;
              
          }
          else
          {
              ListNode *t=f(temp,2);
              start->next=temp;
              start=t;
          }
          temp=start->next;
      }
       return head;
    }
};
