Node *rotate(Node *head, int k) {
     // Write your code here.
     int len=1;
     Node *curr=head;
     while(curr->next!=NULL)
     {
          len++;
          curr=curr->next;
     }
     if(k>=len)
          k=k%len;
     int br=len-k;
     Node* tail=curr;
     tail->next=head;
     curr=head;
     for(int i=1;i<br;i++)
     {
          curr=curr->next;
     }
     head=curr->next;
     curr->next=NULL;
     return head;
}