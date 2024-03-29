#include <iostream>
#include <vector>
using namespace std;

#include <queue>
#include <vector>
using namespace std;
int kthLargest (vector<int> arr, int n, int k){
    
    priority_queue<int> pq;
    
    
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
    }
    
    for(int i=0;i<k-1;i++){
        pq.pop();
    }
    
    return pq.top();
    
}


int main(){
    int n, k, s;
    vector<int> arr;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>s;
        arr.push_back(s);
    }
    cin >> k;
    cout << kthLargest(arr, n, k) << endl;
    
    return 0;
}
