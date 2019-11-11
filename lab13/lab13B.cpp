#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define mod 1000000007

bool comp(string a,string b){
    if(a.compare(b)<=0){
        return true;
    }
}

bool binarySearch(vector<string> &arr,string str){
    int i=0;
    int j = arr.size() -1;
    while(i!=j){
        int t= (i+j)/2;
        if(arr[t].compare(str) == 0){
            return true;
        }else if(arr[t].compare(str)<0){
            i = t+1;
        }else{
            j=t;
        }
    }
    if(arr[i].compare(str)==0){
        return true;
    }
    return false;
}
int main(){
    int n;
    cin>>n;
    vector<string> arr(n),res(n);
    forz(n) cin>>arr[i],res[i]= arr[i];
    sort(arr.begin(),arr.end(),comp);


    for(string x:res){
        string a = x;
        reverse(a.begin(),a.end());
        if(binarySearch(arr,a)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}