Node* removeKthNode(Node* head, int n)
{
    // Write your code here.
    Node* start=  new Node();
    start->next=head;
    Node *f= start, *s=start;
    for(int i=1;i<=n;i++)
        f=f->next;

    while (f->next != NULL) {
      f = f -> next;
      s = s -> next;
    }
    s->next=s->next->next;
    return start->next;//important to return this instead of head, to handle deletion of head.
}
