#include<iostream>
#include<cmath>

using namespace std;


int interpolation(int ar[],int n, int key)
{
    int low,high,pos;
    low = 0;
    high = n-1;

    while(low<=high && key>=ar[low] && key<=ar[high])
    {
        if(high==low)
        {
            if(ar[high]==key)
                return high;
            return -1;
        }
        
        pos = low + ((key-ar[low])/(ar[high]-ar[low]))*(high-low);

        if(ar[pos]==key)
            return pos;
        else if(ar[pos]>key)
            high = pos-1;
        else if(ar[pos]<key)
            low = pos+1;
        
    }
    return -1;
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
    
    int pos = interpolation(ar,n,key);

    cout<<pos;
}
