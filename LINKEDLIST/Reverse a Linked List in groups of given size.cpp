class Solution
{
    public:
    struct node *f(struct node *&temp,int k)
    {
        node *prev=NULL;
        node *curr=NULL;
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
    struct node *reverse (struct node *head, int k)
    { 
      node *temp=head;
      node *start=NULL;
      while(temp!=NULL)
      {
          if(temp==head)
          {
              start=f(temp,k);
              head=temp;
              
          }
          else
          {
              node *t=f(temp,k);
              start->next=temp;
              start=t;
          }
          temp=start->next;
      }
       return head;
    }
};
