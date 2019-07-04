#include <iostream>
using namespace std;


void inplaceHeapSort(int input[], int n){
    
    for(int i=1;i<n;i++){
        int childIndex=i;
        while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(input[parentIndex]>input[childIndex]){
                int temp=input[parentIndex];
                input[parentIndex]=input[childIndex];
                input[childIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
        }
    }
    
   int heapsize=n;
    for(int i=0;i<n;i++){
        
        int temp=input[0];
        input[0]=input[heapsize-1];
        input[heapsize-1]=temp;
        heapsize--;
        
        int minIndex=0;
        int parentIndex=0;
        int childIndex1=2*parentIndex+1;
        int childIndex2=2*parentIndex+2;
        
        while(childIndex1<heapsize){
            
            if(input[minIndex]>input[childIndex1]){
                minIndex=childIndex1;
            }
            
            if(childIndex2<heapsize && input[minIndex]>input[childIndex2]){
                minIndex=childIndex2;
            }
            
            if(parentIndex==minIndex){
                break;
            }
            
            temp=input[parentIndex];
            input[parentIndex]=input[minIndex];
            input[minIndex]=temp;
            
            parentIndex=minIndex;
            childIndex1=2*parentIndex+1;
            childIndex2=2*parentIndex+2;
            
        }
        
    }

}

int main() {
	
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	inplaceHeapSort(input, size);

	for(int i = 0; i < size; i++)
		cout << input[i] << " ";
	
	return 0;
}
