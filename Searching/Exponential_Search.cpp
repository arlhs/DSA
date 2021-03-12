#include<iostream>

using namespace std;

int binary(int ar[],int lo,int hi,int key)
{

    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(ar[mid]==key)
            return mid;
        else if(ar[mid]<key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int expo(int ar[],int n, int key)
{
    int i=0;
    if(ar[i]==key)
        return i;
    i = 1;
    while(i<n && ar[i]<=key)
        i *= 2;
    
    //using binary search after the i'th index for whch exponential is greater than the size of aaray
    return binary(ar,i/2,min(i,n-1),key);

    //return pos;
}



int main()
{
    int n;
    cin>>n;

    int ar[n];

    for(int i=0;i<n;i++)
        cin>>ar[i];
    
    int key;
    cin>>key;

    int pos = expo(ar,n,key);

    cout<<pos;
}
