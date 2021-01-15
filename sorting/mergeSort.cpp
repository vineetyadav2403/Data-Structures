#include<bits/stdc++.h>
using namespace std;

void merge(int A[],int start,int mid,int end,int maxElement){
    int i = start;
    int j = mid+1;
    int k = start;

    while (i<=mid&& j<=end)
    {
        if(A[i]%maxElement <= A[j] % maxElement){
            A[k] = A[k] + (A[i]%maxElement) * maxElement;
            k++;
            i++;
        }else{
            A[k] = A[k] + (A[j]%maxElement) * maxElement;
            k++; j++;
        }

    }
    while (i<=mid)
    {
        A[k] = A[k] + (A[i]%maxElement)*maxElement;
        k++; i++;
    }
    while (j<=end)
    {
        A[k] = A[k] + (A[j]%maxElement)*maxElement;
        k++; j++;
    }
    for(int i = start; i<=end;i++)
        A[i] = A[i] / maxElement;  
}

void mergeSortRec(int A[],int start,int end,int maxElement){
    if(start<end){
        int mid = (start + end) / 2;
        mergeSortRec(A,start,mid,maxElement);
        mergeSortRec(A,mid+1,end,maxElement);
        merge(A,start,mid,end,maxElement);
    }
}

void mergeSort(int A[],int n){
    int maxElement = *max_element(A,A+n) + 1;
    mergeSortRec(A,0,n-1,maxElement);
}

int main(){

    int A[] = {1,5,2,4,3,6,9,7,8,10};
    int n= 10;
    mergeSort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;

}
