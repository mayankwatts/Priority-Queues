using namespace std;
#include<bits/stdc++.h>

class PriorityQueue {
    // Complete this class
    vector<int> pq;
    
    public:
    
    int getSize(){
        return pq.size();
    }
    
    bool isEmpty(){
        return pq.size() == 0;
    }
    
    void insert(int element){
        pq.push_back(element);
        int childIndex=pq.size()-1;
        
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[parentIndex]<pq[childIndex]){
                int temp=pq[childIndex];
                pq[childIndex]=pq[parentIndex];
                pq[parentIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
        
    }
    
    int getMax(){
        if(pq.size()==0){
            return 0;
        }
        return pq[0];
    }
    
    int removeMax(){
        if(isEmpty()){
            return 0;
        }
        int maxi=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        int parentIndex=0;
        int maxIndex;
        
        int childIndex1=2*parentIndex+1;
        int childIndex2=2*parentIndex+2;
        
        while(childIndex1<pq.size()){
            if(pq[maxIndex]<pq[childIndex1]){
                maxIndex=childIndex1;
            }
            if(childIndex2<pq.size() && pq[maxIndex]<pq[childIndex2]){
                maxIndex=childIndex2;
            }
            if(maxIndex==parentIndex){
                break;
            }
            
            int temp=pq[maxIndex];
            pq[maxIndex]=pq[parentIndex];
            pq[parentIndex]=temp;
            
            parentIndex=maxIndex;
            
            childIndex1=2*parentIndex+1;
            childIndex2=2*parentIndex+2;
            
        }
        return maxi; 
    }
    
};

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;
    while(choice != -1) {
        switch(choice) {
            case 1 : // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;
            case 2 : // getMax
                cout << pq.getMax() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMax() << endl;
                break;
            case 4 : // size
                cout << pq.getSize() << endl;
                break;
            case 5 : // isEmpty
                if(pq.isEmpty()) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
            default :
                return 0;
        }
        cin >> choice;
    }
}
