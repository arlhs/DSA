#include<iostream>
#include<cmath>

using namespace std;

int jumpsearch(int ar[], int n, int key)
{
	int jump=sqrt(n);
	int pos=0;

	if(ar[pos]==key)
		return 1;
	pos++;

	while(ar[pos]<=key && pos<n)
	{
		pos*=jump;
	}

	pos = pos/jump;

	for(int i=pos; i<=n; i++)
	{
		if(ar[i]==key)
			return 1;
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

    cout<<jumpsearch(ar,n,key);
}
