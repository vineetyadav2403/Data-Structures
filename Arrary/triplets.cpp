https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/

int Solution::solve(vector<string> &A) {
    int n = A.size(),i;
    if(n<3) return 0;
    double sum =0,t1,t2,t3,t4;
    t1 = atof(A[0].c_str());
    t2 = atof(A[1].c_str());
    for(i=2;i<n;i++)
    {
        t3 = max(t2,t1);
        t1 = min(t2,t1);
        t2 = t3;
        t4 = atof(A[i].c_str());
        sum=t1+t2+t4;
        if(sum >1.0 && sum <2.0) return 1;
        else if(sum >=2) t2 = min(t2,t4);
        else t1 = max(t1,t4);
    }
    return 0;
}
