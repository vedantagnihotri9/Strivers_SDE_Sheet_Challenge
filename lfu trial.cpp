#include <bits/stdc++.h>
struct node{
    int key, val, count;
    node *next;
    node *prev;
    node(int k, int v)
    {
        key=k;
        val=v;
        count=1;
    }
};
struct list{
    int size;
    node* head;
    node* tail;
    list(){
        head=new node(-1,-1);
        tail=new node(-1,-1);
        head->next=tail;
        tail->prev=head;
        size=0;
    }

    void addNode(node *newnode)
    {
        node* temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
        size++;
    }

    void deleteNode(node* delNode)
    {
        node* delPrev=delNode->prev;
        node* delNext=delNode->next;
        delPrev->next=delNext;
        delNext->prev=delPrev;
        size--;
    }
};

class LFUCache
{
public:
    unordered_map <int, node*> keyNode;
    unordered_map <int, list*> freqList;
    int cap;
    int minFreq;
    int curSize;
    LFUCache(int capacity)
    {
        // Write your code here.
        cap=capacity;
        minFreq=0;
        curSize=0;

    }
    void  updateFreqList(node *curNode)
    {
        keyNode.erase(curNode->key);
        freqList[curNode->count]->deleteNode(curNode);
        if(curNode->count==minFreq && freqList[curNode->count]->size==0)
        {
            minFreq++;
        }

        list* nextHighFreqList= new list();
        if(freqList.find(curNode->count+1)!=freqList.end())
        {
            nextHighFreqList = freqList[curNode->count+1];
        }
        curNode->count+=1;
        nextHighFreqList->addNode(curNode);
        freqList[curNode->count]=nextHighFreqList;
        keyNode[curNode->key]=curNode;
    }

    int get(int key)
    {
        // Write your code here.
        if(keyNode.find(key)!=keyNode.end())
        {
            node *resNode=keyNode[key];
            int res=resNode->val;
            updateFreqList(resNode);
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here.
        if (cap == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            node* newnode = keyNode[key]; 
            newnode->val = value; 
            updateFreqListMap(newnode); 
        }
        else {
            if(curSize == cap) {
                list* currlist = freqList[minFreq]; 
                keyNode.erase(currlist->tail->prev->key); 
                freqList[minFreq]->deleteNode(currlist->tail->prev);
                curSize--; 
            }
            curSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            list* listFreq = new List(); 
            if(freqList.find(minFreq) != freqList.end()) {
                listFreq = freqList[minFreq]; 
            }
            node* newnode = new Node(key, value); 
            listFreq->addNode(newnode);
            keyNode[key] = newnode; 
            freqList[minFreq] = listFreq; 
        }
    }
};
