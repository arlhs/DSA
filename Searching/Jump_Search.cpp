#include<iostream>
#include<cmath>

using namespace std;

// mine simplest jump program

// int jumpsearch(int ar[], int n, int key)
// {
// 	int jump=sqrt(n);
// 	int pos=0;

// 	if(ar[pos]==key)
// 		return 1;
// 	pos++;

// 	while(ar[pos]<=key && pos<n)
// 	{
// 		pos*=jump;
// 	}

// 	pos = pos/jump;

// 	for(int i=pos; i<=n; i++)
// 	{
// 		if(ar[i]==key)
// 			return 1;
// 	}

// 	return -1;

// }

int jumpSort(int *ar,int n, int key)
{
    int m=sqrt(n)-1;
    for(int i=sqrt(n); i>0 ; i--){
        if(ar[m]==key)
            return m;
        else if(ar[m]<key)
            m += sqrt(n);
        else
        {
            if(n-m>=sqrt(n)){
            for(int j=1;j<=sqrt(n)-1;j++){
                if(ar[m-j]==key)
                    return (m-j);
            }
            }
            else{
                for(int j=m+1;j<n;j++){
                    if(ar[j]==key)
                        return (j);
                }
            }
        }   
    }
    return -1;
}

int jumpsort2(int ar[], int n, int key)
{
    int pos=sqrt(n);
    int lo = 0;

    // finding the block where the element is present
    while(ar[min(pos,n-1)]<key)
    {
        lo = pos;
        pos += sqrt(n);
         cout<<lo<<" "<<pos<<"\n";
        if(lo>=n)
            return -1;
        //cout<<pos;
    }

    if(ar[lo]<=key && ar[pos]>=key ){
        for(int i=pos; i>=lo; i--){
            if(ar[i]==key)
                return i;
            cout<<i<<"\n";
        }
    }
    else{
        for(int i=pos;i<n;i++){
            if(ar[i]==key)
                return i;
             cout<<i<<"\n";
        }
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

    cout<<jumpsort2(ar,n,key);
}
