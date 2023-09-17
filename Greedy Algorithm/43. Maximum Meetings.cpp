#include <bits/stdc++.h> 
//struct for meeting
 struct meeting{
    int s;
    int e;
    int pos;
};
//comparator to sort on the basis of end time and position
bool comp(struct meeting a, struct meeting b){
    if(a.e<b.e)
        return true;
    else if(a.e>b.e)
        return false;
    else if(a.pos<b.pos)
        return true;
    else
        return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    struct meeting m[start.size()];
    for(int i=0;i<start.size();i++)
    {
        m[i].s=start[i];
        m[i].e=end[i];
        m[i].pos=i+1;
    }
    sort(m, m+start.size(), comp);
    vector<int> ans;
    ans.push_back(m[0].pos);
    int limit=m[0].e;
    
    for(int i=1; i<start.size(); i++)
    {
        if(m[i].s>limit)
        {
            ans.push_back(m[i].pos);
            limit=m[i].e;
        }
    }
    return ans;
}