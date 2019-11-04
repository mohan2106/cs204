#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define inf 99999

int main(){

    vector<vector<li>> graph = {{0,3,6,inf,inf,inf,inf},
    {3,0,2,1,inf,inf,inf},
    {6,2,0,1,4,2,inf},
    {inf,1,1,0,2,inf,4},
    {inf,inf,4,2,0,2,1},
    {inf,inf,2,inf,2,0,1},
    {inf,inf,inf,4,1,1,0}
    };
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                if(j == i || k==i || j==k){
                    
                }else{
                    graph[j][k] = min(graph[j][k],graph[j][i] + graph[i][k]);
                }
            }
        }
    }
    for(int j=0;j<7;j++){
        for(int k=0;k<7;k++){
            cout<<graph[j][k]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    return 0;
}