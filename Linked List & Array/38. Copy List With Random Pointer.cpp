#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *front=head;
    LinkedListNode<int> *curr=head;
//making a copy linkd list using og linked list
    while(curr!=NULL)
    {
        front = curr->next;
        LinkedListNode<int> *copy= new LinkedListNode<int>(curr->data);
        copy->next=front;
        curr->next=copy;
        curr=front;
    }
//setting random nodes
    curr=head;
    front=head;
    while(curr!=NULL)
    {
        front=curr->next->next;
        if(curr->random!=NULL)
            curr->next->random=curr->random->next;
        curr=front;
    }
//making 2 different list; removing copy from original
    curr=head;
    front=head;
    LinkedListNode<int> *cHead= new LinkedListNode<int>(0);
    LinkedListNode<int> *temp= cHead;
    while(curr!=NULL)
    {
        front=curr->next->next;
        temp->next=curr->next;
        curr->next=front;
        temp=temp->next;
        curr=front;
    }
    return cHead->next;

}
////////// Another Approach

#include <bits/stdc++.h>

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    unordered_map<LinkedListNode<int>*,LinkedListNode<int>*> map;
    LinkedListNode<int> *ori=head;
    LinkedListNode<int> *copy=NULL;
    //mapping copy to og
    while(ori!=NULL)
    {
        copy = new LinkedListNode<int>(ori->data);
        map[ori]=copy;
        ori=ori->next;
    }

    //setting next and random
    ori=head;
    while(ori!=NULL)
    {
        copy=map[ori];
        copy->next=map[ori->next];
        copy->random=map[ori->random];
        ori=ori->next;
    }
    ori=head;
    copy=map[ori];
    return copy;

}
