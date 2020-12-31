https://www.interviewbit.com/problems/maximum-sum-triplet/

int getLowValue(set<int>& lowValue, int& n)
{
    auto it = lowValue.lower_bound(n);
 
    --it;
 
    return (*it);
}

int Solution::solve(vector<int> &A) {
    int n = A.size(),i;
    vector<int> suf(n+1,0);
    for(i=n-1;i>=0;i--){
        suf[i] = max(suf[i+1],A[i]);
    }
    int ans = 0;
    set<int> lvalue;
    lvalue.insert(INT_MIN);
    
    for(i = 0;i<n-1;i++){
        if(suf[i+1]>A[i]){
            
            ans = max(ans,getLowValue(lvalue,A[i]) + A[i] + suf[i+1]);
            lvalue.insert(A[i]);
        }
    }
    return ans;
}
