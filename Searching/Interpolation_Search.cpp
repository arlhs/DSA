#include<iostream>
#include<cmath>

using namespace std;


int interpolation(int ar[],int n, int key)
{
   int lo=0, hi=n-1;
	int pos=0;

	if(ar[pos]==key)
			return 1;

	while(lo<hi && key>=ar[lo] && key<=ar[hi])
	{
	    if(hi==lo)
	    {
	        if(ar[lo]==key)
	            return 1;
	        return -1;
	    }
		
		pos = lo + (key-ar[lo])/(ar[hi]-ar[lo])*(hi-lo);

		if(ar[pos]==key)
			return 1;
		else if(ar[pos]>key)
			hi = pos-1;
		else
			lo = pos+1;

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
