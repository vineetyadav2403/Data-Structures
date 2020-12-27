https://leetcode.com/problems/regular-expression-matching/

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
