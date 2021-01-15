#include<iostream>
using namespace std;
//---- O(n^2)
void ShellSort(int A[],int size){
    for (int gap = size/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < size; i += 1) 
        {  
            int temp = A[i]; 
  
            int j;             
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap) 
                A[j] = A[j - gap]; 
            
            A[j] = temp; 
        } 
    } 
}

int main(){
    int A[] = {4,2,3,5,1,7,0};
    int size = 7;
    ShellSort(A,size);
    for(int i=0;i<size;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}
