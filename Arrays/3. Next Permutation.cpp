#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int bp=-1;
    for(int i=n-1; i>0; i--)
    {
      if (permutation[i] > permutation[i - 1]) {
        bp = i - 1;
        break;
      }
    }
    // cout<<permutation[bp]<<endl;
    // cout<<"bp: "<<bp<<endl;
    // bool t=false;
     if(bp==-1)
    {
       reverse(permutation.begin(), permutation.end());
       return permutation;
    }
    for(int i=n-1;i>bp;i--)
    {
        if(permutation[i]>permutation[bp])
        {
            swap(permutation[i], permutation[bp]);
            break;
        }
    }
   
    reverse(permutation.begin()+bp+1, permutation.end());
    return permutation;
}