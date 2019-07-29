#include<bits/stdc++.h>
using namespace std;
void func(int arr[],int n,int k){
    
    priority_queue <int,vector<int>,greater<int>> pq;
    if(k>n){
        for(int i=0;i<n;i++){
            cout<<"-1"<<" ";
        }
    }
    else{
        int* dp=new int[k-1];
        for(int i=0;i<k-1;i++){
            cout<<"-1"<<" ";
            pq.push(arr[i]);
        }
        pq.push(arr[k-1]);
        cout<<pq.top()<<" ";
        for(int i=k;i<n;i++){
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
                cout<<pq.top()<<" ";
            }
            else{
                cout<<pq.top()<<" ";
            }
        }
    }
}
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>k>>n;
	    int* arr=new int[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    func(arr,n,k);
	    cout<<endl;
	    delete[] arr;
	}
	return 0;
}
