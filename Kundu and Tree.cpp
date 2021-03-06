//https://www.hackerrank.com/challenges/kundu-and-tree/problem?isFullScreen=false
#include <bits/stdc++.h>
 
using namespace std;
 
 
#define REP(a,b) for (int a=0; a<(int)(b); ++a)
#define FOR(a,b,c) for (int a=(b); a<(int)(c); ++a)

const int MAXN = 100010;
 
vector <int> tree[MAXN];
char vis[MAXN];

int main() {
    int n, a, b;
    long long res, bad;
    char s[4];
    
    scanf("%d", &n);
    
    REP(i,n-1) {
        scanf("%d%d%s", &a, &b, s);
        if (s[0] == 'b') {
            tree[a-1].push_back(b-1);
            tree[b-1].push_back(a-1);
        }
    }
    
    res = n;
    res = res*(res-1)*(res-2);
    res /= 6;
  //  cout<<res<<" ";
    memset(vis, 0, sizeof(vis));
    
    REP(i,n) if (vis[i] == 0) {
        int v;
        long long cs = 0;
        queue <int> q;
        q.push(i); vis[i] = 1; cs = 1;
        while (!q.empty()) {
            v = q.front(); q.pop();
            REP(j,tree[v].size()) {
                int next = tree[v][j];
                if (vis[next] == 0) {
                    q.push(next);
                    vis[next] = 1;
                    ++cs;
                }
            }
        }
        
        bad = cs*(cs-1)*(n-cs)/2;
        bad += cs*(cs-1)*(cs-2)/6;
        res -= bad;
    }
    
    printf("%d\n", (int)(res%1000000007));

    return 0;
} 
