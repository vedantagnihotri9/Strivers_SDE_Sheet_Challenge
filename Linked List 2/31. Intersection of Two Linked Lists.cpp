Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    int cnt1=1, cnt2=1;
    Node *temp1=firstHead, *temp2=secondHead;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1!=NULL)
        {
            temp1=temp1->next;
            cnt1++;
        }
            
        if(temp2!=NULL)
        {
            temp2=temp2->next;
            cnt2++;
        }
    }
    int diff=0;
    if (cnt1 >= cnt2) {
        diff = cnt1 - cnt2;
        Node* start = firstHead;
        for(int i=0;i<diff;i++)
        {
            start=start->next;
        }
        temp2=secondHead;
        while(temp2!=start)
        {
            temp2=temp2->next;
            start=start->next;
        }
        // if(start==NULL)
        //     return -1;
        return start;

    }
    else{
        diff = cnt2 - cnt1;
        Node* start = secondHead;
        for(int i=0;i<diff;i++)
        {
            start=start->next;
        }
        temp2=firstHead;
        while(temp2!=start)
        {
            temp2=temp2->next;
            start=start->next;
        }
        // if(start==NULL)
        //     return ;
        return start;
    }
}



///////////////////////////////////////////////////
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    Node *a = firstHead, *b=secondHead;
    while(a!=b)
    {
        if(a==NULL)
            a=secondHead;
        else
            a= a->next;
        
        if(b==NULL)
            b=firstHead;
        else
            b= b->next;
    }
    return a;
}