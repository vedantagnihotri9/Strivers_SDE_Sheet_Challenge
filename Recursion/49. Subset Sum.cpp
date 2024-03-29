#include <algorithm>
#include <vector>
using namespace std;
void sumSubset(vector<int>& num, int i, int sum, vector<int>&ans)
{
    //base
    if(i==num.size())
    {
        ans.push_back(sum);
        return;
    }
    
    //recursion
    //1. select
    sumSubset(num, i+1, sum+num[i], ans);
    //2. don't select
    sumSubset(num, i+1, sum, ans);
}
vector<int> subsetSum(vector<int>& num) {
    int sum=0;   
    int i=0;
    vector<int>ans; 
    sumSubset(num,i,sum,ans);
    sort(ans.begin(),ans.end());
    return ans;
}
