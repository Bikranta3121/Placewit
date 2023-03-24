/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
       QueueNode *t=new QueueNode(x);
       if(front==NULL)
       {
           front=t;
           rear=t;
       }
       else
       {
           rear->next=t;
           rear=rear->next;
       }
}


//Function to pop front element from the queue.
int MyQueue :: pop()
{
       int x=-1;
       if(front==NULL) return -1;
       else
       {
          x=front->data;
          front=front->next;
       }
       return x;
}
