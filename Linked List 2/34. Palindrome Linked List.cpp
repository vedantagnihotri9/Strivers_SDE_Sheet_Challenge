bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head==NULL||head->next==NULL)
        return true;
    //find 1st middle;
    LinkedListNode<int> *f=head, *s=head;
    while(f->next!=NULL and f->next->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
    }
    //reverse linked list from node next to s till last
    LinkedListNode<int> *prev=s;
    LinkedListNode<int> *curr=s->next;
    while(curr!=NULL)
    {
        LinkedListNode<int> *n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
    }
    //check if normal and reverse part are eq;
    LinkedListNode<int> *d=head;
    while(prev!=s)
    {
        if(d->data!=prev->data)
            return false;
        d=d->next;
        prev=prev->next;
    }
    return true; 
}