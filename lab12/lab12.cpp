#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define mod 1000000007
struct edges{
    int u,v,e;
    double log;
};

bool comp(edges a,edges b){
    return a.log > b.log;
}
int root(int x,vector<int> &id)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y,vector<int> &id)
{
    int p = root(x,id);
    int q = root(y,id);
    id[p] = id[q];
}
double kruskals(vector<edges> graph,vector<int> vis,vector<int> &id){
    lli res=1;
    for(edges x:graph){
        
        int e = x.e;
        int u = x.u;
        int v = x.v;
        // if(vis[u] && vis[v]) continue;
        if(root(u,id)!=root(v,id)){
            vis[u] = 1;
            vis[v] = 1; 
            union1(u,v,id);
            res *= e;
            res = res%mod;
        }
        
    }
    bool connected=true;
    for(int i=1;i<vis.size();i++){
        if(vis[i]==0){
            connected = false;
            break;
        }
    }
    if(true){
        return res;
    }
    
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    // map<int,pair<int,int>> graph;
    vector<int> vis(n+1,0);
    vector<edges> graph;
    int e,u,v;
    while(m--){
        cin>>u>>v>>e;
        double x = log(e);
        graph.push_back({u,v,e,x});
    }
    sort(graph.begin(),graph.end(),comp);
    vector<int> id(n+1);
    forz(n) id[i] = i;
    double res = kruskals(graph,vis,id);
    cout<<res<<'\n';
    
    return 0;
}
