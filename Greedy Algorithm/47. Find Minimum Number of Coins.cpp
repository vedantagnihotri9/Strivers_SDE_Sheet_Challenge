#include <bits/stdc++.h> 
bool comp(pair<int,int> a , pair<int,int> b)
{
    double r1 = ((double)(a.second)/(double)(a.first));
    double r2 = ((double)(b.second)/(double)(b.first));
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(), items.end(), comp);
    int cW=0;
    double fV=0.0;

    for(int i=0;i<n;i++)
    {
        if(cW + items[i].first<=w)
        {
            cW+=items[i].first;
            fV+=items[i].second;
        }
        else
        {
            int r=w-cW;
            fV+=(items[i].second)/((double)items[i].first)*(double)r;
            break;
        }
    }
    return fV;
}