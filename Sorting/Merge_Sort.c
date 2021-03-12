// https://www.youtube.com/watch?v=TzeBrDU-JaY&t=353s
// https://practice.geeksforgeeks.org/problems/merge-sort/1#


// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    void merge(int ar[], int l, int m, int r)
    {
         int n1 = m-l+1, n2= r-m;
         int left[n1], right[n2];
         
         for(int i=0; i<n1; i++)
            left[i] = ar[l+i];
        
         for(int i=0; i<n2; i++)
            right[i] = ar[m+1+i];
            
         int i=0, j=0, k=l;
         
         while(i<n1 && j<n2)
         {
             if(left[i]<=right[j])
                ar[k++] = left[i++];
             else
                ar[k++] = right[j++];
         }
         
         while(i<n1)
             ar[k++] = left[i++];
         
         while(j<n2)
            ar[k++] = right[j++];
        
    }
    public:
    void mergeSort(int ar[], int l, int r)
    {
        if(l>=r)
            return ;
        
        int mid = (l+r)/2;
        mergeSort(ar,l, mid);
        mergeSort(ar,mid+1,r);
        merge(ar,l,mid,r);
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends
