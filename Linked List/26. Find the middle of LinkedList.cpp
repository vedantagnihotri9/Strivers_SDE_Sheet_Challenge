Node *findMiddle(Node *head) {
    // Write your code here
    Node *f=head, *s=head;
    while(f!=NULL and f->next!=NULL)
    {
        s=s->next;
        f=f->next->next;
    }
    return s;
}
