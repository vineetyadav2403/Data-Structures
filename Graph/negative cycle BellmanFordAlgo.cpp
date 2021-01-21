#include<bits/stdc++.h>
using namespace std;
bool checkNegativeCycle(vector<pair<int,int>> adj[],int v,vector<int> &dist){
    for(int j=0;j<v;j++){
        for(auto k:adj[j]){
            if(dist[j]+k.second < dist[k.first])
                return true;
        }
    }
    return false;
}
void BellmanFordAlgo(vector<pair<int,int>> adj[],int v,vector<int> &dist){
    for(int i=0;i<v-1;i++){
        for(int j=0;j<v;j++){
            for(auto k:adj[j]){
                if(dist[j] + k.second < dist[k.first]){
                    dist[k.first] = dist[j] + k.second;
                }
            }
        }
    }
}
int main()
 {  int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<pair<int,int>> adj[v];
        vector<int> dist(v,INT_MAX);
        int x,y,w;
        for(int i = 0;i < e;i++){
            cin>>x>>y>>w;
            adj[x].push_back({y,w});
        }
        dist[0] = 0;
        BellmanFordAlgo(adj,v,dist);
        cout<<checkNegativeCycle(adj,v,dist)<<endl;
    }
	return 0;
}
