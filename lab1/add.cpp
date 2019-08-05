#include<iostream>
#include<string>
using namespace std;

void addstr(string str1,string str2){
	int carry =0;
	long int l1=str1.length();
	long int l2=str2.length();
	long int x=0;
	if(l1>=l2){
		for(long int i=l1-1;i>=l1-l2;i--){
			int temp=(str1[i]-'0')+(str2[l2-x-1]-'0')+carry;
			str1[i]='0'+temp%10;
			carry=temp/10;
			x++;
		}
		for(long int i=l1-l2-1;i>=0;i--){
			int temp=(str1[i]-'0')+carry;
			str1[i]='0'+temp%10;
			carry=temp/10;
		}
		cout<<str1<<endl;
	}else{
		for(long int i=l2-1;i>=l2-l1;i--){
			int temp=(str1[i]-'0')+(str2[l1-x-1]-'0')+carry;
			str2[i]='0'+temp%10;
			carry=temp/10;
			x++;
		}
		for(long int i=l2-l1-1;i>=0;i--){
			int temp=(str1[i]-'0')+carry;
			str2[i]='0'+temp%10;
			carry=temp/10;
		}
		cout<<str2<<endl;
	}
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str1,str2;
		cin>>str1>>str2;
		addstr(str1,str2);
	}
	return 0;
}