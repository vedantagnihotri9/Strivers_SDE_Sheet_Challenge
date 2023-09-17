
LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Write your code here
    // LinkedListNode<int>* curr=head;
    LinkedListNode<int>* prev=NULL;
    while(head!=NULL)
    {
        LinkedListNode<int>* n=head->next;
        head->next=prev;
        prev=head;
        head=n;
    }
    return prev;
}