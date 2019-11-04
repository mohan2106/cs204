#include<bits/stdc++.h>
using namespace std;
#define forz(n) for(int i=0;i<n;i++)

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
int main(){
    
    return 0;
}