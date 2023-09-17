#include<unordered_map>
class LRUCache
{
public:
    class node{
        public:
        int key;
        int val;
        node *next;
        node *prev;

        node(int k, int v)
        {
            key = k;
            val = v;
        }       
    };
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int cap;
    unordered_map<int, node*> LRU;
    
    void addNode(node* newnode)
    {
        node* temp=head->next;
        head->next=newnode;
        newnode->next=temp;
        newnode->prev=head;
        temp->prev=newnode;
    }
    
    void deleteNode(node *delnode)
    {
        node* tempPrev = delnode->prev;
        node* tempNext = delnode->next;
        tempPrev->next=tempNext;
        tempNext->prev=tempPrev;
    }
    
    LRUCache(int capacity)
    {
        // Write your code here
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    int get(int key)
    {
        // Write your code here
        if(LRU.find(key)==LRU.end())
            return -1;
        node* resultNode = LRU[key];
        int res= resultNode->val;
        LRU.erase(key);
        deleteNode(resultNode);
        addNode(resultNode);
        LRU[key]=head->next;
        return res;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(LRU.find(key)!=LRU.end())
        {
            // node *existingNode = LRU[key];
            deleteNode(LRU[key]);
            LRU.erase(key);
            addNode(new node(key, value));
            LRU[key]=head->next;
        }

        else if(LRU.size()==cap)
        {
            LRU.erase(tail->prev->key);
            deleteNode(tail->prev);
            addNode(new node(key, value));
            LRU[key]=head->next;
        }
        else
        {
            addNode(new node(key, value));
            LRU[key]=head->next;
        }
    }
};
