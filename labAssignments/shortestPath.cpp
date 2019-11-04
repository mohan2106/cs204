#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (int i = 0; i < n; i++)
#define rforz(a,n) for (int i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define module 1000000007

vector<int> bfs(int n,int s, vector<int> g[],vector<int> &vis){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    vector<int> prev(n+1,0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int x:g[node]){
            if(vis[x]) continue;
            q.push(x);
            vis[x] = 1;
            prev[x] = node;
        }
    }
    return prev;
}
vector<int> pathTraverse(int s, int e, vector<int> &prev){
    vector<int> path;
    vector<int> empty;
    int x = e;
    while(x){
        path.push_back(x);
        x = prev[x];
    }
    reverse(path.begin(),path.end());
    if(path[0]==s){
        return path;
    }else{
        return empty;
    }
}


vector<int> shortestPath(int n, int s, int e, vector<int> g[],vector<int> &vis){
    vector<int> prev = bfs(n, s,g,vis);
    return pathTraverse(s,e,prev);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> g[n+1];
    int u,v;
    vector<int> vis(n+1,0);
    forz(m){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>u>>v;
    vector<int> path = shortestPath(n,u,v,g,vis);
    for(int x:path){
        cout<<x<<" ";
    }
    return 0;
}