
class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        Node *slow=head;
        Node *fast=head;
        if(head->next==NULL) return false;
        while(fast!=NULL)
        {
           fast=fast->next;
           if(fast!=NULL) fast=fast->next;
           slow=slow->next;
           if(slow==fast) return true;
            
        }
        return false;
        
    }
};
