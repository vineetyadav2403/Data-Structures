https://leetcode.com/problems/regular-expression-matching/
//******************************************************************
    bool charMatch(char a,char b){
        return a==b || b=='.';
    }
    
    bool isMatch(string s, string p){
        int n = s.length(), m=p.length();
        
        if(!m) return !n;
        
        return n && m > 1 && p[1] == '*' && charMatch(s[0],p[0]) && isMatch(s.substr(1), p)
                || m > 1 && p[1] == '*' && isMatch(s,p.substr(2))
                || n && (m==1 || m > 1 && p[1] != '*') && charMatch(s[0],p[0]) && isMatch(s.substr(1), p.substr(1));
    }


//********************************************************************
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        
        // a* or a*b* for this type of case
        
        for(int i=1;i<=m;i++)
            if(p[i-1]=='*')
                dp[0][i] = dp[0][i-2];
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1] == '.'||p[j-1]==s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else if(p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2];
                    if(p[j-2]=='.'||p[j-2]==s[i-1]){
                        dp[i][j] = dp[i][j] | dp[i-1][j];
                    }
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
