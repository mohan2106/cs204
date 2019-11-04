#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (int i = 0; i < n; i++)
#define rforz(a,n) for (int i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define module 1000000007

//initialise arrray of vector and
vector<int> g[20];

bool vis[10]; //this is bollean array which keeps the record that whether a node is visited or not during a DFS
void dfs(int u){
    vis[u] = true;
    for(int v:g[u]){
        if(vis[v]) continue;
        dfs(v);
    }
}

 
int main(){
    //if node 2 have path to 5 than push 5 in g[2]
    //same for others
    int n,m,u,v;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);  //start depth first search from 1 as root node
    if(vis[6]){ //if we visited 6 than travelling from node 1 than true else false
        cout<<"Yeah we reached to 6";
    }else{
        cout<<"oops can't reach to 6";
    }

    // forz(10){
    //     for(int x:g[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<'\n';
    // }
    
    return 0;
}