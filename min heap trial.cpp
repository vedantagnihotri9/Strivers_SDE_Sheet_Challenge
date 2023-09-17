#include <bits/stdc++.h>
void heapify(vector<int> &heap, int x, int &size)
{
    heap.push_back(x);
    int index=size;

    while(index>0)
    {
        int parent= (index-1)/2;
        if(heap[index]<heap[parent])
        {
            swap(heap[index], heap[parent]);
            index=parent;
        }
    }
    size++; 
} 

int pop(vector<int> &heap, int &size)
{
    int min=heap[0];
    int i=0;
    heap[i]=heap[size];
    size--;
    while(i<size)
    {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left<size && heap[left]<heap[i])
        {
            swap(heap[i], heap[left]);
            i=left;
        }

        else if(right<size && heap[right]<heap[i])
        {
            swap(heap[i], heap[right]);
            i=right;
        }

        else
            break;
    }
    return min;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap;
    int size=0;
    for(int i=0;i<n;i++)
    {
        if(q[i][0]==0)
            heapify(heap, q[i][1], size);
        else 
        {
            cout<<pop(heap, size)<<endl;
        }
    }
    return heap;
}
