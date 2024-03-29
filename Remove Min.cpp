#include <bits/stdc++.h>
using namespace std;

class PriorityQueue {
    vector<int> pq;
    
    public :
    
    PriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
        pq.push_back(element);
        
        int childIndex = pq.size() - 1;
        
        while(childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;
            
            if(pq[childIndex] < pq[parentIndex]) {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else {
                break;
            }
            childIndex = parentIndex;
        }
        
    }
    
    int removeMin() {
    
        if(isEmpty()){
            return 0;
        }
        
        int mini=pq[0];
        pq[0]=pq[pq.size()-1];
        pq.pop_back();
        
        int parentIndex=0;
        int minIndex,minimum,temp;
        
        while(parentIndex<pq.size()){
            
            int childIndex1=2*parentIndex+1;
            int childIndex2=2*parentIndex+2;
            
            if(childIndex1<pq.size() && childIndex2<pq.size()){
                minimum=min(pq[parentIndex],min(pq[childIndex1],pq[childIndex2]));
                if(minimum==pq[childIndex1]){
                    minIndex=childIndex1;
                }
                else if(minimum==pq[childIndex2]){
                    minIndex=childIndex2;
                }
                else{
                    return mini;
                }
                
                temp=pq[parentIndex];
                pq[parentIndex]=pq[minIndex];
                pq[minIndex]=temp;
            }
            
            else if(childIndex1<pq.size() && childIndex2>=pq.size()){
                minimum=min(pq[parentIndex],pq[childIndex1]);
                if(minimum==pq[childIndex1]){
                    minIndex=childIndex1;
                }
                else{
                    return mini;
                }
                
                temp=pq[parentIndex];
                pq[parentIndex]=pq[minIndex];
                pq[minIndex]=temp;
                
            }
            
            else if(childIndex1>=pq.size() && childIndex2>=pq.size()){
                 return mini;   
            }
            
            parentIndex=minIndex;
        }
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
            case 2 : // getMin
                cout << pq.getMin() << endl;
                break;
            case 3 : // removeMax
                cout << pq.removeMin() << endl;
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
