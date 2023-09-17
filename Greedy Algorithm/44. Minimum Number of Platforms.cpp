int calculateMinPatforms(int at[], int dt[], int n) {
    // Write your code here.
    int plt=1;
    int maxi=1;
    sort(at,at+n);
    sort(dt,dt+n);
    int i=1;
    int j=0;
    while(i<n && j<n)
    {
        if(at[i]<=dt[j])
        {
            plt++;
            i++;
        }
        else if(at[i]>dt[j])
        {
            plt--;
            j++;
        }
        maxi=max(maxi,plt);
    }
    return maxi;
}