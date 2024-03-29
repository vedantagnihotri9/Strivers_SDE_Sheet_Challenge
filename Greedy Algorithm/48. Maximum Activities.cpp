#include<algorithm>
// struct activities{
//     int s;
//     int e;
// };
bool comp(pair<int,int> a, pair<int,int> b)
{
    return a.second<=b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int ans=1;
    int n =start.size();
    vector<pair<int,int>> act(n);
    for(int i=0;i<n;i++)
    {
        act[i].first=start[i];
        act[i].second=finish[i];
    }
    sort(act.begin(), act.end(), comp);
    int i=0, j=1;
    while(i<n-1 && j<n)
    {
      if (act[i].second <= act[j].first) {
        ans++;
        i=j;
        j++;
      } else
            j++;
    }
    return ans;
}
