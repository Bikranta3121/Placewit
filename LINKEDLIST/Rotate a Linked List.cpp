class Solution
{
    public:
    Node* f(Node *&temp,int k)
    {
        Node *curr=temp->next;
        Node *prev=NULL;
        while(k-- and temp!=NULL)
        {
            temp->next=prev;
            prev=temp;
            temp=curr;
            curr=temp->next;
        }
        
        while(prev->next!=NULL)
        {
            prev=prev->next;
        }
        prev->next=curr;
        return prev;
    }
    Node* rotate(Node* head, int k)
    {
      Node *temp=head;
      Node *curr=head;
      while(curr->next!=NULL)
      {
          curr=curr->next;
      }
      curr->next=head;
      while(k--)
      {
          temp=temp->next;
      }
      head=temp;
      while(temp->next!=head)
      {
          temp=temp->next;
      }
      temp->next=NULL;
     
      return head;
    }
};
