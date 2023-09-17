Node *firstNode(Node *head)
{
    //    Write your code here.
    Node *f=head, *s=head, *e=head;
    if(head==NULL)
        return NULL;
    while(f!=NULL and f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
        if(s==f)
        {
            while(s!=e)
            {
                s=s->next;
                e=e->next;
            }
            return e;
        }
    }
    return NULL;
}