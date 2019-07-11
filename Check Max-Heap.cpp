#include <iostream>
#include<queue>
#include<vector>
using namespace std;

bool checkMaxHeap(int arr[], int n){
    
    int parent=0;
    int child1=2*parent+1;
    int child2=2*parent+2;
    
    while(child1<n){
        if(arr[parent]<arr[child1]){
            return false;
        }
        if(child2<n && arr[parent]<arr[child2]){
            return false;
        }
        parent++;
        child1=2*parent+1;
        child2=2*parent+2;
    }
    
    return true; 
}


int main() {
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    bool ans = checkMaxHeap(arr, n);
    if(ans){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
    
    delete [] arr;
    
    return 0;
}
