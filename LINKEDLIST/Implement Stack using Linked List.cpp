void MyStack ::push(int x) 
{
    StackNode *t=new StackNode(x);
    if(top==NULL)
    {
        top=t;
    }
    else
    {
        StackNode *temp=top;
        top=t;
        top->next=temp;
    }
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    int x=-1;
    if(top==NULL) return -1;
    else
    {
        x=top->data;
        top=top->next;
    }
    return x;
}
