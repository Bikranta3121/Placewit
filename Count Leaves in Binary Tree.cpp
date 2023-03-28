void tree_traversal(Node *temp,int &count)
{
    if(!temp) return;
    if(!temp->left and !temp->right)
     count++;
    tree_traversal(temp->left,count);
    tree_traversal(temp->right,count);    
}
int countLeaves(Node* root)
{
   int count=0;
   tree_traversal(root,count);
   return count;
}
