#include<bits/stdc++.h>
using namespace std;
void check(long long int n){
	long int x=sqrt(n);
	if(n%2 == 0){
		cout<<"Not a Prime"<<endl;
		return;
	}
	for(long int i=3;i<=x;i+=2){
		if(n%i == 0){
			cout<<"Not a Prime"<<endl;
			return;
		}
	}
	cout<<"Prime"<<endl;
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int n;
		cin>>n;
		check(n);
	}
	return 0;
}