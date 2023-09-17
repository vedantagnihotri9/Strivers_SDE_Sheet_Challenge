int search(int* arr, int n, int key) {
    // Write your code here.
    int i=0;
    int j=n-1;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(arr[mid]==key)
            return mid;
        //check if right sorted
        if(arr[mid]<=arr[j])
        {
            if(key<=arr[j] && key>=arr[mid])
                i=mid+1;
            else
                j=mid-1;
        }

        //check in left sorted array
        else if(arr[mid]>=arr[i])
        {
            if(key>=arr[i] && key<=arr[mid])
                j=mid-1;
            else
                i=mid+1;
        }
    }
    return -1;
}