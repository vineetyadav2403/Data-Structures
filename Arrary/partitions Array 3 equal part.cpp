https://www.interviewbit.com/problems/partitions/


int Solution::solve(int A, vector<int> &B) {
    int sum=B[0];
    int pre[A];
    int suf[A];
    int ways=0;
    pre[0]=B[0];
    suf[A-1]=B[A-1];
    for(int i=1;i<A;i++)
    {

        sum+=B[i];
        pre[i]=B[i]+pre[i-1];
        suf[(A-1)-i]=B[(A-1)-i]+suf[(A-i)];
    
    }

    if(sum%3==0)

    {
        int x=sum/3;
        for(int i=0;i<A;i++)

        {
            if(pre[i]==x)
            {
                for(int j=(A-1);j>=(i+2);j--)
                {
                    if(suf[j]==x)
                    {
                        ways++;
                        continue;
                    }
                }
            }
        }

    }

    else if((sum%3)!=0)
    {ways=0;}
    

    
    return ways; 
}
