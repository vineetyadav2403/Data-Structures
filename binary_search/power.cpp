https://www.interviewbit.com/problems/implement-power-function/

int Solution::pow(int x, int n, int d) {
    long long int X=x,y=n,p=d;
    X=X%p;
    if(X==0)
    {
        return 0;
    }
    long long int res=1;
    while(y>0)
    {
        if(y&1)//if y is odd
        {
            res=((res%p)*(X%p))%p;
        }
        //y must be even now
        y=y>>1;//y=y/2
        X=((X%p)*(X%p))%p;
    }
    res=(res>=0)?(res%p):(res+p)%p;
    return(res);
}
