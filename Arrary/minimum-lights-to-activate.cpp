https://www.interviewbit.com/problems/minimum-lights-to-activate/

int Solution::solve(vector<int> &A, int B) {
    int c = 0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            c++;
            if(c==B)
                return -1;
        }
        else
            break;
    }
    c =0;
    for(int i=A.size()-1;i>=0;i--){
        if(A[i]==0){
            c++;
        if(c==B)
            return -1;
        }
        else
            break;
    }
    c =0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0){
            c++;
            if(c==B * 2)
                return -1;
        }
        else
            c =0;
    }
    if(A.size()%((2*B)-1)!=0)
        return (A.size()/((2*B)-1))+1;
    else
        return A.size()/((2*B)-1);
}
