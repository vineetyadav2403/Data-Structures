https://www.interviewbit.com/problems/n3-repeat-number/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int c1 = 0,c2=0,e1=INT_MAX,e2=INT_MAX;
    for(int i=0;i<n;i++){
        if(e1==A[i]) c1++;
        else if(e2==A[i]) c2++;
        else if(c1==0){
            c1++;
            e1 = A[i];
            
        }else if(c2==0){
            c2++;
            e2=A[i];
        }else{
            c1--;
            c2--;
        }
    }
    c1 = 0;
    c2 = 0;
    for(int i=0;i<n;i++){
        if(e1==A[i]) c1++;
        else if(e2==A[i]) c2++;
    }
    if(n/3<c1) return e1;
    if(n/3<c2) return e2;
    return -1;
}
