#include <bits/stdc++.h>
struct job{
    int deadline;
    int profit;
};
bool comparator(struct job a, struct job b)
{
    if (a.profit > b.profit) 
        return true;
    else if (a.profit < b.profit)
        return false;
    else if(a.deadline>b.deadline)
        return true;
    else
        return false;
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    struct job J[jobs.size()];
    for (int i = 0; i < jobs.size(); i++) {
      J[i].deadline = jobs[i][0];
      J[i].profit = jobs[i][1];
    }
    sort(J,J+jobs.size(),comparator);
    int max=-1;
    for(int i=0;i<jobs.size();i++)
    {
        if(max<J[i].deadline)
            max=J[i].deadline;
    }
    int mP[max]={0}, maxProfit=0;
    for (int i = 0; i < jobs.size(); i++)
    {
        int d=J[i].deadline-1;
        while(d>=0)
        
        {
            if (mP[d] == 0) 
            {
                mP[d] = J[i].profit;
                maxProfit+=mP[d];
                break;
            }
            d--;
        }
    }
    return maxProfit;
}
