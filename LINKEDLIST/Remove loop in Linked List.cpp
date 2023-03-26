class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        Node *slow=head;
        Node *fast=head;
        int count=0;
        while( fast and fast->next )
        {
            fast=fast->next;
            if(fast->next) fast=fast->next;
            slow=slow->next;
            if(fast==slow) break;
        }
        if(!fast || !fast->next) return;
        else    
        {
         slow=head;
         while(slow!=fast)
         {
            slow=slow->next;
            fast=fast->next;
         }
         
         while(fast->next!=slow)
         {fast=fast->next;}
          fast->next=NULL;
        }
   
