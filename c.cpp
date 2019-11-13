#include<bits/stdc++.h>
using namespace std;

typedef long long lli;
typedef long li;
#define forz(n) for (long i = 0; i < n; i++)
#define rforz(a,n) for (long i = a; i < n; i++)
#define forlz(n) for (long int i = 0; i < n; i++)
#define inf 99999

lli get(lli n){
    lli x = floor(sqrt(n));
    lli temp = n;
    lli count = 0;
    lli ans = 1;
    for(lli i=2;i<=x;i++){
        if(n%i == 0){
            count += 1;
            ans = i;
        }
        while(n%i == 0){
            n = n/i;
            
        }
    }
    if(count == 1){
        if(n>2){
           return 1; 
        }
        return ans;
    }else if(count>1){
        return 1;
    }else{
        return temp;
    }
    
}
bool comp(string a,string b){
    int i=0,j=0;
    int x = a.compare(b);
    if(x<0){
        return true;
    }else{
        return false;
    }
}

// string rs(){
    
//     int t=0;
//     string s;
//     char arr[57]={'q','w','e','r','t','y','u','i','o','p','a', 's','d','f','g','h','j','k','l','z','x','c','v','b','n','m','0','1','2','3','4','5','6','7','8','9','@','!','#','$','%','^','&','*','(',')','_','-','=','+','}','{', ':',';','"','?','/'};
//     t=1+rand()%20;
//     for(int u=0;u<t;u++){
//         s.push_back(arr[rand()%57]);
//     }
//     return s;
// }
 
int main(){
    srand(time(NULL));
    int n;
    cin>>n;
    vector<string> arr(n);

    // cout<<"String generated:\n";
    // for(int i=0;i<n;i++){arr[i]=rs();cout<<i+1<<"th string: "<<arr[i]<<endl;}

    forz(n) cin>>arr[i];
    sort(arr.begin(),arr.end(),comp);
    cout<<"Sorted:\n";
    for(string x:arr){
        cout<<x<<"\n";
    }
    cout<<'\n';
    return 0;
}
