#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
 
typedef long long lli;
typedef long li;
typedef pair<int,int> PI;
typedef pair<long,int> PLI;
typedef pair<int,long> PIL;
typedef pair<long, long> PL;
typedef pair<long long, long long> PLL;
typedef vector<int> VI;
typedef vector<long> VL;
typedef vector<long long> VLL;
typedef priority_queue<int> PQ;
typedef priority_queue<long> PQL;
typedef priority_queue<long long> PQLL;
#define FAST ios::sync_with_stdio(0)
#define forz(n) for (long i = 0; i < n; i++)
#define forv(i,x,y) for (long i=x; i<y; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define TRAV(it, v) for(auto it = v.begin(); it != v.end(); it++) 
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define SQ(a) (a)*(a)
#define CUBE(a) (a)*(a)*(a)
#define Pi 3.14159265358979323846
 
 
#define module 1000000007
 
 
lli gcd(lli x,lli y)
{
    if(x==0) return y;
    return gcd(y%x,x);
}
 
PL Egcd(lli x,lli y)
{
    if(x==0) return MP(0,1);
    PL t=Egcd(y%x,x);
    return MP(t.S-t.F*(y/x),t.F);
}
 
 
lli powerget(lli y, lli x) 
{ 
    lli temp; 
    if( y == 0) 
        return 1; 
    temp = powerget(y/2, x); 
    if (y%2 == 0) 
        return (temp*temp); 
    else{
        lli t = (temp*temp);
        t = t;
        return (x*t); 
    }
} 
 
vector<lli> primeDivisor(lli x){
    if(x<=3){
        vector<lli> r = {x};
        return r;
    }
    lli n = floor(sqrt(x));
    vector<lli> res;
    for(lli i=2;i<=n;i++){
        if(x%i == 0){
            res.push_back(i);
        }
        while(x%i == 0){
            x = x/i;
        }
        if(x<2){
            break;
        }
 
    }
    if(x>2){
        res.push_back(x);
    }
    return res;
}
 
 
 
struct edges{
    int e,u,v;
};
 
 
int root(int v,vector<int> &parent)
{
    if(v == parent[v]){
        return v;
    }
    return parent[v] = root(parent[v],parent);
    
}
 
// void union1(int x, int y,vector<int> &id)
// {
//     int p = root(x,id);
//     int q = root(y,id);
//     id[p] = id[q];
// }
 
void union_set(int x,int y,vector<int> &parent,vector<int> &rank){
    x = root(x,parent);
    y = root(y,parent);
    if(x != y){
        if(rank[x]<rank[y]){
            swap(x,y);
        }
        parent[y] = x;
        if(rank[x] == rank[y]){
            rank[x]++;
        }
    }
}
int kruskals(vector<edges> graph,vector<int> vis,vector<int> &id,vector<int> &rank){
    // vector<edges> res;
    int res=0;
    for(edges x:graph){
        int e = x.e;
        int u = x.u;
        int v = x.v;
        // if(vis[u] && vis[v]) continue;
        if(root(u,id)!=root(v,id)){
            vis[u] = 1;
            vis[v] = 1; 
            union_set(u,v,id,rank);
            // res.push_back(x);
            // res+=e;
        }
        
    }
    // bool connected=true;
    // for(int i=1;i<vis.size();i++){
    //     if(vis[i]==0){
    //         connected = false;
    //         break;
    //     }
    // // }
    // if(true){
    //     return res;
    // }
    // vector<edges> nl;
    // return nl;
    return res;
}
li b_search(lli arr[],lli key,li n){
    li k=0;
    // li n = (*(&arr + 1) - arr);
    // lli n = sizeof(arr)/sizeof(arr[0]);
    for(li b = n/2 ; b>0; b /= 2){
        while(k+b <n && arr[k+b]<=key) k+= b;
    }
    if(arr[k]==key){
        return k;
    }else{
        return -1;
    }
}
 
 
pair<li,li> bfs(int s, vector<int> g[],vector<int> &vis,vector<int> &id){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    li min=s,max= s;
    
    // vector<int> prev(n+1,0);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int x:g[node]){
            if(vis[x]) continue;
            q.push(x);
            vis[x] = 1;
            id[x] = s;
            if(x<min){
                min = x;
            }else if(x>max){
                max = x;
            }
            // prev[x] = node;
        }
    }
    return make_pair(min,max);
}
li max_subarray_sum(VL &arr){
    li  l= arr.size();
    li sum=0,best=0;
    forz(l){
        sum = max(arr[i],arr[i]+sum);
        best = max(sum,best);
    }
    return best;
}
string generate_ternary(lli n){
    string str = "";
    int t,index=0;
    int i=0;
    while(n>0){
        t = n%3;
        i++;
        if(n==2){
            index=i;
        }
        str+= (t+'0');
        n/=3;
    }
    reverse(str.begin(),str.end());
    return str;
}
string cal(PL a){
    string str="";
    li x = a.F;
    li y = a.S;
    while(x){
        int temp = x%10;
        str += temp + '0';
        x/= 10;
    }
    reverse(str.begin(),str.end());
    while(y){
        int temp = y%10;
        str += temp + '0';
        y/= 10;
    }
    return str;
}
string decimal_to_binary(lli n){
    int t = 0;
    lli tt = n;
    while(tt>0){
        t++;
        tt /= 2;
    }
    bitset<32> s = bitset<32>(n);
    string str = "";
    forz(s.size()){
        str += s[i]+'0';
    }
    reverse(str.begin(),str.end());
    return str;
}
lli find_combination(lli n,lli k){
    if(n<k){
        return 0;
    }else if(n==k){
        return 1;
    }else if(k==0){
        return 1;
    }
    return find_combination(n-1,k) + find_combination(n-1,k-1);
 
}
lli nC2 (lli n){
    return (n*(n-1))/2;
}
string checkPrime(lli x){
    if(x==1){
        return "NO";
    }
    if(x<=3){
        return "YES";
    }
    li t=2;
    if(x%2 == 0){
        return "NO";
    }
    t=3;
    for(t;t<=sqrt(x);t+=2){
        if(x%t ==0){
            return "NO";
        }
    }
    return "YES";
}
 

