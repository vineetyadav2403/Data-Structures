https://leetcode.com/problems/unique-binary-search-trees/

int numTrees(int n) {
        int i=1,j=1;
        
        int dp[n+1];
        fill_n(dp,n+1,0);
        dp[0] = 1;
        dp[1] = 1;
     
        for(int i=2;i<=n;i++){
            for(j=1;j<=i;j++){
                dp[i]=dp[i] + (dp[j-1]*dp[i-j]);
            }
        }
        return dp[n];
        
    }
