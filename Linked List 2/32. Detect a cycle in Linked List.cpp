bool detectCycle(Node *head)
{
	//	Write your code here
    Node *f=head, *s=head;
    while(f!=NULL and f->next!=NULL)
    {
        f=f->next->next;
        s=s->next;
        if(f==s)
        {
            return true;
        }
    }
    return false;
}