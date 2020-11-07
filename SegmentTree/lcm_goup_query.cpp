#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;  
#define FOR(i,n) for(int i=0;i<n;i++)
int tree[400001]={0};
// int gcd(int a, int b) 
// { 
//     if (a == 0) 
//         return b; 
//     return gcd(b%a, a); 
// } 
  
int lcm(int a, int b) 
{ 
    return a*b/__gcd(a,b); 
}
void buildSegmentTree(int a[],int node,int start,int end){
    if(start==end){
        tree[node] = a[start];
        return;
    }
    int mid = (start+end)/2;
    buildSegmentTree(a,2*node,start,mid);
    buildSegmentTree(a,2*node+1,mid+1,end);
    int left = tree[2*node];
    int right = tree[2*node+1];
    tree[node] = lcm(left,right);
}

int query(int node, int start, int end, int l, int r){
    if(end<l || start>r){
        return 1;
    }
    if(l<=start && r>=end){
        return tree[node];
    }
    int mid = (start+end)/2;
    int left = query(2*node,start,mid,l,r);
    int right = query(2*node+1,mid+1,end,l,r);
    return lcm(left,right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        FOR(i,n){
            cin>>a[i];
        }
        int m;
        cin>>m;
        vector<pair<int,int>> b;
        int x,y;
        FOR(i,m){
            cin>>x>>y;
            b.push_back({x,y});
        }
        buildSegmentTree(a,1,0,n-1);
        for(auto j:b){
            cout<<query(1,0,n-1,j.first-1,j.second-1)<<endl;
        }
    }
    return 0;
}
