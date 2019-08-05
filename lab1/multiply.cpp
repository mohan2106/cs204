#include<bits/stdc++.h>
using namespace std; 

string sum(string str1, string str2) 
{ 
    if (str1.length() > str2.length()) 
        swap(str1, str2); 
 
    string str = ""; 
    int n1 = str1.length(), n2 = str2.length(); 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
  
    int carry = 0; 
    for (int i=0; i<n1; i++) 
    { 
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    for (int i=n1; i<n2; i++) 
    { 
        int sum = ((str2[i]-'0')+carry); 
        str.push_back(sum%10 + '0'); 
        carry = sum/10; 
    } 
    if (carry) 
        str.push_back(carry+'0'); 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string singleMultiply(string str,char ch,int l2){
	int x= ch-'0';
	int carry=0;
	for(int i=l2-1;i>=0;i--){
		int temp=(str[i]-'0')*x + carry;
		str[i]=temp%10 + '0';
		carry=temp/10;
	}
	string zero="0";
	zero[0] = carry+'0';

	if(carry==0){
		return str;
	}else{
		return zero.append(str);
	}
}

string multiply(string str1,string str2){
	long int l1=str1.length();
	long int l2=str2.length();
	string result="";
	long int k=0;
	string zero="0";
	for(long int i=l1-1;i>=0;i--){
		string str=singleMultiply(str2,str1[i],l2);
		for(long int z=0;z<k;z++){
			str.append(zero);
		}
		k++;
		result=sum(str,result);
	}
	return result;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		string str1,str2;
		cin>>str1>>str2;
		cout<<multiply(str1,str2)<<endl;
	}
	return 0;
}