class Solution
{
    public:
    Node* pairWiseSwap(struct Node* head) 
    {
        Node *temp=NULL;
        Node *temp1=NULL;
        Node *fast=head;
        Node *prev=NULL;
        int flag=0;
        while(fast!=NULL and fast->next!=NULL)
        {
          temp=fast;
          temp1=fast->next;
          fast=fast->next->next;
          temp1->next=temp;
          temp->next=fast;
          if(!flag)
          {
              flag=1;
              head=temp1;
          }
          else
          {
              prev->next=temp1;
          }
          prev=temp;
        }
        
        
        return head;
    }
};
