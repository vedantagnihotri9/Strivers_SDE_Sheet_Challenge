Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first==NULL)
        return second;
    if(second==NULL)
        return first;
    Node<int> *l1=first,*l2=second;
    if(first->data>=second->data)
    {
        l2=first;
        l1=second;
    }
    Node<int> *res=l1;
    while(l1!=NULL and l2!=NULL)
    {
        Node<int> *temp=NULL;
        while(l1!=NULL and l1->data<=l2->data)
        {
            temp=l1;
            l1=l1->next;
        }
        temp->next=l2;
        swap(l1,l2);
    }
    return res;
}
