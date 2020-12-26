https://leetcode.com/problems/target-sum/

int n = a.size(), sum = 0;
        for(auto i:a){   
            sum+=i;
        }
        
        int dif = (sum-d);
        
        if(dif < 0 || dif%2)    return 0;
        
        dif/=2;
        
        for(int i=0;i<=dif;i++)   dp[0][i] = 0;
        for(int i=0;i<=n;i++)   dp[i][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=dif; j++){
                if(j >= a[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]]; 
                }else   dp[i][j] = dp[i-1][j];
            }
        }    
                
        return dp[n][dif];
