#include <bits/stdc++.h> 
long getTrappedWater(long *a, int n){
    // Write your code here.
    if(n==0)
        return 0;
    long long int l[n];
    long long int r[n];
    l[0]=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=l[i-1])
            l[i]=l[i-1];
        else
            l[i]=a[i];
    }
    r[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]<=r[i+1])
            r[i]=r[i+1];
        else
            r[i]=a[i];
    }
    long long int sum=0;
    for(int i=0; i<n;i++)
    {
        long long int z;
        if(l[i]>r[i])
            z=r[i];
        else
            z=l[i];
        z=z-a[i];
        if(z>0)
            sum=sum+z;
    }
    return sum;
}