#include<bits/stdc++.h>

using namespace std;

void heapify(vector<int> &ar, int n, int i)
    {
        int largest = i;
        int L = 2*i + 1;
        int R = 2*i + 2;
        
        if(L<n and ar[L]>ar[largest])
            largest = L;
        if(R<n and ar[R]>ar[largest])
            largest = R;
        if(largest!=i){
            swap(ar[largest], ar[i]);
            heapify(ar, n, largest);
        }
    }
    
    void pop(vector<int> &arr, int &n){
        
        if(n<1)
            return;
            
        int mx = arr[0];
        arr[0] = arr[n-1];
        n--;
        
        heapify(arr, n, 0);
        
    }

    void push(vector<int> &arr, int key, int &n){

        int vn = arr.size();
        if(n==vn){
            arr.push_back(key);
            n++;
        }
        else{
            n++;
            arr[n-1] = key;
        }

        int i = n-1;

        while(i>0 and arr[i/2]<arr[i]){
            swap(arr[i/2], arr[i]);
            i = i/2;
        }

    }

int main()
{
    int n;
    cin>>n;
    vector<int> ar(n);

    for(int i=0; i<n; i++){
        cin>>ar[i];
    }

    for(int i=n/2; i>=0; i--){
        heapify(ar, n, i);
    }

    push(ar, 12, n);

    cout<<ar[0]<<" "<<n;




}
