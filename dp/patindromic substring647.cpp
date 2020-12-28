https://leetcode.com/problems/palindromic-substrings/

int countSubstrings(string s) {
        int n = s.length(),i,j,total = 0;
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        for(int g = 0; g < n ; g++){
            for(i = 0,j = g; j < n; i++,j++){
                if(g==0)
                    dp[i][j]=true;
                else if(g==1)
                    dp[i][j] = (s[i]==s[j]);
                else {
                    if(s[i]==s[j] && dp[i+1][j-1]) {
                        dp[i][j]= true;
                    }
                }
                if(dp[i][j]){
                    total++;
                }
            }
        }
        return total;
    }
