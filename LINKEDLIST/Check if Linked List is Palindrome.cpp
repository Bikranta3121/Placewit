
class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *temp=head;
        Node *temp1=NULL;
        Node *temp2=NULL;
        while(temp!=NULL)
        {
            Node* t=new Node(temp->data);
            if(temp1==NULL)
            {
                temp1=t;
                temp2=temp1;
            }
            else
            {
                temp2->next=t;
                temp2=temp2->next;
            }
            temp=temp->next;
        }
        Node *prev_head=NULL;
        Node *next_head=NULL;
        while(head->next!=NULL)
        {
           next_head=head->next;
           head->next=prev_head;
           prev_head=head;
           head=next_head;
        }
        head->next=prev_head;
        while(head!=NULL)
        {
            if(head->data!=temp1->data) return false;
            head=head->next;
            temp1=temp1->next;
        }
        return true;
    }
};
