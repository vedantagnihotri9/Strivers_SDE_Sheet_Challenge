#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
  vector<vector<long long int>> ans;
  for(long long int i=1; i<=n; i++)
  {
    vector<long long int> row={1};
    long long int beg=1;
    for(long long int j=1; j<i;j++)
    {
      beg=beg*(i-j);
      beg=beg/j;
      row.push_back(beg);
    }
    ans.push_back(row);
  }
  return ans;
}
