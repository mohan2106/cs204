#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef long li;
#define forz(i,n) for(long i=0;i<n;i++)

bool bfs(vector<pair<int,int>> adl[],int i,vector<int> &vis){
    adl[i][0].second = 1;
    queue<pair<int,int>> q;
    q.push(adl[i][0]);
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        vis[temp.first] = 1;
        for(pair<int,int> &x:adl[temp.first]){
            vis[x.first]=1;
            if(x.second == 0){
                if(temp.second == 1){
                    x.second =2;
                }else{
                    x.second =1;
                }
                q.push(x);
            }else{
                if(x.second == temp.second){
                    return false;
                }
            }
        }
    }
    return true;
}
struct node{
    int u;
    int v;
    int w;
};

int main(){
    li n,m;
    cin>>n>>m;
    vector<node> adl;
    
    int x =n+1;
    int u,v,w;
    node te;
    int count=0;
    forz(i,m){
        cin>>u>>v>>w;
        te.u = u;
        te.v = v;
        te.w = w;
        adl.push_back(te);
        if(w%2 == 0 ){
            count++;
        }
    }
    vector<pair<int,int>> graph[n+1+count];
    vector<int> vis(n+1+count,0);
    forz(i,m){
		node t = adl[i];
        if((adl[i].w % 2) == 0){
            graph[t.u].push_back(make_pair(x,0));
            graph[x].push_back(make_pair(t.u,0));
            graph[t.v].push_back(make_pair(x,0));
            graph[x].push_back(make_pair(t.v,0));
            x++;
        }else{
            graph[t.u].push_back(make_pair(t.v,0));
            graph[t.v].push_back(make_pair(t.u,0));
        }
        
        
    }
    bool res=true;
    forz(i,n+count){
        if(vis[i+1] == 0){
            bool ans = bfs(graph,i+1,vis);
            if(!ans){
                res = false;
            }
        }
    }
    
    if(res){
        cout<<"NO\n";
    }else{
        cout<<"YES\n";
    }
    return 0;
}