lli cal(int s,lli x){
    return x*(x+s);
}
int sx(lli a){
    int count=0;
    while(a>0){
        count++;
        a = a/10;
    }
    return count;
}
int differ(lli n,lli x){
    string str1 = to_string(n);
    string str2 = to_string(x);
    int count=0;
    forz(str1.length()){
        if(str1[i]!=str2[i]){
            break;
        }
        count++;
    }
    return count;
}
void convert(lli n,int d){
    string str = to_string(n);
    str[d] = ((str[d]-'0') -1 )+'0';
    int count=0;
    for(int i=d+1;i<str.length();i++){
        if(str[i]!='9'){
            count=1;
        }
        str[i] = '9';
        
    }
    if(count==0){
        str[d] = ((str[d]-'0') +1 )+'0';
    }
    cout<<str<<'\n';
}
string gene(lli n){
    string str="";
    bool flag = true;
    forz(n){
        if(flag){
            str+='a';
        }else{
            str+='b';
        }
        flag = !flag;
    }
    return str;
}
lli string_to_lli(string s){
    lli t=0;
    for(char x:s){
        t = t*10 + (x-'0');
    }
    return t;
}
bool check_valid(string s){
    map<char,int> mp;
    mp['4'] = 0;
    mp['7'] = 0;
    for(char x:s){
        mp[x] +=1;
    }
    if(mp['4']==mp['7']){
        return true;
    }
    return false;
 
}
void all(int t,vector<lli> &v,string s){
    if(s.length()==t){
        if(check_valid(s)){
            v.PB(string_to_lli(s));
        }
        
        return;
    }else{
        s += '4';
        all(t,v,s);
        s[s.length()-1] = '7';
        all(t,v,s);
        return;
    }
}
struct group{
    li l,r;
    int ind;
};
bool comp(group a,group b){
    return a.r < b.r;
}
bool poss(vector<int> a,int s,int t,int i){
    if(t==s){
        return true;
    }else if(i>3){
        return false;
    }else{
        return  poss(a,s,t+a[i],i+1) || poss(a,s,t,i+1);
    }
}
li countCoin(vector<int> coins,li sum){
    if(sum<0){
        return 0;
    }else if(sum==0){
        return 1;
    }else{
        li count=0;
        for(int x:coins){
            count+=countCoin(coins,sum-x);
        }
        return count;
    }
    
}
int minChange(vector<int> coins,li sum,vector<int> sol){
    if(sum < 0) return 9999;
    else if(sum == 0) return 0;
    else{
        if(sol[sum]) return sol[sum];
        int best = 9999;

        for(int x:coins){
            best = min(best,minChange(coins,sum-x,sol)+1);
        }
        sol[sum] = best;
        return best;
    }
}
 

int main(){
    FAST;
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    //=====================================code starts here
    li n,s;
    cin>>n>>s;
    vector<int> arr(n);
    forz(n) cin>>arr[i];
    vector<int> sol(s+1);
    rforz(1,s+1){
        int best = 9999;
        for(int x:arr){
            if(i-x >= 0){
                best = min(best,sol[i-x]+1);
            }
        }
        sol[i] = best;
    }
    forz(s+1){
        cout<<i<<" "<<sol[i]<<'\n';
    }
    // cout<<minChange(arr,s,sol)<<'\n';
    
    return 0;
}