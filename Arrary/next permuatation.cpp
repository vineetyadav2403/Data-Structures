https://www.interviewbit.com/problems/next-permutation/

vector<int> Solution::nextPermutation(vector<int> &A) {
    int index = -1;
    int n = A.size();
    for(int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            index = i;
            break;
        }
    }
    int x = 0;
    if(index==-1){
        while(x<n/2){
            swap(A[x],A[n-x-1]);
            x++;
        }
        return A;
    }
    int dif=INT_MAX, ind = -1;
    for(int i = index+1;i<n;i++){
        if(A[i]>A[index] && A[i]-A[index]<dif){
            dif = A[i]-A[index];
            ind = i;
        }
    }
    swap(A[index],A[ind]);
    x = index+1;
    int y = n-1;
    while(x<y){
        swap(A[x],A[y]);
        x++;
        y--;
    }
    return A;
}
