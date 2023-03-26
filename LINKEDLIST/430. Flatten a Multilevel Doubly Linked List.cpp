/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void func(Node *&temp)
    {
        Node *t1=temp->child;
        Node *t2=temp->next;
        Node *t3=t1;
        
        while(t3->next!=NULL)
        {
          t3=t3->next;
        }
        if(t2)
        {
         t2->prev=t3;
         t3->next=t2;
        }
        temp->next=t1;
        t1->prev=temp;
        temp->child=NULL;
    }
    void f(Node *&temp)
    {
        if(temp==NULL)
         return;
        if(temp->child)
        {
           f(temp->child);
           func(temp);
        }  
        f(temp->next);
    } 
    Node* flatten(Node* head) {
       f(head);
       return head;
    }
};
