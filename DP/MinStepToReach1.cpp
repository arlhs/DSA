#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long


int minStepToOneTD(int n, vector<int> &dp)
{
	if(n==2 or n==3)
		return 1;
	if(n==1)
		return 0;
	// if(n<1)
	// 	return INT_MAX;

	int div3=INT_MAX, div2=INT_MAX, sub1=INT_MAX;

	if(dp[n]!=-1)
		return dp[n];

	if(n%3==0){
		div3 = 1 + minStepToOneTD(n/3, dp);
		// if(n%2==0)
		// 	return	1 + min({minStepToOneTD(n/3, dp), minStepToOneTD(n-1, dp), minStepToOneTD(n/2, dp)});
		// else
		// return 1 + min({minStepToOneTD(n/3, dp), minStepToOneTD(n-1, dp)});
	}

	if(n%2==0){
		div2 = 1 + minStepToOneTD(n/2, dp);
		// if(n%3==0)
		// 	1 + min({minStepToOneTD(n/3, dp), minStepToOneTD(n-1, dp), minStepToOneTD(n/3, dp)});
		// else
		// return 1 + min({minStepToOneTD(n/2, dp), minStepToOneTD(n-1, dp)});
	}
	sub1 = 1 + minStepToOneTD(n-1, dp);

	return dp[n] = min({div3, div2, sub1});
}

int minStepToOneBU(int n)
{
	vector<int> dp(n+1, 0);
	int i=1;
	dp[3] = 1;
	dp[2] = 1;
	dp[1] = 0;
	for(int i=4; i<=n; i++){
		int mn = INT_MAX;
		if(i%3==0){
			mn = dp[i/3] + 1;
		}
		if(i%2==0 and mn > dp[i] + dp[i/2]){
				mn = 1 + dp[i/2]; 
		}
		if(mn > dp[i] + dp[i-1])
			mn = 1 + dp[i-1];
		dp[i] = mn;
		//cout<<dp[i]<<" ";
	}

	return dp[n];
}

int main()
{
    
    int n;
    cin>>n;

    cout<<minStepToOneBU(n)<<"\n";

    vector<int> dp(n+1, -1);

    cout<<minStepToOneTD(n, dp);
}
