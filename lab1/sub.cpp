#include<iostream>
#include<string>
using namespace std;

int lenZero(string s){
	int i=0;
	while(s[i]-'0' == 0){
		i++;
	}
	return i;
}

string modify(string str){
	int l2=lenZero(str);
	int l1=str.length();
	string stt="";
	for(int i=l2;i<l1;i++){
		stt.push_back(str[i]);
	}
	return stt;
}

bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int flag1=0;
    int flag2=0;
    int x1=lenZero(str1);
    int x2=lenZero(str2);
    int n1 = str1.length()-x1, n2 = str2.length()-x2; 
    
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
	
    for (int i=0; i<n1-x1; i++){
    	if(str1[i+x1]-'0'!=0){
    		flag1=1;
    	}
    	if(str2[i+x2]-'0'!=0){
    		flag2=1;
    	}
    	if(flag1>flag2){
    		return false;
    	}else if(flag2>flag1){
    		return true;
    	}

		if (str1[i+x1] < str2[i+x2] && flag1 && flag2) 
        	return true; 
    	else if (str1[i+x1] > str2[i+x2] &&flag2 &&flag1) 
        	return false; 
    	
    } 
    return true; 
} 

void diff(string str1,string str2){
	str1=modify(str1);
	str2=modify(str2);
	int carry =0;
	long int l1=str1.length();
	long int l2=str2.length();
	long int x=0;
	if(l1>l2 || (l1==l2 && isSmaller(str2,str1))){
		for(long int i=l1-1;i>=l1-l2;i--){
			if(str1[i]-carry>=str2[l2-x-1]){
				int temp=(str1[i]-'0')-(str2[l2-x-1]-'0')-carry;
				str1[i]='0'+temp;
				carry=0;
				x++;
			}else{
				int temp=(str1[i]-'0')-(str2[l2-x-1]-'0')-carry+10;
				str1[i]='0'+temp;
				carry=1;
				x++;
			}
		}
		for(long int i=l1-l2-1;i>=0;i--){
			if(str1[i]>=carry){
				int temp=(str1[i]-'0')-carry;
				str1[i]='0'+temp;
				carry=0;
				x++;
			}else{
				int temp=(str1[i]-'0')-carry+10;
				str1[i]='0'+temp;
				carry=1;
				x++;
			}
		}
		str1=modify(str1);
		if(str1.length()>0){
			cout<<str1<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}else if(l2>l1 || (l1==l2 && isSmaller(str1,str2))){
		for(long int i=l2-1;i>=l2-l1;i--){
			if(str2[i]-carry>=str1[l2-x-1]){
				int temp=(str2[i]-'0')-(str1[l1-x-1]-'0')-carry;
				str2[i]='0'+temp;
				carry=0;
				x++;
			}else{
				int temp=(str2[i]-'0')-(str1[l1-x-1]-'0')-carry+10;
				str2[i]='0'+temp;
				carry=1;
				x++;
			}
		}
		for(long int i=l2-l1-1;i>=0;i--){
			if(str2[i]>=carry){
				int temp=(str2[i]-'0')-carry;
				str2[i]='0'+temp;
				carry=0;
				x++;
			}else{
				int temp=(str2[i]-'0')-carry+10;
				str2[i]='0'+temp;
				carry=1;
				x++;
			}
		}
		str2=modify(str2);
		if(str2.length()>0){
			cout<<"-"<<str2<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str1,str2;
		cin>>str1>>str2;
		diff(str1,str2);
	}
	return 0;
}