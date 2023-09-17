Node *addTwoNumbers(Node *num1, Node *num2)
{
    // Write your code here.
    Node *ans = new Node();
    Node *temp=ans;
    Node *n1= num1, *n2=num2;
    int carry=0;
    while(n1!=NULL || n2!=NULL || carry)
    {
        int sum=0;
        if (n1 != NULL) {
            sum = n1->data;
            n1=n1->next;
        }
        if(n2!=NULL)
        {
            sum += n2->data;
            n2 = n2->next;
        }
        sum=sum+carry;
        carry=sum/10;
        Node *node=new Node(sum%10);
        temp->next=node;
        temp=temp->next;
    }
    return ans->next;
}