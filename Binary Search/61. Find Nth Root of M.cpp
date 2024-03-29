int NthRoot(int n, int m) {
  // Write your code here.
  long long int i=1;
  long long int j=m;
  while(i<=j)
  {
    long long int mid=(i + (j-i)/2);
    long long int x=mid;
    for(int i=1; i<n;i++)
    {
      x=x*mid;
      if(x>m)
      {
        j=mid-1;
        break;
      }
    }
    if(x==m)
      return mid;
    else if(x<m)
      i=mid+1;
  }
  return -1;
}